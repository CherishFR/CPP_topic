#include "pch.h"
#include <iostream>
#include"test.h"
using namespace std;

//C++调用C的方法
// extern "C" void show();

int main()
{
	show();  // C++中函数会发生重载的，编译器会把函数名称偷偷改变
}


