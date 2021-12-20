/*
  令 f(S,W) 表示已经询问的集合为S，已经确定w拥有的特性的集合为W，至少还要问多少问题。
  则 f(S,W) = min{ max{ f(S+{k},W), f(S+{k},W+{k}) } +1 }
    当最多只有1个物件满足条件P：“拥有W中的所有特性，且不拥有S-W中的任意一个特性”时，f(S,W)为0，因为已经确定，无需继续询问。
  对每个f(S,W)都要查看一遍满足P的物品数，因此可以初始化cnt[S][W]表示满足P的物品数，则可以对每个物品枚举S，来更新cnt[S][W]：
    for(i 0:n-1) for(j {S})
      cnt[j][j&fea[i]]++;
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

const int INF=0x3f3f3f3f;
int n,m;
int fea[140]; char t1[100];
int cf[1<<11][1<<11],cnt[1<<11][1<<11];

void PRINT(int n){
  printf("***");
  FOR(i,0,m) printf("%d",(n>>i)&1);
  printf("***");
}
int f(int S, int W){
  int & a=cf[S][W];
  if(a!=-1) return a;
  if(cnt[S][W]<=1) a=0;
  else if(cnt[S][W]==2) a=1;
  else{
    a=INF;
    //FOR(i,0,m) if(!(S&(1<<i))){
    FOR(i,0,m) if(!(S&(1<<i)) && cnt[S|(1<<i)][W] && cnt[S|(1<<i)][W|(1<<i)]){
      a=min(a,max(f(S|(1<<i),W),f(S|(1<<i),W|(1<<i)))+1);
    }
  }
  return a;
}

int main(void){
  while(scanf("%d%d",&m,&n)==2 && m){
#ifdef DEBUG
    printf("  get m: %d, n: %d\n",m,n);
#endif
    MST(fea,0); MST(cf,-1); MST(cnt,0);
    FOR(i,0,n){
      scanf("%s",t1);
      FOR(j,0,m) if(t1[j]=='1') fea[i]|=1<<j;
      FOR(j,0,(1<<m)) cnt[j][j&fea[i]]++; //<b>保证i有W中的所有，且i没有S-W中的任意一个</b>
    }
    printf("%d\n",f(0,0));
  }
  return 0;
}
