#include <iostream>
using namespace std;

// 1.全局变量检测增强
int a;
int a = 10;  // 不允许全局变量重定义(多次定义)

// 2.函数检测增强：参数类型检测增强，返回值检测增强，函数调用的参数检测增强
int getRectS(w, h) {

}
void test01() {
	getRectS(10, 10, 10)
}

// 3.类型转换检测增强
void test02() {
	//    char *p = malloc(sizeof(64)); //malloc返回值为void *
	char *p = (char*)malloc(sizeof(64));
}

// 4.struct增强
struct Person {
	int m_Age;
	void plusAge() {
		m_Age++;
	};  // C++中可以添加函数
};
void test03() {
	Person p1; // C++中可以不写struct关键字
	p1.m_Age = 10;
	p1.plusAge();
	cout << p1.m_Age << endl;
}

// 5.bool增强，C中没有bool
bool flag;  // 只有真或假，true为真(1)，false为假(0)，赋的所有非0值都会转化成1；

// 6.三目运算符增强
void  test04() {
	int a = 10;
	int b = 20;
	cout << "ret=" << (a > b ? a : b) << endl;
	a > b ? a : b = 100;  // C++返回的是变量，而C返回变量对应的值
	cout << "b=" << b << endl;
}

// 7.const增强，C++默认const为内部链接，只能文件内调用
void test05() {
	const int m_A = 10;  // C++中const不会分配内存地址
	int *p = (int *)&m_A;
	*p = 200;
	cout << "*p=" << *p << endl;
	cout << "m_A=" << m_A << endl;  // 常量m_A无法进行修改
}

int main() {
	test05();
	return 0;
}