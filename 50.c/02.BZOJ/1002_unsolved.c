/*
Description
轮状病毒有很多变种，所有轮状病毒的变种都是从一个轮状基产生的。一个N轮状基由圆环上N个不同的基原子和圆心处一个核原子构成的，2个原子之间的边表示这2个原子之间的信息通道。如图1002-1.png所示。
N轮状病毒的产生规律是在一个N轮状基中删去若干条边，使得各原子之间有唯一的信息通道，例如共有16个不同的3轮状病毒，如图1002-2.png所示。
现给定n(N<=100)，编程计算有多少个不同的n轮状病毒

Input
第一行有1个正整数n

Output
计算出的不同的n轮状病毒数输出

Sample Input
3

Sample Output
16
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

/*
const int MAX=20;
struct Edge{
  int u,v;
}edge[MAX*MAX];
bool G[MAX][MAX],vis[MAX];
int n,cnt,tot,tail=0;
int rec[MAX];

bool bfs(){
  queue<int> q; MST(vis,0);
  q.push(0); vis[0]=1;
  while(!q.empty()){
    int u=q.front(); q.pop();
    FORR(i,0,n) if(G[u][i] && !vis[i]){
      q.push(i); vis[i]=1;
    }
  }
  FORR(i,0,n) if(!vis[i]) return false;
  return true;
}
void dfs(int cur, int step){
  if(cur>tail) return;
  if(step==n){
    cnt+=bfs(); tot++; return;
  }
  int u=edge[cur].u,v=edge[cur].v;
  G[u][v]=G[v][u]=1;
  dfs(cur+1,step+1);
  G[u][v]=G[v][u]=0;
  dfs(cur+1,step);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) {edge[tail].u=i; edge[tail].v=i+1; tail++;}
  edge[tail-1].v=1;
  FORR(i,1,n) {edge[tail].u=0; edge[tail].v=i; tail++;}
#ifdef DEBUG
  FOR(i,0,tail) printf("  edge[%d]: (%d,%d)\n",i,edge[i].u,edge[i].v);
#endif

  dfs(0,0);
  printf("%d in %d\n",cnt,tot);


  return 0;
}
*/
