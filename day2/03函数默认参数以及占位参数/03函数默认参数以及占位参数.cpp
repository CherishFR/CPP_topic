#include "pch.h"
#include <iostream>
using namespace std;

// 函数的默认参数，如果一个位置有了默认参数，那么从这位置开始之后的参数都必须有默认参数
void Add(int a, int b, int c=10) 
{
	cout << a + b + c << endl;
}

//占位参数，函数调用时必须提供这个参数，但不会用到这个参数
void test01(int a, int)
{

}

// 函数申明和函数实现里不能同时存在默认参数
void test02(int a = 10, int b = 20);
void test02(int a, int b)
{

}

int main()
{
	Add(5, 6);
}

