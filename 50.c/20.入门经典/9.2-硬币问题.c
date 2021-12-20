/*
问题描述
有n种硬币，面值分别为v1, v2, ..., vi，每种硬币有无数个。输出用这些硬币恰好凑出S元的最小和最大硬币个数。
答案保证有解。

输入
第一行，n,S
第二行，共n个正整数，第i个表示vi。

输出
一行，分别为最小和最大硬币数目。
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

const int MAX=10020;
const int INF=0x3f3f3f3f;
int n,S,v[MAX];
int f[MAX],g[MAX];  //f[i]: 还剩i元时最小值
int rf[MAX],rg[MAX];

int main(void){
  scanf("%d%d",&n,&S);
  FOR(i,0,n) scanf("%d",&v[i]);
  sort(v,v+n);

  FORR(i,1,S){
    f[i]=INF; g[i]=-INF;
    for(int j=0;j<n && i>=v[j];j++){
      if(f[i]>f[i-v[j]]+1){
        f[i]=f[i-v[j]]+1;
        rf[i]=v[j];
      }
      if(g[i]<g[i-v[j]]+1){
        g[i]=g[i-v[j]]+1;
        rg[i]=v[j];
      }
    }
  }
  printf("%d %d\n",f[S],g[S]);

  //print
  int t=S;
  while(t){
    printf("%d ",rf[t]);
    t-=rf[t];
  }
  printf("\n");
  t=S;
  while(t){
    printf("%d ",rg[t]);
    t-=rg[t];
  }
  printf("\n");

  return 0;
}
