// Tag: 线段树
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

const int MAX = 100000 + 20;
int n,m,a[MAX];

struct ST{
  LL v[MAX<<2], av[MAX<<2];

  void pushdown(int u, int l, int r, int m){
    if(av[u]){
      v[u<<1] += av[u] * (m-l+1);
      v[u<<1|1] += av[u] * (r-m);
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { v[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void add(int l, int r, int val){
    add(1,1,n,l,r,val);
  }
  void add(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      v[u] += 1ll * val * (cr - cl + 1);
      av[u] += val; return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  LL sum(int l, int r){
    return sum(1,1,n,l,r);
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; LL s = 0; pushdown(u,cl,cr,m);
    if(ql <= m) s += sum(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) s += sum(u<<1|1, m+1, cr, ql, qr);
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int l,r,v; scanf("%d%d%d",&l,&r,&v);
      sg.add(l+1,r,v);
    }else{
      int x; scanf("%d",&x); ++x;
      printf("%lld\n",sg.sum(x,x));
    }
  }

  return 0;
}
