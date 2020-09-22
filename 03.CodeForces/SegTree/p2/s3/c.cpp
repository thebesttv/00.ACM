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

const int MAX = 1e5 + 20;
int n,m;

struct ST{
  LL v[MAX<<2], av[MAX<<2];

  void pushup(int u){
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
  void pushdown(int u, int l, int r, int m){
    if(av[u]){
      v[u<<1] += av[u];
      v[u<<1|1] += av[u];
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void add(int l, int r, LL val){
    add(1,1,n,l,r,val);
  }
  void add(int u, int cl, int cr, int ql, int qr, LL val){
    if(ql <= cl && cr <= qr){
      v[u] += val; av[u] += val;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }

  int query(int l, int x){
    return query(1,1,n,l,x);
  }
  int query(int u, int cl, int cr, int ql, int x){
    if(cr < ql || v[u] < x) return INT_MAX;
    if(cl == cr) return cl;
    int m = (cl+cr)/2, s = INT_MAX; pushdown(u,cl,cr,m);
    if(ql <= m) s = query(u<<1, cl, m, ql, x);
    if(s == INT_MAX) s = query(u<<1|1, m+1, cr, ql, x);
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
      int x,l; scanf("%d%d",&x,&l);
      int ans = sg.query(l+1, x);
      printf("%d\n", ans == INT_MAX ? -1 : ans-1);
    }
  }

  return 0;
}
