#include "snake.h"

Snake::Snake(Wall & tempWall) : wall(tempWall)
{
	pHead = NULL;
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
