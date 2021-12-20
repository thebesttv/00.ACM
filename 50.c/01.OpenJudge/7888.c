/*
描述
若将一个正整数化为二进制数，在此二进制数中，我们将数字1的个数多于数字0的个数的这类二进制数称为A类数，否则就称其为B类数。
例如：
(13)10 = (1101)2，其中1的个数为3，0的个数为1，则称此数为A类数；
(10)10 = (1010)2，其中1的个数为2，0的个数也为2，称此数为B类数；
(24)10 = (11000)2，其中1的个数为2，0的个数为3，则称此数为B类数；
程序要求：求出1~1000之中（包括1与1000），全部A、B两类数的个数。

输入
无。

输出
一行，包含两个整数，分别是A类数和B类数的个数，中间用单个空格隔开。
*/

#include<iostream>
#include<cstdio>
using namespace std;

int Get(int n);

int main(void){
	int A=0,B=0;
	for(int i=1;i<=1000;i++)
		if(Get(i)) A++;
		else B++;
	printf("%d %d\n",A,B);

	return 0;
}

int Get(int n){
	int tot=0,cou=0;
	while(n>0){
		if(n%2==1) cou++;
		n/=2; tot++;
	}
	return cou>tot-cou;
}
