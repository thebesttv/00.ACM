// Tag: 线段树 最长连续子序列
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2004;
int n; LL G[MAX][MAX];
VR<int> vx, vy;

int ID(int x, const VR<int> &v){
  return lower_bound(ALL(v), x) - v.begin() + 1;
}

struct Node{
  int x,y,w;
  void read(){
    scanf("%d%d%d",&x,&y,&w);
    vx.pb(x), vy.pb(y);
  }
  void update(){
    x = ID(x, vx), y = ID(y, vy);
  }
}node[MAX];
VR<Node> vec[MAX];

struct ST{
  struct Data{
    LL sum, msl, msr, msm;
    Data(LL x = 0) : sum(x){
      msl = msm = msr = max(x, 0ll);
    }
  }v[MAX<<2];

  Data merge(const Data &l, const Data &r){
    Data a;
    a.sum = l.sum + r.sum;
    a.msl = max(l.msl, l.sum + r.msl);
    a.msr = max(r.msr, r.sum + l.msr);
    a.msm = max(l.msr + r.msl, max(l.msm, r.msm));
    return a;
  }

  void pushup(int u){
    v[u] = merge(v[u<<1], v[u<<1|1]);
  }
  void build(LL *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, LL *a){
    if(l == r) { v[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    pushup(u);
  }
  void add(int p, LL val){
    add(1,1,n,p,val);
  }
  void add(int u, int l, int r, int p, LL val){
    if(l == r) { v[u] = v[u].sum + val; return; }
    int m = (l+r)/2;
    if(p <= m) add(u<<1, l, m, p, val);
    else add(u<<1|1, m+1, r, p, val);
    pushup(u);
  }
  LL query(){
    return v[1].msm;
  }
}sg;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    vx.clear(), vy.clear(); MST(G,0);
    scanf("%d",&n);
    FORR(i,1,n) node[i].read(), vec[i].clear();

    sort(ALL(vx)), sort(ALL(vy));
    vx.erase(unique(ALL(vx)), vx.end());
    vy.erase(unique(ALL(vy)), vy.end());

    FORR(i,1,n){
      node[i].update();
      G[node[i].x][node[i].y] += node[i].w;
      vec[node[i].x].pb(node[i]);
#ifdef DEBUG
      printf("(%d, %d): %d\n",node[i].x,node[i].y,node[i].w);
#endif
    }

    LL ansMax = 0;
    FORR(i,1,n){
      sg.build(G[i],n);
      ansMax = max(ansMax, sg.query());
      FORR(j,i+1,n){
        for(Node &p : vec[j]) sg.add(p.y, p.w);
        ansMax = max(ansMax, sg.query());
      }
    }
    printf("%lld\n",ansMax);
  }

  return 0;
}
