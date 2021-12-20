/*
题目描述

给定一个整数，请将该数各个位上数字反转得到一个新数。新数也应满足整数的常见形式，即除非给定的原数为零，否则反转后得到的新数的最高位数字不应为零（参见样例2）。

输入输出格式

输入格式：
输入文件名为reverse.in 。

输入共1 行，一个整数 N。

输出格式：
输出文件名为reverse.out 。

输出共1行，一个整数，表示反转后的新数。
*/

#include<stdio.h>
#include<stdlib.h>

int main(void){
	int n,t=0;

	scanf("%d",&n);
	if(n<0){
		n=-n;
		printf("-");
	}
	while(n>0){
		t=t*10+n%10;
		n/=10;
	}
	printf("%d\n",t);

	return 0;
}
