#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,m,k;
int base;
VR<int> to[MAX];
bool isMon[MAX],vis1[MAX],vis2[MAX];

int getAll(int u, bool *vis, int color=1){ // frist get all available candies
  vis[u]=color; int s=1;
  for(int v : to[u]) if(vis[v]!=color && !isMon[v]){
    s+=getAll(v,vis);
  }
  return s;
}
void getMon(int u, VR<int> &vMon, bool *vis){
  vis[u]=1;
  for(int v : to[u]) if(!vis[v]){
    if(isMon[v]){
      vMon.push_back(v);
      vis[v]=1;
    }else getMon(v,vMon,vis);
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&m,&k);
    MST(isMon,0); FORR(i,1,n) to[i].clear();
    int u,v;
    FOR(i,0,m){
      scanf("%d%d",&u,&v);
      to[u].push_back(v);
      to[v].push_back(u);
    }
    FOR(i,0,k){
      scanf("%d",&u); isMon[u]=1;
    }

    VR<int> vMon;
    MST(vis1,0);
    getMon(1,vMon,vis1);
    MST(vis1,0);
    base = getAll(1,vis1);
#ifdef DEBUG
    printf("base: %d\n",base);
    printf("get Monster in:");
    for(int u : vMon) printf(" %d",u);
    printf("\n");
#endif

    double eMax=base;
    //for(int u : vMon) if(to[u].size()>=2){
    for(int u : vMon){
      int tbase=0, color=1;
      for(int v : to[u]) if(!vis1[v]){
        tbase += getAll(v,vis2,color++);
      }
#ifdef DEBUG
      printf("  tbase: %d\n",tbase);
#endif
      eMax = max(eMax, base + (1.0*tbase)/to[u].size());
    }
    printf("%lf\n",eMax);
  }

  return 0;
}
