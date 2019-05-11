#include "food.h"


Food::Food(Wall & tempWall) : wall(tempWall)
{
}

void Food::setFood()
{
	while (true)
	{
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		// 如果生产到了蛇头或者蛇身的位置就重新生成
		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			break;
		}
	}
}


