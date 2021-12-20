/*
描述
A sequence of positive integers is Palindromic if it reads the same forward and backward. For example:
23 11 15 1 37 37 1 15 11 23
1 1 2 3 4 7 7 10 7 7 4 3 2 1 1
A Palindromic sequence is Unimodal Palindromic if the values do not decrease up to the middle value and then (since the sequence is palindromic) do not increase from the middle to the end For example, the first example sequence above is NOT Unimodal Palindromic while the second example is.
A Unimodal Palindromic sequence is a Unimodal Palindromic Decomposition of an integer N, if the sum of the integers in the sequence is N. For example, all of the Unimodal Palindromic Decompositions of the first few integers are given below:
1: (1)
2: (2), (1 1)
3: (3), (1 1 1)
4: (4), (1 2 1), (2 2), (1 1 1 1)
5: (5), (1 3 1), (1 1 1 1 1)
6: (6), (1 4 1), (2 2 2), (1 1 2 1 1), (3 3),
(1 2 2 1), ( 1 1 1 1 1 1)
7: (7), (1 5 1), (2 3 2), (1 1 3 1 1), (1 1 1 1 1 1 1)
8: (8), (1 6 1), (2 4 2), (1 1 4 1 1), (1 2 2 2 1),
(1 1 1 2 1 1 1), ( 4 4), (1 3 3 1), (2 2 2 2),
(1 1 2 2 1 1), (1 1 1 1 1 1 1 1)

Write a program, which computes the number of Unimodal Palindromic Decompositions of an integer.

输入
Input consists of a sequence of positive integers, one per line ending with a 0 (zero) indicating the end.
N<250

输出
For each input value except the last, the output is a line containing the input value followed by a space, then the number of Unimodal Palindromic Decompositions of the input value. See the example on the next page.
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

long long check[250][250][250];
long long sum[250];

long long f(int a, int n, int N){
	long long & ans=check[a][n][N];
	if(ans!=-1) return ans;
	if(n==1){
		if(a==N) ans=1;
		else ans=0;
	}else if(n==2){
		if(N&2) ans=0;
		else ans=1;
	}else if(n==N){
		if(a==1) ans=1;
		else ans=0;
	}else{
		//for(int i=a;i<=(N/n);i++) ans+=f(i,n-2,N-2*i);
		ans=f(a,n-2,N-2*a);
	}
	return ans;
}

int main(void){
	freopen("out","w",stdout);
	memset(check,-1,sizeof(check));
	for(int a=1;a<250;a++) for(int n=1;n<250;n++) for(int N=1;N<250;N++)
		f(a,n,N);
	for(int N=1;N<250;N++) for(int a=1;a<250;a++) for(int n=1;n<250;n++)
		sum[N]+=check[a][n][N];
//	for(int i=1;i<=250;i++) printf("%d\t%lld\n",i,sum[i]);
	int n;
	while(scanf("%d",&n)==1 && n)
		printf("%d %lld\n",n,sum[n]);

	return 0;
}
