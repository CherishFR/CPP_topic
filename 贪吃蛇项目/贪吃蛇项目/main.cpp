#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctime>
#include<conio.h>
#include<windows.h>
using namespace std;

#include"wall.h"
#include"snake.h"
#include"food.h"


int main() {
	// ����������
	srand((unsigned int)time(NULL));

	// �Ƿ�����
	bool isDead = false;
	char preKey = NULL;

	Wall wall;
	wall.initWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	wall.drawWall();

	// �����û�����
	while (!isDead)
	{
		char key = _getch();

		// ����ǵ�һ�ΰ�������Ͳ��ܼ�����Ϸ
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}

		do 
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// �жϳ�ͻ����
				if ((key == snake.LEFT && preKey == snake.RIGHT) ||
					(key == snake.RIGHT && preKey == snake.LEFT) ||
					(key == snake.UP && preKey == snake.DOWN) ||
					(key == snake.DOWN && preKey == snake.UP))
				{
					key = preKey;
				}
				else {
					preKey = key;
				}
				
				if (snake.move(key) == true)
				{
					system("cls");
					wall.drawWall();
					Sleep(300);
				}
				else
				{
					isDead = true;
					break;
				}
			}
			else
			{
				key = preKey;
			}
		} while (!_kbhit()); // ��û�м�������ʱ����0

		
	}
	
	system("pause");
}