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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1000020;
const int INF=1000000020;
int n,m,a[MAX],ori[MAX],f[MAX];
int topo[MAX],c[MAX],t;
struct Edge{
  int v,next;
}edge[MAX];
int se[MAX],tailE=1;

void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
bool dfs(int u){
  c[u]=-1; int v;
  for(int i=se[u];i;i=edge[i].next){
    v=edge[i].v;
    if(c[v]<0) return false;
    else if(!c[v] && !dfs(v)) return false;
  }
  c[u]=1; topo[t--]=u;
  return true;
}
bool topo_sort(){
  t=n;
  FORR(i,1,n) if(!c[i])
    if(!dfs(i)) return false;
  return true;
}
bool check_DAG(int t){
  memcpy(a,ori,SIZ(ori));
  int u,v,d,tm=m;
  ROR(i,n,1){
    u=topo[i]; if(a[u]>=t) continue;
    d=t-a[u]; a[u]=t;
    a[v=f[u]]-=d;
    if(f[v]==-1 && a[v]<t){
      tm-=t-a[v]; a[v]=t;
      if(tm<0) return false;
    }
  }
  return true;
}
bool check_nonDAG(int t){

}

int main(void){
  //freopen("in3.txt","r",stdin);
  scanf("%d%d",&n,&m);
  int tMax=0,tMin=INF;
  FORR(i,1,n){
    scanf("%d",&f[i]);
    if(f[i]!=-1) addEdge(f[i],i);
  }
  for(RE int i=1,t;i<=n;i++){
    scanf("%d",&t); ori[i]=t;
    t>tMax ? tMax=t : 0 ;
    t<tMin ? tMin=t : 0 ;
  }

  int L=tMin,R=tMax+m;
  if(topo_sort()){
    while(L<R){
      int M=L+((R-L+1)>>1);
      if(check_DAG(M)){
        L=M;
        //printf("  [%d,%d]: %d, ok\n",L,R,M);
      }else{
        R=M-1;
        //printf("  [%d,%d]: %d, not ok\n",L,R,M);
      }
    }
  }else{  //TODO
  }
  printf("%d\n",L);

  return 0;
}
