/*
描述
Bessie has gone to the mall's jewelry store and spies a charm bracelet. Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N≤ 3,402) available charms. Each charm iin the supplied list has a weight Wi(1 ≤ Wi≤ 400), a 'desirability' factor Di(1 ≤ Di≤ 100), and can be used at most once. Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M≤ 12,880).

Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, deduce the maximum possible sum of ratings.

输入
Line 1: Two space-separated integers: N and M
Lines 2..N+1: Line i+1 describes charm i with two space-separated integers: Wi and Di

输出
Line 1: A single integer that is the greatest sum of charm desirabilities that can be achieved given the weight constraints
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int N,M;
struct Ind{
	int w;
	int d;

	bool operator < (const Ind b) const {
		return w<b.w;
	}
}a[3403];
int f[12881];
bool book[12881][3403];

int main(void){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d%d",&a[i].w,&a[i].d);
	}
	sort(a,a+N); int Max=0;
	for(int i=a[0].w;i<=M;i++){
		int ans=0,u=0,left;
		for(int j=0;j<N;j++){
			left=i-a[j].w;
			if(left<0) break;
			if(book[left][j]) continue;
			if(f[left]+a[j].d>ans){
				ans=f[left]+a[j].d; u=j;
			}
		}
		left=i-a[u].w;
		memcpy(book[i],book[left],sizeof(book[i])); book[i][u]=1;
		f[i]=ans;
		Max=max(Max,f[i]);
	}
	printf("%d\n",Max);

	return 0;
}
