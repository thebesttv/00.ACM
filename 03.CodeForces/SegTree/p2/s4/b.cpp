// Tag: 线段树 数列
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

const int MAX = 2e5 + 20;
int n,m;
struct ST{
  LL v[MAX<<2], av[MAX<<2], dv[MAX<<2];

  void pushdown(int u, int l, int r, int m){
    if(dv[u]){
      v[u<<1] += dv[u] * (m-l) * (m-l+1) / 2;
      v[u<<1|1] += dv[u] * (m+1-l + r-l) * (r-m) / 2;
      dv[u<<1] += dv[u];
      dv[u<<1|1] += dv[u];
      av[u<<1|1] += dv[u] * (m+1-l);
      dv[u] = 0;
    }
    if(av[u]){
      v[u<<1] += av[u] * (m-l+1);
      v[u<<1|1] += av[u] * (r-m);
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void pushup(int u){
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void add(int l, int r, int a, int d){
    add(1,1,n,l,r,a,d);
  }
  void add(int u, int cl, int cr, int ql, int qr, LL a, LL d){
#ifdef DEBUG
    printf("add(%d, [%d, %d], [%d, %d], a: %lld, d: %lld)\n",
        u,cl,cr,ql,qr,a,d);
#endif
    if(ql == cl && cr <= qr){
      v[u] += (a + a + d * (cr - cl)) * (cr - cl + 1) / 2;
      av[u] += a; dv[u] += d; return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m){
      add(u<<1, cl, m, ql, qr, a, d);
      if(m+1 <= qr) add(u<<1|1, m+1, cr, m+1, qr, a + d * (m+1-ql), d);
    }else{  // ql > m
      add(u<<1|1, m+1, cr, ql, qr, a, d);
    }
    pushup(u);
  }
  LL sum(int l, int r){
    return sum(1,1,n,l,r);
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; pushdown(u,cl,cr,m); LL s = 0;
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
      int l,r,a,d; scanf("%d%d%d%d",&l,&r,&a,&d);
      sg.add(l,r,a,d);
    }else{
      int x; scanf("%d",&x);
      printf("%lld\n",sg.sum(x,x));
    }
  }

  return 0;
}
