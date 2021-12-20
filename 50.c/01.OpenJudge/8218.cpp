/*
描述
给定一个整数，判断该数是奇数还是偶数。

输入
输入仅一行，一个大于零的正整数n。

输出
输出仅一行，如果n是奇数，输出odd；如果n是偶数，输出even。
*/

#include<iostream>
#include<cstdio>

int main(){
	int n;

	scanf("%d",&n);
	if(n%2)	printf("odd\n");
	else	printf("even\n");

	return 0;
}
