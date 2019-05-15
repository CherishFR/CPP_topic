#pragma once
#include<iostream>
#include"wall.h"
#include"food.h"
using namespace std;

class Snake
{
public:
	Snake(Wall & tempWall, Food & tempFood);
	
	enum { UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd' };

	// 初始化
	void initSnake();

	// 销毁节点
	void destoryPoint();

	// 添加节点
	void addPoint(int x, int y);

	// 删除节点
	void delPoint();

	// 移动蛇操作
	bool move(char key);
private:
	// 节点
	struct Point
	{
		// 数据域
		int x;
		int y;

		//指针域
		Point * next;
	};

	//头节点
	Point * pHead;

	Wall & wall;
	Food & food;
	bool isRool; //判断循环
};
