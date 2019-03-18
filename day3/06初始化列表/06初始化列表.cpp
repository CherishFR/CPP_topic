#include "pch.h"
#include <iostream>
using namespace std;

class Person
{
public:
	Person()
	{

	}
	/*
	Person(int A, int B, int C)
	{
		m_A = A;
		m_B = B;
		m_C = C;
	}
	*/

	// 利用初始化列表来初始化数据
	Person(int A, int B, int C):m_A(A), m_B(B), m_C(C)
	{}

	int m_A;
	int m_B;
	int m_C;
};

void test01()
{
	Person p1(10, 24, 64);
}

int main()
{
    std::cout << "Hello World!\n"; 
}

