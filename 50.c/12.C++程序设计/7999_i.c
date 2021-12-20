/*
描述

下面程序的输出结果是：
5,5
5,5

请填空：

#include <iostream>
using namespace std;

class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big  {
public:
	int v; Base b;

	// 在此处补充你的代码

};

int main()  {
	Big a1(5);    Big a2 = a1;
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	return 0;
}

输入
无

输出
5,5
5,5

提示
所缺代码具有如下形式：
Big ________________{ }
Big ________________{ }


*/

#include <iostream>
using namespace std;

class Base {
public:
	int k;
	Base(int n):k(n) { }
};
class Big  {
public:
	int v; Base b;
	Big(int v_): v(v_), b(v_) {}
	Big(Big & a_): v(a_.v), b(a_.v) {}
};

int main()  {
	Big a1(5);    Big a2 = a1;
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	return 0;
}
