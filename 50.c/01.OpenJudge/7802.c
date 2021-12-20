/*
描述
给定一个十进制非负整数N，求其对应2进制数中1的个数。

输入
输入包含一行，包含一个非负整数N。(N < 10^9)

输出
输出一行，包含一个整数，表示N的2进制表示中1的个数。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int main(void){
	long n,sum=0;
	scanf("%ld",&n);
	while(n!=0){
		if(n%2) sum++;
		n/=2;
	}
	printf("%ld\n",sum);

	return 0;
}
