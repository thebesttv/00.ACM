/*
描述
分别定义float，double类型的变量各一个，并依次输出它们的存储空间大小（单位：字节）。

输入
无。

输出
一行，两个整数，分别是两个变量的存储空间大小，用一个空格隔开。
*/

#include<iostream>
#include<cstdio>

int main(){
	float a;
	double b;

	printf("%ld %ld\n",sizeof(a),sizeof(b));

	return 0;
}
