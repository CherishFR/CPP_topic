#include "snake.h"

Snake::Snake(Wall & tempWall, Food & tempFood) : wall(tempWall), food(tempFood)
{
	pHead = NULL;
	isRool = false;
}


void Snake::initSnake()
{
	destoryPoint();

	addPoint(5, 3);
	addPoint(5, 4);
	addPoint(5, 5);
}

void Snake::destoryPoint()
{
	Point * pCur = pHead;
	while (pHead != NULL)
	{
		pCur = pHead->next;
		delete pHead;
		pHead = pCur;
	}
	/*while (pHead != NULL)
	{
		pHead = pHead->next;
	}*/
}

void Snake::addPoint(int x, int y)
{
	// 创建新节点
	Point * newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	// 如果头节点不为空则变为身子
	if (pHead != NULL)
	{
		wall.setWall(pHead->x, pHead->y, '+');
	}
	newPoint->next = pHead;
	pHead = newPoint;
	wall.setWall(pHead->x, pHead->y, '@');
}

void Snake::delPoint()
{	
	// 两个节点以上才删除
	if (pHead == NULL || pHead->next == NULL) 
	{
		return;
	}

	Point * pCur = pHead->next;
	Point * pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}

	// 删除尾节点
	wall.setWall(pCur->x, pCur->y, ' ');
	delete pCur;
	pCur = NULL;
	pPre->next = NULL;
}

bool Snake::move(char key)
{
	int x = pHead->x;
	int y = pHead->y;
	switch (key)
	{
	case UP:
		x--;
		break;
	case DOWN:
		x++;
		break;
	case LEFT:
		y--;
		break;
	case RIGHT:
		y++;
		break;
	default:
		break;
	}

	// 如果下次移动地点是尾巴则不应该死亡
	Point * pCur = pHead->next;
	Point * pPre = pHead;

	while (pCur->next != NULL)
	{
		pPre = pPre->next;
		pCur = pCur->next;
	}
	if (pCur->x == x && pCur->y == y)
	{
		isRool = true;
	}
	else {
		// 判断用户到达位置是否成功
		if (wall.getWall(x, y) == '*' || wall.getWall(x, y) == '+')
		{	
			addPoint(x, y);
			delPoint();
			system("cls");
			wall.drawWall();
			cout << "game over" << endl;
			return false;
		}
	}

	

	// 移动成功
	// 吃到食物
	if (wall.getWall(x, y) == '#')
	{
		addPoint(x, y);
		food.setFood();
	}
	else
	{
		addPoint(x, y);
		delPoint();
		if (isRool)
		{
			wall.setWall(x, y, '@');
		}
	}
	return true;
}
