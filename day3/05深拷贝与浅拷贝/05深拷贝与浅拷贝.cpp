#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person()
	{

	}
	Person(char *name,int age)
	{
		m_Name = (char*)malloc(strlen(name) + 1);
		strcpy(m_Name, name);
		m_age = age;
	}
	//自己提供拷贝构造，原因是简单的浅拷贝会释放堆区空间两次，导致崩溃
	Person(const Person &p)
	{
		m_age = p.m_age;
		m_Name = (char*)malloc(strlen(p.m_Name) + 1);
		strcpy(m_Name, p.m_Name);
	}

	~Person()
	{
		cout << "析构函数调用" << endl;
		if (m_Name != NULL)
		{
			free(m_Name);
			m_Name = NULL;
		}
	}

	char * m_Name;
	int m_age;
};

void test01()
{
	Person p1("剑圣",24);
	Person p2(p1);
}

int main()
{
    std::cout << "Hello World!\n"; 
}

