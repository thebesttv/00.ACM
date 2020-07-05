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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
int n,k,a[MAX],len[MAX],rlen[MAX];
VR<int> G[MAX], leaf, vlen;

int dfs(int u){
  if(!G[u].size()){
    leaf.push_back(u);
    return 0;
  }
  int tMax = -1, r=-1;
  for(int v : G[u]){
    int t = dfs(v);
    if(t>tMax){
      tMax = t, r=v;
    }
  }
  len[u] = tMax + 1, rlen[u] = r;
  return len[u];
}

void mark(int u, int l){
  len[u]=l;
  for(int v : G[u])
    if(v!=rlen[u]){
      mark(v, 1);
    }else{
      mark(v,l+1);
    }
}

int main(void){
  scanf("%d%d",&n,&k);
  FOR(i,0,k) scanf("%d",&a[i]);
  sort(a,a+k);
  FOR(i,1,n){
    int p; scanf("%d",&p);
    G[p].push_back(i);
  }

  dfs(0);

#ifdef DEBUG
  FOR(i,0,n) printf("len[%d]: %d, r: %d\n",i,len[i],rlen[i]);
#endif
  mark(0,0);

#ifdef DEBUG
  FOR(i,0,n) printf("len[%d]: %d\n",i,len[i]);
#endif

  for(int u : leaf)
    vlen.push_back(len[u]);
  sort(ALL(vlen));
  LL ans = 0;
  FOR(i,0,k)
    ans += 1ll*vlen[i]*a[i];
  printf("%lld\n",ans);


  return 0;
}

/*
const int MAX = 1e5 + 20;
int n,k,a[MAX],dep[MAX];
VR<int> G[MAX];

int dfs(int u){
  int &a = dep[u];
  for(int v : G[u]){
    a = max(a, dfs(v)+1);
  }
  return a;
}

int main(void){
  scanf("%d%d",&n,&k);
  FOR(i,0,k) scanf("%d",&a[i]);
  sort(a,a+k,greater<int>());
  FOR(i,1,n){
    int p; scanf("%d",&p);
    G[p].push_back(i);
  }

  dfs(0);

  LL ans = 0;
  VR<int> v;
  for(int u : G[0])
    v.push_back(dep[u]+1);
  sort(ALL(v),greater<int>());
#ifdef DEBUG
  printf("v:"); for(int x : v) printf(" %d",x); putchar('\n');
#endif
  FOR(i,0,v.size())
    ans += 1ll*a[i]*v[i];
  FOR(i,v.size(),k)
    ans += a[i];
  printf("%lld\n",ans);

  return 0;
}
*/
