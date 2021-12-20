/*
描述
Pell数列a1, a2, a3, ...的定义是这样的，a1 = 1, a2 = 2, ... , a_n = 2 * a_(n − 1) + a_(n - 2) (n > 2)。
给出一个正整数k，要求Pell数列的第k项模上32767是多少。

输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数k (1 ≤ k < 1000000)。

输出
n行，每行输出对应一个输入。输出应是一个非负整数。
*/

#include<iostream>
#include<cstdio>

#define MAX 1000000
#define DEBUG 0

unsigned long a[MAX+1]={0,1,2};

int main(){
	#if DEBUG
		freopen("in","r",stdin);
	#endif

	int n;
	long long k;

	scanf("%d",&n);
	for(int i=3;i<=MAX;i++){
		a[i]=((2*a[i-1]+a[i-2])%32767);	//每项都要模32767
	}
	for(int i=0;i<n;i++){
		scanf("%lld",&k);
		printf("%lu\n",a[k]);
	}

	return 0;
}

/*
//递归超时
unsigned long long Pell(long long n);

int main(){
	#if DEBUG
		freopen("in","r",stdin);
	#endif

	long long n,k;

	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		scanf("%lld",&k);
		printf("%llu\n",Pell(k)%32767);
	}

	return 0;
}

unsigned long long Pell(long long n){
	if(n==1) return 1;
	if(n==2) return 2;
	return 2*Pell(n-1)+Pell(n-2);
}
*/
