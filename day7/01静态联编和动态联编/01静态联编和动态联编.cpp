#include "pch.h"
#include <iostream>
using namespace std;

class Animal
{
public:
	virtual void speak() {
		cout << "动物在说话" << endl;
	}
	virtual void eat() {
		cout << "动物在吃饭" << endl;
	}
};

class Cat :public Animal
{
public:
	void speak() {
		cout << "小猫在说话" << endl;
	}
	void eat() {
		cout << "小猫在鱼" << endl;
	}
};

// 调用doSpeak，speak函数的地址早就绑定好了，早绑定，静态联编，编译阶段确定好了地址
// 如果想调用猫的speak就不能提前绑定好函数的地址，所以需要在运行时再去确定函数地址
// 动态联编，将doSpeak改为虚函数，在父类上声明虚函数，发生了多态
// 父类的引用或者指针指向子类对象
void doSpeak(Animal &animal)
{
	animal.speak();
};


// 如果发生了继承的关系，编译器允许进行类型的转化
void test01()
{
	Cat cat1;
	doSpeak(cat1);
};

void test02() 
{
	// 父类指针指向子类对象 多态
	Animal * animal = new Cat;
	// animal->speak();
	// *(int *)*(int *)animal 函数地址
	((void(*)()) (*(int *)*(int *)animal))();
	// 猫吃鱼的函数地址，*((int *)*(int *)animal+1)
	((void(*)()) (*((int *)*(int *)animal+1)))();
}

int main()
{
	test01();
}

