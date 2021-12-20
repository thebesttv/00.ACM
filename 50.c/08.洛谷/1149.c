/*
给你n根火柴棍，你可以拼出多少个形如“A+B=C”的等式？等式中的A、B、C是用火柴棍拼出的整数（若该数非零，则最高位不能是0）。用火柴棍拼数字0-9的拼法如图所示：
  数字：	0  1  2  3  4  5  6  7  8  9
  消耗火柴：	6  2  5  5  4  5  6  3  7  6

注意：

加号与等号各自需要两根火柴棍

如果A≠B，则A+B=C与B+A=C视为不同的等式（A、B、C>=0）

n根火柴棍必须全部用上

输入输出格式

输入格式：
输入文件matches.in共一行，一个整数n（n<=24）。

输出格式：
输出文件matches.out共一行，表示能拼成的不同等式的数目。
*/

//for循环，超时
#include<stdio.h>
#include<stdlib.h>

int a[10]={6,2,5,5,4,5,6,3,7,6};
int book[1000000];

int Count(int n);

int main(void){
	int n;
	register int cou=0;
	register long tot=0;
	scanf("%d",&n);
	for(register int i=0;i<(n-4)/2/2;i++) tot=tot*10+1;
	for(register int i=0;i<=tot;++i)
		for(register int j=0;j<=tot;++j){
			register int toti=Count(i); if(toti>n) continue;
			register int totj=Count(j); if(toti+totj>n) continue;
			if((n-toti-totj-4)==Count(i+j)) cou++;
		}
	printf("%d\n",cou);

	return 0;
}

int Count(register int n){
	register int sum=0,t=n;
	if(n==0) return a[0];
	if(n<1000000 && book[n]!=0) return book[n];
	while(t>0){
		sum+=a[t%10];
		t/=10;
	}
	return book[n]=sum;
}
