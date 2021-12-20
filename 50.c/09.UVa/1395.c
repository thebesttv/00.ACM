/*
  解题报告：
    带枚举的最小生成树。
    先将所有边按权值升序排列，如果在[l,r]中的边能使得n个点全连通，则一定存在一个苗条度不大于w(r)-w(l)的生成树。
    枚举l，然后对从l开始的边采用Kruskal算法，如果全连通则停止，并更新ans。但如果不能全连通，则跳出l的循环，直接输出答案。因为如果[l,m]的边都不能使得n个点全连通，那么[l+1,m]更不可能使得n个点全连通。

    ans=-1
    for(i 1:m){
      for(j i:m){
        如果可使用j，更新cnt和并查集
        如果cnt==n-1，记录j并跳出循环
      }
      如果无j的记录，跳出循环
      否则更新ans
    }
    输出ans
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);(i)++)
#define ROR(i,a,b) for(int i=(a);i>=(b);i--)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)

const int MAX=120;
int n,m;
struct Edge{
  int u,v,w;

  Edge() { }
  Edge(int u_, int v_, int w_): u(u_), v(v_), w(w_) { }
  bool operator < (const Edge & b) const {
    return w<b.w;
  }
};
VR<Edge> edge;
int p[MAX];

int gP(int x){
  return p[x]<0 ? x : p[x]=gP(p[x]);
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    edge.clear();
    int u,v,w;
    FOR(i,0,m){
      scanf("%d%d%d",&u,&v,&w);
      edge.push_back(Edge(u,v,w));
    }
    sort(edge.begin(),edge.end());

    int ans=-1;
    FOR(i,0,m){
      MST(p,-1);  //<b></b>
      int rr=-1,cnt=0;
      FOR(j,i,m){
        Edge & e=edge[j];
        int x=e.u,y=e.v;
        int px=gP(x),py=gP(y);
        if(px==py) continue;
        p[px]=py; cnt++;
        if(cnt==n-1) {rr=j; break;}
      }
      if(rr==-1) break;
      int t=edge[rr].w-edge[i].w;
      ans = ans==-1 ? t : min(ans,t); //<b></b>
    }
    printf("%d\n",ans);
  }

  return 0;
}
