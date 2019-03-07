// 04函数重载的基本语法.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

// 函数重载
// c++中函数名称可以重复（必须在同一个作用域）
void func()
{
	cout << "无参数的func()" << endl;
}

void func(int a)
{
	cout << "有参数的func(int a)" << endl;
}

void func(double a)
{
	cout << "有参数的func(double a)" << endl;
}

void func(double a, int b)
{
	cout << "有参数的func(double a, int b)" << endl;
}

void test01()
{
	func();
	func(10);
	func(1.1);
	func(1.1,20);
}

// 函数重载，碰到默认参数应该避免二义性问题
void func2(int a, int b=10)
{
	cout << "有参数的func2(int a, int b=10)" << endl;
}

void func2(int a)
{
	cout << "有参数的func2(int a)" << endl;
}

void test02()
{
	// func2(10);
}

// 引用的重载
void func3(int &a)  // 应用必须时合法的内存空间
{
	cout << "func3(int &a)" << endl;
}

void func3(const int &a)  // const也可以作为重载的条件。 int tmp = 10; const int &a = tmp;
{
	cout << "func3(const int &a)" << endl;
}

void test03()
{
	int a = 10;
	func3(a);
	func3(10);
}


int main()
{
	test03();
}

