#include "pch.h"
#include <iostream>
using namespace std;

void test01()
{
	// int &ref = 10;  // 引用不合法的内存
	const int &ref = 10;  // 编译器处理，int tmp = 10; const int &ref = tmp;因此该const可以被修改
	int *p = (int*)&ref;
	*p = 1000;
	cout << ref << endl;
}

void showValue(const int &val)
{
	// val += 1000;  // 如果只想显示内容而不修改内容则用const修饰
	cout << "val=" << val << endl;
} 

void test02()
{
	int a = 10;
	showValue(a);
}

int main()
{
	test01();
}

