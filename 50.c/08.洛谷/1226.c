/*
题目描述
输入b，p，k的值，求b^p mod k的值。其中b，p，k*k为长整型数。

输入输出格式

输入格式：
三个整数b,p,k.

输出格式：
输出“b^p mod k=s”
s为运算结果
*/

#include<iostream>
#include<cstdio>
using namespace std;

long long b,p,k;

long long PowerMod(long long b, long long p, long long k){
	if(p==0) return 1%k;
	long long t=PowerMod(b,p/2,k);
	t=(t*(t%k))%k;
	if(p&1) t=(t*(b%k))%k;
	return t;
}

int main(void){
	scanf("%lld%lld%lld",&b,&p,&k);
	printf("%lld^%lld mod %lld=%lld\n",b,p,k,PowerMod(b,p,k));

	return 0;
}
