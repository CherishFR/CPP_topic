#include "pch.h"
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{
		cout << "默认构造函数调用" << endl;
	}
	Person(int i)
	{
		cout << "有参构造函数调用" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age + 10;
		cout << "拷贝构造函数调用" << endl;
	}
	int m_Age;
};

// 拷贝构造函数的使用时机
// 1.用已经创建好的对象来初始化新的对象
void test01()
{
	Person p1(1);
	p1.m_Age = 10;
	Person p2(p1);
	cout << "p2.m_Age=" << p2.m_Age << endl;
}

// 2.以值传递的方式给函数参数传值
void doWork(Person p1)
{

}

void test02()
{
	Person p1(1);
	p1.m_Age = 10;
	doWork(p1);
}

// 3.以值方式返回局部对象
Person doWork2()
{
	Person p1;
	return p1;
}

void test03()
{
	Person p = doWork2();
}
//Release下优化
/*
	Person p;
	doWork2(p);
	void doWork2(Person & p)
	{
		Person p1;
	}
*/



int main()
{
	test01();
}