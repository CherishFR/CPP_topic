#include "pch.h"
#include <iostream>
using namespace std;

#define MyAdd(x,y) ((x)+(y))

// 内联函数
// 当编译器处理调用内联函数的语句时，不会将该语句编译成函数调用的指令，而是直接将整个函数体的代码插人调用语句处，就像整个函数体在调用处被重写了一遍一样。
inline void func();
inline void func() {

}

void test01()
{
	int ret = MyAdd(10, 20) * 20;
	cout << "ret=" << ret << endl;
}

int main()
{
    
}

