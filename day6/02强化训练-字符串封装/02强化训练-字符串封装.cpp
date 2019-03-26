#include "pch.h"
#include "MyString.h"
#include <iostream>
using namespace std;

void test01()
{
	MyString str = "abc";
	cout << str << endl;
	cin >> str;
	cout << "新内容：" << str << endl;
	str = "aaa";
	cout << "str=：" << str << endl;
}

int main()
{
	test01();
}
