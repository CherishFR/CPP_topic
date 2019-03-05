#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//const分配内存
extern const int m_B = 7;  // 1.添加extern也会让编译器为其分配内存地址
void test01() 
{
	const int m_A = 10;
	int * p = (int *)&m_A;  // 2.取地址时会分配临时内存地址
	int a = 11;
	const int m_C = a; // 3.用普通变量初始化const会分配内存地址
}
// 4.自定义数据类型，const也会分配内存地址
struct Person
{
	string m_Name;
	int m_Age;
};
void test02()
{
	const Person p1;
	Person *p = (Person*)&p1;
	p->m_Name = "刘";
	(*p).m_Age = 23;
	cout << "姓名：" << p1.m_Name << "年龄：" << p1.m_Age << endl;
}

int main()
{
    std::cout << "Hello World!\n"; 
}

