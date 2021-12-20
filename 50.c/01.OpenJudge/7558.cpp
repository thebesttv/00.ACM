/*
描述
输入一个除空格以外的可见字符（保证在函数scanf中可使用格式说明符%c读入），输出其ASCII码。

输入
一个除空格以外的可见字符。

输出
一个十进制整数，即该字符的ASCII码。
*/

#include<iostream>
#include<cstdio>

int main(){
	char c;
	scanf("%c",&c);
	printf("%d\n",c);

	return 0;
}
