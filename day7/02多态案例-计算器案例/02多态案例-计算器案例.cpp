#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

//class Calculator
//{
//public:
//	void setv1(int v)
//	{
//		this->val1 = v;
//	}
//	void setv2(int v)
//	{
//		this->val2 = v;
//	}
//		
//	int getResult(string oper)
//	{
//		if (oper == "+")
//		{
//			return val1 + val2;
//		}
//		else if (oper == "-")
//		{
//			return val1 - val2;
//		}
//	}
//
//private:
//	int val1;
//	int val2;
//};
//
//void test01()
//{
//	Calculator cal;
//	cal.setv1(10);
//	cal.setv2(10);
//	cout << cal.getResult("+") << endl;
//	cout << cal.getResult("-") << endl;
//}

// 利用多态实现计算器
class abstractCalculator
{
public:
	// 虚函数
	/*virtual int getResult()
	{
		return 0;
	}*/
	// 纯虚函数
	// 如果父类中有纯虚函数，子类继承父类必须实现纯虚函数
	// 如果父类中有纯虚函数，这个父类无法实例化对象了
	// 这个类有了纯虚函数，通常被称为抽象类
	virtual int getResult() = 0;

	void setv1(int v)
	{
		this->val1 = v;
	}
	void setv2(int v)
	{
		this->val2 = v;
	}

	int val1;
	int val2;
};

class plusCalculator :public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 + val2;
	}
};

class subCalculator :public abstractCalculator
{
public:
	virtual int getResult()
	{
		return val1 - val2;
	}
};

void test02()
{
	abstractCalculator *abc;
	abc = new plusCalculator;
	abc->setv1(20);
	abc->setv2(10);
	cout << abc->getResult() << endl;
	delete abc;
	
	abc = new subCalculator;
	abc->setv1(20);
	abc->setv2(10);
	cout << abc->getResult() << endl;
}

int main()
{
	test02;
	system("pause");
}
