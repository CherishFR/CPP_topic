#include <iostream>  // 标准输入输出头文件
using namespace std;  // 使用命名空间std，理解为打开一个叫做std的房间
#include "game1.h"
#include "game2.h"

int atk = 200;
void test01() {
	int atk = 100;
	cout << "攻击力为：" << atk << endl;
	// 作用域运算符 ::；::全局作用域
	cout << "全局攻击力为：" << ::atk << endl;
}

//namespace命名空间主要用途：用来解决命名冲突的问题
// 1.命名空间可以放函数，变量，结构体，类
// 2.命名空间必须定义在全局作用域下
// 3.命名空间可以嵌套命名空间
namespace A {
	void func();
	int m_A = 20;
	struct Person {

	};
	class Animal {

	};
	namespace B {
		int m_A = 10;
	}
}

void test02() {
	cout << "作用域B下的m_A为：" << A::B::m_A << endl;
}

// 4.命名空间是开放的，可以随时往原来的命名空间中添加内容
namespace A {  // 此命名空间会和上面的命名空间合并
	int m_B;
}

// 5.匿名命名空间
namespace {
	int m_C = 0;
}  // 匿名命名空间相当于 static int m_C，只能在当前文件内使用

// 6.命名空间可以起别名
namespace veryLongName {
	int m_A = 0;
}
void test03() {
	namespace VLN = veryLongName;
	cout << veryLongName::m_A << endl;
	cout << VLN::m_A << endl;
}

int main() {
	// cout标准输出
	// << 左移运算符
	// endl 结束换行
	cout << "Hello, World!" << endl;
	test01();
	LOL::goAtk();
	return 0;
}