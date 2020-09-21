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

inline int read(){
  int ans=0,ch;
  do ch=getchar(); while(ch<'0' || ch>'9');
  do {ans=ans*10+ch-'0'; ch=getchar();} while(ch>='0' && ch<='9');
  return ans;
}

const int MAX=200000 + 20;
int n,m,s;
int f[MAX][20],dep[MAX],lg[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
bool vis[MAX];
int q[MAX],head,tail;

inline void addEdge(int u, int v){
  int t=tailE++;
  edge[t] = (Edge){v,se[u]}; se[u]=t;
}
int lca(int x, int y){
  if(dep[x]<dep[y]) swap(x,y);
  while(dep[x]>dep[y])
    x=f[x][lg[dep[x]-dep[y]]];
  if(x==y) return x;
  ROR(k,lg[dep[x]],0)
    if(f[x][k]!=f[y][k])
      x=f[x][k],y=f[y][k];
  return f[x][0];
}

const LL MOD = 1e9+7;
LL pow_mod(LL a, LL x){
  LL ans = 1;
  while(x){
    ans = x&1 ? ans*a%MOD : ans;
    a=a*a%MOD, x>>=1;
  }
  return ans;
}
LL rev(LL x) { return pow_mod(x,MOD-2); }

int main(void){
  n=read(); s = 1;
  //init lg
  for(int i=2;i<=n;i<<=1) lg[i]=1;  //<b> log2(1)=0，i从2开始 </b>
  //FORR(i,1,n) lg[i]+=lg[i-1];
  int *p=lg+1;
  FORR(i,1,n){ *p += *(p-1); p++; }

  //read edge
  int u,v;
  FOR(i,1,n){
    u=read(); v=read();
    addEdge(u,v); addEdge(v,u);
  }

  //bfs
  int d; q[tail++]=s; vis[s]=1;
  while(head<tail){
    u=q[head++]; d=dep[u];
    for(RE int k=1;(1<<k)<=d;k++)
      f[u][k] = f[f[u][k-1]][k-1];
    for(RE int i=se[u];i;i=edge[i].next) if(!vis[v=edge[i].v]){
      dep[v]=d+1; f[v][0]=u;
      vis[v]=1; q[tail++]=v;
    }
  }

  m = read(); int cnt = 0;
  FOR(k,0,m){
    int a=read(), b=read(), c=read(), t=read();
    int u = lca(b,c);
    int d1 = dep[a], d2 = dep[b]-dep[u] + dep[c]-dep[u] + dep[b];
    if(d1 < t &&  d2 < t) ++cnt;
#ifdef DEBUG
    printf("d1: %d, d2: %d\n",d1,d2);
#endif
  }
  printf("%lld\n",1ll*cnt*rev(m)%MOD);

  return 0;
}
