#include "pch.h"
#include <iostream>
using namespace std;

class MyClass
{
public:
	// MyClass()
	// {
	// 	cout << "默认构造函数" << endl;
	// }
	MyClass(int a)
	{
		cout << "有参构造函数" << endl;
	}
};

// 当我们提供了有参构造函数，系统就不会提供默认构造函数，但会提供默认的拷贝构造
void test01()
{
	// MyClass c1;
	MyClass c1(1);
	MyClass c2(c1);
}

int main()
{
	test01();
}

