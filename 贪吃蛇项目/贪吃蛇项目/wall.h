#ifndef _WALL_HEAD
#define _WALL_HEAD
#include<iostream>
using namespace std;

class Wall
{
public:
	enum {
		ROW = 26,
		COL = 26
	};

	// 初始化
	void initWall();

	// 画出墙壁
	void drawWall();

	// 根据索引修改二维数组的内容
	void setWall(int x, int y, char c);

	// 根据索引获取二维数组的内容
	char getWall(int x, int y);
private:
	char gameArray[ROW][COL];
};


#endif
