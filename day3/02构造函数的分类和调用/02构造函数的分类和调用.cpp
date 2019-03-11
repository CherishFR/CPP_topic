#include "pch.h"
#include <iostream>
using namespace std;

// 分类 
// 按照参数进行分类 无参构造函数（默认构造函数） 有参构造函数
// 按照类型进行分类 普通构造函数 拷贝构造函数

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
	// 拷贝构造函数
	Person(const Person& p)  // const 防止p1被修改
	{	
		// p.m_Age = p.m_Age+10;
		m_Age = p.m_Age + 10;
		cout << "拷贝构造函数调用" << endl;
	}
	int m_Age;
};

void test01()
{
	// 构造函数调用
	// 括号法调用
	Person p1(1);
	p1.m_Age = 10;
	Person p2(p1);
	cout << "p2.m_Age="<< p2.m_Age << endl;
	Person p3;  // 不能加括号，否则编译器会认为是函数的声明

	// 显示法调用
	Person p4 = Person(100);
	Person p5 = Person(p4);
	Person(200);  // 匿名对象，在该行代码结束后就释放

	// 不能用拷贝构造函数初始化匿名对象
	// Person(p5);  //编译器会认为是Person p5，对象的申明
}

int main()
{
	test01();
}

