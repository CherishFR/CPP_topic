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
	// �����½ڵ�
	Point * newPoint = new Point;
	newPoint->x = x;
	newPoint->y = y;
	newPoint->next = NULL;

	// ���ͷ�ڵ㲻Ϊ�����Ϊ����
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
	// �����ڵ����ϲ�ɾ��
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

	// ɾ��β�ڵ�
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

	// ����´��ƶ��ص���β����Ӧ������
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
		// �ж��û�����λ���Ƿ�ɹ�
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

	

	// �ƶ��ɹ�
	// �Ե�ʳ��
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
