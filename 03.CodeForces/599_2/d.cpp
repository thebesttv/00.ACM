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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1e5 + 20;
int n,m;
VR<int> G[MAX];
set<int> st;

int vis[MAX], cnt[MAX];

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

void merge(int x, int y){
  x = fa(x), y = fa(y);
  if(x==y) return;
  if(p[x] < p[y]){
    p[x] += p[y];
    p[y] = x;
    st.erase(y);
  }else{
    p[y] += p[x];
    p[x] = y;
    st.erase(x);
  }
}

int main(void){
  MST(p,-1);
  scanf("%d%d",&n,&m);
  int u, v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    if(u < v) swap(u,v);
    G[u].push_back(v);
  }

  st.insert(1);
  FORR(u,2,n){
    for(int v : G[u]){
      int pv = fa(v);
      if(vis[pv] != u)
        vis[pv] = u, cnt[pv] = 1;
      else
        ++cnt[pv];
    }

    st.insert(u);
    VR<int> vst(st.begin(), st.end());
    for(int v : vst) if(v!=u && (vis[v]!=u || cnt[v] < -p[v])){
      merge(u,v);
    }
  }

  int ans = 0;
  FORR(u,1,n) for(int v : G[u]){
    if(fa(u) != fa(v)){
      merge(u,v); ++ans;
    }
  }
  printf("%d\n",ans);

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n,m;
VR<int> G[MAX];
set<int> st;

int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

void merge(int x, int y){
  x = fa(x), y = fa(y);
  if(p[x] < p[y]){
    p[x] += p[y];
    p[y] = x;
    st.erase(y);
  }else{
    p[y] += p[x];
    p[x] = y;
    st.erase(x);
  }
}

int main(void){
  MST(p,-1);
  scanf("%d%d",&n,&m);
  int u, v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    if(u < v) swap(u,v);
    G[u].push_back(v);
  }

  st.insert(1);
  FORR(u,2,n){
    map<int, int> mp;
    for(int v : G[u]){
      int pv = fa(v);
      ++mp[pv];
    }

    st.insert(u);
    for(int v : st) if(v!=u && (mp.count(v)==0 || mp[v] < -p[v])){
      merge(u,v);
#ifdef DEBUG
      printf("  merge (%d,%d)\n",u,v);
#endif
    }
  }

  int ans = 0;
  FORR(u,1,n) for(int v : G[u]){
    if(fa(u) != fa(v)){
      merge(u,v); ++ans;
#ifdef DEBUG
      printf("  merge (%d,%d) with ans++\n",u,v);
#endif
    }
  }
  printf("%d\n",ans);

  return 0;
}
*/
