#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
using namespace std;

#include"wall.h"
#include"snake.h"
#include"food.h"


int main() {
	// 添加随机种子
	srand((unsigned int)time(NULL));

	Wall wall;
	wall.initWall();

	Snake snake(wall);
	snake.initSnake();

	Food food(wall);
	food.setFood();

	wall.drawWall();
	system("pause");
}