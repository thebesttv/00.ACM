/*
描述
农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。他计算出并记录下了接下来 N (1 ≤ N ≤ 100,000) 天里每天需要的开销。

约翰打算为连续的M (1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。

约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。


输入
第一行包含两个整数N,M，用单个空格隔开。

接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
输出
一个整数，即最大月度开销的最小值。
*/

#include<iostream>
#include<cstdio>
#include<cmath>

int a[100000];
long n,m;
long sum=0;

long Cal(long max);

int main(void){
	int max=0; long cur;
	scanf("%ld%ld",&n,&m);
	for(long i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		a[i]=t; sum+=t;
		max=(t>max ? t : max);
	}
	long L=max, R=sum;
	while(L<=R){
//printf("  %ld %ld\n",L,R);
		long M=L+(R-L)/2;
		if(Cal(M)>m) L=M+1;	//<b>条件为大于m，而非大于等于m</b>
		else R=M-1;
	}
	printf("%ld\n",L);

	return 0;
}

long Cal(long max){
	long cou=0;
	for(long i=0;i<n;i++){
		long tot=a[i];
		if(tot<=max){
			cou++;
			for(long j=i+1;j<n;j++){
				if(tot+a[j]>max) break;
				tot+=a[j]; i=j;
			}
		}else return m;
	}
	return cou;
}
