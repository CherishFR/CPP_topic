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

	// ��ʼ��
	void initSnake();

	// ���ٽڵ�
	void destoryPoint();

	// ��ӽڵ�
	void addPoint(int x, int y);

	// ɾ���ڵ�
	void delPoint();

	// �ƶ��߲���
	bool move(char key);
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
	Food & food;
	bool isRool; //�ж�ѭ��
};
