/*
描述
给定一个多项式(ax + by)^k，请求出多项式展开后 x^n * y^m 项的系数。

输入
共一行，包含 5 个整数，分别为 a，b，k，n，m，每两个整数之间用一个空格隔开。

输出
输出共 1 行，包含一个整数，表示所求的系数，这个系数可能很大，输出对 10007 取模后的结果。

提示
对于 30%的数据，有 0≤k≤10； 
对于 50%的数据，有 a = 1，b = 1； 
对于 100%的数据，有 0≤k≤1,000，0≤n, m≤k，且 n + m = k，0≤a，b≤1,000,000。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MOD = 10007;
int power_mod(int n, int a, int m){	//(n^a)%m
	if(a == 0 || n==1) return 1%m;
	if(a == 1) return n%m;
	int ans = power_mod(n, a/2, m);
	ans = (long long)(ans*ans)%m;
	if(a&1) ans = (long long)(ans*n)%m;
	return ans%m;
}
int c[1010][1010];
int C_mod(int n, int k, int m){
	//有模的情况下，不能用 C(n,k+1)=C(n,k)*(n-k)/k+1 推导，因为取模后可能不再能整除
	//只能用 C(n+1,k+1) = C(n,k) + C(n,k+1);
	//<b>有模时的推导最好没有除法</b>
	c[0][0]=1;
	for(int i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%m;
	}
	return c[n][k];
}

int main(void){
	int a,b,k,n,m;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	a = power_mod(a%MOD,n,MOD);
	b = power_mod(b%MOD,m,MOD);
	int c = C_mod(k, m, MOD);
	#ifdef DEBUG
	printf("  %d %d C(%d,%d)%%%d = %d\n",a,b,k,m,MOD,c);
	#endif
	printf("%d\n",(int)((long long)(a*b%MOD*c%MOD))%MOD);

	return 0;
}
