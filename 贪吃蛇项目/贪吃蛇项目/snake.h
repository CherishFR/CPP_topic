#pragma once
#include<iostream>
#include"wall.h"
using namespace std;

class Snake
{
public:
	Snake(Wall & tempWall);

	// 初始化
	void initSnake();

	// 销毁节点
	void destoryPoint();

	// 添加节点
	void addPoint(int x, int y);
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
};
