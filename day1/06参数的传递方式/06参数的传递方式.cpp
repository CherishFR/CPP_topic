#include "pch.h"
#include <iostream>
using namespace std;

// 值传递
void mySwap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

// 地址传递
void mySwap2(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 引用传递
void mySwap3(int &a, int &b)  // int &a = a;
{
	int tmp = a;
	a = b;
	b = tmp;
}

void test01()
{
	int a = 10;
	int b = 20;
	mySwap(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	mySwap2(&a, &b);  
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	mySwap3(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
}

// 引用的注意事项
// 1.引用必须引用合法的内存空间
void test02()
{
	// int &a = 10;
}

// 2.不要返回局部变量的引用
int dowork()
{
	int a = 10;
	return a;
}
void test03()
{
	int &ret = dowork();  // 局部变量的声明周期已过
	cout << ret << endl;  // 返回10是因为编译器做的优化
	cout << ret << endl;
	cout << ret << endl;
}

int& dowork2()
{
	static int a = 10;
	return a;
}
void test04()
{
	int &ret = dowork2(); 
	// 如果函数的返回值是引用，那么这个函数的调用可以作为左值
	dowork2() = 1100;  // 相当于a = 1100
}


int main()
{
	test01();
}
