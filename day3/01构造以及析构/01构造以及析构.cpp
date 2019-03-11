#include "pch.h"
#include <iostream>
using namespace std;

class Person
{
public:  // 必须写在public下
	// 构造函数写法
	// 与类名相同，没有返回值，不写void，可以发生重载（可以有参数）
	Person()
	{
		cout << "构造函数" << endl;
	}

	// 析构函数
	// 与类名相同，类名前面加“~”，没有返回值，不写void，不可以发生重载（不可以有参数）
	~Person()
	{
		cout << "析构函数" << endl;
	}
};

void test01()
{
	Person p1;  // 默认调用了构造和析构
}


int main()
{
	test01();
}

