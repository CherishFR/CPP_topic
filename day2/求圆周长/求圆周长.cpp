#include "pch.h"
#include <iostream>
using namespace std;

const double pi = 3.14;

// 设计一个类，求圆周长
class Circle
{
public:  // 公共权限
	// 在类里写函数，成员函数
	double calculate()
	{
		return 2 * pi * m_R;
	}
	void setR(int r)
	{
		m_R = r;  // 修改成员属性
	}

	int m_R;

};

void test01()
{
	Circle c;  // 创建对象
	c.setR(10);  //调用方法
	cout << "圆的周长为：" << c.calculate() << endl;
}


int main()
{
	test01();
}
