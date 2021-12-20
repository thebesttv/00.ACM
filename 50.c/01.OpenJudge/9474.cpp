/*
描述
写出函数中缺失的部分，使得函数返回值为一个整数,该整数的第i位是n的第i位取反，其余位和n相同

请使用【一行代码】补全bitManipulation2函数使得程序能达到上述的功能

#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
// 在此处补充你的代码
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}

输入
第一行是整数 t，表示测试组数。
每组测试数据包含一行，是两个整数 n 和 i (0<=i<=31)。

输出
输出整型变量n中的第i位取反的结果
*/

#include <iostream>
using namespace std;

int bitManipulation2(int n, int i) {
// 在此处补充你的代码
	return n^(1<<i);	//切记return
}

int main() {
	int t, n, i;
	cin >> t;
	while (t--) {
		cin >> n >> i;
		cout << bitManipulation2(n, i) << endl;
	}
	return 0;
}
