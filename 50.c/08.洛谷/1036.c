/*
题目描述
已知 n 个整数 x1,x2,...,xn，以及一个整数 k(k<n)。从 n 个整数中任选 k 个整数相加，可分别得到一系列的和。例如当 n=4，k=3，4 个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为：
  3+7+12=22
  3+7+19=29
  7+12+19=38
  3+12+19=34。
现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3+7+19=29。

输入输出格式
输入格式：
n, k (1<=n<=20，k<n)
x1,x2,...,xn (1<=xi<=5000000)

输出格式：
一个整数，满足条件的种数。
*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 20000000

bool check[MAX];
int n,k,cou=0;
long a[20+4];

void Solve(long a[], int pos, int step, long sum);

int main(void){
	for(register long long i=2;i<MAX;i++)	if(!check[i])
			for(register long long j=i*2;j<MAX;j+=i) check[j]=1;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) scanf("%ld",&a[i]);
	for(int i=0;i<n;i++) Solve(a,i,0,0);
	printf("%d\n",cou);

	return 0;
}

void Solve(long a[], int pos, int step, long sum){
	if(pos>=n) return;
	sum+=a[pos];
	if(step==k-1){
		if(!check[sum]) cou++;
		return;
	}
	for(int i=pos+1;i<n;i++){
		Solve(a,i,step+1,sum);
	}
}
