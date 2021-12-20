/*
题目描述

因为151既是一个质数又是一个回文数(从左到右和从右到左是看一样的)，所以 151 是回文质数。

写一个程序来找出范围[a,b](5 <= a < b <= 100,000,000)( 一亿)间的所有回文质数;

输入输出格式

输入格式：
第 1 行: 二个整数 a 和 b .

输出格式：
输出一个回文质数的列表，一行一个。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100000000

bool check[MAX];
//bool book[MAX/2];
char a[10],b[10];
int ta=0, tb=0;

void Create(int l, int dest, int n, int step);

int main(void){
	scanf("%s%s",a,b);
	for(register long i=3;i<=10000;i+=2)	//部分判定，最终判断时，要考虑模2是否为0
		if(!check[i])
			for(register long j=i*i;j<=MAX;j+=i*2) check[j]=1;
	int la=strlen(a),lb=strlen(b);
	for(int i=0;i<la;i++) ta=ta*10+a[i]-'0';
	for(int i=0;i<lb;i++) tb=tb*10+b[i]-'0';
	for(int i=la;i<=lb;i++){
		for(int j=0;j<10;j++) Create(1,i,j,0);
	}

	return 0;
}

void Create(int l, int dest, int n, int step){
//for(int i=0;i<step;i++) printf("  ");
//printf("  l: %d, dest: %d, n: %d\n",l,dest,n);
	if(l==(dest+1)/2){
//printf("***%d\n",n);
		int t=n;
		if(dest>1){
			if(dest&1) n/=10;
			while(n>0){
				t=t*10+n%10;
				n/=10;
			}
		}
//printf("*****%d\n",t);
		if(t>=ta && t<=tb && t&1 && !check[t]){
//			for(int i=0;i<step;i++) printf("  ");
			printf("%d\n",t);
		}
		return;
	}
	for(int i=0;i<=9;i++){
		if(n){	//??
			Create(l+1,dest,n*10+i,step+1);
		}
	}
}
