#pragma once
#include<iostream>
#include"wall.h"
using namespace std;

class Snake
{
public:
	Snake(Wall & tempWall);

	// ��ʼ��
	void initSnake();

	// ���ٽڵ�
	void destoryPoint();

	// ��ӽڵ�
	void addPoint(int x, int y);
private:
	// �ڵ�
	struct Point
	{
		// ������
		int x;
		int y;

		//ָ����
		Point * next;
	};

	//ͷ�ڵ�
	Point * pHead;

	Wall & wall;
};
