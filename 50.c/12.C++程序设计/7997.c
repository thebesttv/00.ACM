/*
描述
下面程序输出的结果是：
0
5
请填空：

#include <iostream>
using namespace std;
class A {
public:
    int val;

// 在此处补充你的代码

};
main()  {
    A a;
    cout << a.val << endl;
    a.GetObj() = 5;
    cout << a.val << endl;
}

输入
无

输出
0
5

提示
所缺代码具有如下形式：

A(_________________ ){ val = n; }
________________ GetObj() {
    return _________________;
}
*/

#include <iostream>
using namespace std;

class A {
public:
	int val;
	A(){
		val = 0;
	}
	int & GetObj(){
		return this->val;
	}
};

main()  {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
}
