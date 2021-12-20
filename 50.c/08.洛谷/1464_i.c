/*
题目描述

对于一个递归函数w(a,b,c)
如果a<=0 or b<=0 or c<=0就返回值1.
如果a>20 or b>20 or c>20就返回w(20,20,20)
如果a<b并且b<c 就返回w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c)
其它别的情况就返回w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1)
这是个简单的递归函数，但实现起来可能会有些问题。当a,b,c均为15时，调用的次数将非常的多。你要想个办法才行.


absi2011 : 比如 w(30,-1,0)既满足条件1又满足条件2
这种时候我们就按最上面的条件来算
所以答案为1


输入输出格式

输入格式：
会有若干行.
并以-1，-1，-1结束.
保证输入的数在-9223372036854775808~9223372036854775807之间
并且是整数

输出格式：
输出若干行
格式:
w(a,_b,_c)=_你的输出	(_代表空格)
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long check[22][22][22];

long long calc(long long a, long long b, long long c){
	if(check[a][b][c]!=-1) return check[a][b][c];
	else{
		if(a<=0 || b<=0 || c<=0) check[a][b][c]=1;
		else if(a>20 || b>20 || c>20) check[a][b][c]=calc(20,20,20);
		else if(a<b && b<c) check[a][b][c]=calc(a,b,c-1)+calc(a,b-1,c-1)-calc(a,b-1,c);
		else check[a][b][c]=calc(a-1,b,c)+calc(a-1,b-1,c)+calc(a-1,b,c-1)-calc(a-1,b-1,c-1);
	}
	return check[a][b][c];
}

long long w(long long a, long long b, long long c){
	if(0<=a && a<=20 && 0<=b && b<=20 && 0<=c && c<=20){
		if(check[a][b][c]!=-1) return check[a][b][c];
	}else{
		if(a<=0 || b<=0 || c<=0) return 1;
		else if(a>20 || b>20 || c>20) return w(20,20,20);
		else if(a<b && b<c) return w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
		else return w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
	}
}

int main(void){
	memset(check,-1,sizeof(check));
	long long a,b,c;
	for(int a=0;a<=20;a++) for(int b=0;b<=20;b++) for(int c=0;c<=20;c++)
		calc(a,b,c);
	while(scanf("%lld%lld%lld",&a,&b,&c) && !(a==-1 && b==-1 && c==-1)){
		printf("w(%lld, %lld, %lld) = %lld\n",a,b,c,w(a,b,c));
	}

	return 0;
}
