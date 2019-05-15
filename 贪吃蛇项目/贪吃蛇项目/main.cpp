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
	// 添加随机种子
	srand((unsigned int)time(NULL));

	// 是否死亡
	bool isDead = false;
	char preKey = NULL;

	Wall wall;
	wall.initWall();

	Food food(wall);
	food.setFood();

	Snake snake(wall, food);
	snake.initSnake();

	wall.drawWall();

	// 接收用户输入
	while (!isDead)
	{
		char key = _getch();

		// 如果是第一次按了左键就不能激活游戏
		if (preKey == NULL && key == snake.LEFT) {
			continue;
		}

		do 
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				// 判断冲突按键
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
		} while (!_kbhit()); // 当没有键盘输入时返回0

		
	}
	
	system("pause");
}