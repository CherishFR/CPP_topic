#include <iostream>
using namespace std;

namespace LOL {
	int ali = 10;
}

void test01() {
	int ali = 20;
	//using 声明，using声明往后的代码遇到ali都用LOL命名空间的，但编译器又有就近原则（二义性）
	// 注意避免二义性
//    using LOL::ali;
	cout << ali << endl;
}


void test02() {
	int ali = 20;
	// using编译指令，优先级低于就近原则
	using namespace LOL;
	cout << ali << endl;
}

namespace DOTA {
	int ali = 30;
}

void test03() {
	// 同样存在二义性
	using namespace LOL;
	using namespace DOTA;
	cout << DOTA::ali << endl;
}

int main() {
	test03();
	return 0;
}