/*
题目背景
题目名称是吸引你点进来的
实际上该题还是很水的

题目描述
区间质数个数

输入输出格式
输入格式：
一行两个整数 询问次数n，范围m
接下来n行，每行两个整数 l,r 表示区间

输出格式：
对于每次询问输出个数 t，如l或r∉[1,m]输出 Crossing the line

输入输出样例
输入样例#1：
2 5
1 3
2 6

输出样例#1：
2
Crossing the line

说明
数据范围和约定
对于20%的数据 1<=n<=10 1<=m<=10
对于100%的数据 1<=n<=1000 1<=m<=1000000 -10^9<=l<=r<=10^9 1<=t<=1000000
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=1000000;
bool a[MAX+20];
int s[MAX+20];

int main(void){
  a[1]=1; int sq=sqrt(MAX+0.5);
  for(int i=4;i<=MAX;i+=2) a[i]=1;
  for(int i=3;i<=sq;i+=2) if(!a[i])
    for(int j=i*i;j<=MAX;j+=i) a[j]=1;
#ifdef DEBUG
  FORR(i,1,50) if(!a[i]) printf("%d ",i); printf("\n");
#endif
  FORR(i,1,MAX) s[i]=s[i-1]+(a[i]==0);
  int n,m,l,r;
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    scanf("%d%d",&l,&r);
    if(l<1 || l>m || r<1 || r>m || l>r) printf("Crossing the line\n");
    else printf("%d\n",s[r]-s[l-1]);
  }

  return 0;
}
