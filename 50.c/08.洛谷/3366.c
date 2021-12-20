/*
题目描述
如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出orz

输入输出格式
输入格式：
第一行包含两个整数N、M，表示该图共有N个结点和M条无向边。（N<=5000，M<=200000）
接下来M行每行包含三个整数Xi、Yi、Zi，表示有一条长度为Zi的无向边连接结点Xi、Yi

输出格式：
输出包含一个数，即最小生成树的各边的长度之和；如果该图不连通则输出orz

输入输出样例
输入样例#1： 复制
4 5
1 2 2
1 3 2
1 4 3
2 3 4
3 4 3

输出样例#1： 复制
7

说明
时空限制：1000ms,128M

数据规模：
对于20%的数据：N<=5，M<=20
对于40%的数据：N<=50，M<=2500
对于70%的数据：N<=500，M<=10000
对于100%的数据：N<=5000，M<=200000
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

const int MAX=200020;
int n,m,p[MAX];
struct Edge{
  int u,v,w;
  bool operator < (const Edge & e) const{
    return w<e.w;
  }
};
VR<Edge> edge;

int find(int x){
  return p[x]<0 ? x : p[x]=find(p[x]);
}
void merge(int x, int y){
  int px=find(x),py=find(y);
  if(px==py) return;
  p[py]=px;
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v,w; MST(p,-1);
  FOR(i,0,m){
    scanf("%d%d%d",&u,&v,&w);
    merge(u,v); edge.push_back((Edge){u,v,w});
  }
  int t=find(1);
  FORR(i,2,n) if(find(i)!=t) {printf("orz\n"); return 0;}

  MST(p,-1);
  sort(edge.begin(),edge.end());
  int cnt=0,ans=0;
  FOR(i,0,m){
    Edge & e=edge[i];
    int px=find(e.u),py=find(e.v);
    if(px==py) continue;
    merge(px,py); ans+=e.w; cnt++;
    if(cnt==n-1) break;
  }
  printf("%d\n",ans);

  return 0;
}
