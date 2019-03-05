#include "pch.h"
#include <iostream>
using namespace std;

// 1. 引用的基本语法，int &别名 = 原名;
void test01() 
{
	int a = 10;
	int &b = a;
	b = 20;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}

// 2.引用必须初始化
void test02()
{
	// int &a;  // 必须初始化
	int a = 10;
	int &b = a;  // 初始化后就不能修改
}

// 3.对数组建立引用
void test03()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}
	// 给数组起别名
	int(&parr)[10] = arr;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}

	// 第二种方式起别名
	typedef int(ARRAYREF)[10];
	ARRAYREF &parr2 = arr;
}

int main()
{
	test01();
}

