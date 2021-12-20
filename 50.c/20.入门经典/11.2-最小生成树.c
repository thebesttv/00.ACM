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
int p[MAX];
struct Edge{
  int u,v,w;
  bool operator < (const Edge & b) const{
    return v<b.w;
  }
};
VR<Edge> edge;

int find(int x){
  return x<0 ? x : p[x]=find(p[x]);
}
void merge(int x, int y){
  int px=find(x),py=find(y);
  if(p[px]<p[py]){
    p[px]+=p[py]; p[py]=px;
  }else{
    p[py]+=p[px]; p[px]=py;
  }
}
int Kruskal(){
  int ans=0,cnt=0;
  MST(p,-1);
  sort(edge.begin(),edge.end());
  FOR(i,0,edge.size()){
    Edge & e=edge[i];
    int px=find(e.u),py=find(e.v);
    if(px!=py) {merge(e.u,e.v); ans+=e.w; cnt++;}
    if(cnt==n-1) break; //<b></b>
  }
  return ans;
}
