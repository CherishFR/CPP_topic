#pragma once
#include<iostream>
using namespace std;
#include"wall.h"

class Food
{
public:
	Food(Wall & tempWall);
	//…Ë÷√ ≥ŒÔ
	void setFood();
	
	int foodX;
	int foodY;

private:
	Wall &wall;
};
