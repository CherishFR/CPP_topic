// C++下的封装.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

// C++封装，严格类型转化检测，将属性和行为封装到一起
/*	1.属性和行为作为一个整体表示生活中的事物
	2.控制权限： public-公有权限  protected-保护权限 private-私有权限
		public：在类的内部和类的外部都可以访问
		protected：只有类的内部以及子类中才能访问
		private：只能在类的内部访问
*/ 
struct Person
{
	char Name[20];
	int Age;
	void PersonEat()
	{
		cout << Name << "吃人饭" << endl;
	}
};

struct Dog
{
	char Name[20];
	int Age;
	void DogEat()
	{
		cout << Name << "吃狗粮" << endl;
	}
};

void test01()
{
	Person p1;
	strcpy(p1.Name, "老王");
	p1.PersonEat;

}

// struct和class是一个意思，唯一的不同时struct默认权限为public，class默认权限为private
class Animal
{
	// 如果不声明权限，默认为private
	int age;
public:
	int name;
protected:
	int weight;
};

void test02()
{
	Animal an;
	// an.age;  // 私有权限不能被外部访问
	// an.weight;  // 保护权限不能被外部访问
	an.name;

}

int main()
{
	test01();
}

