// Tag: 
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

const int MAX = 100020;
int n,m;
struct ST{
  LL v[MAX<<2], sv[MAX<<2];

  void pushdown(int u, int l, int r, int m){
    if(sv[u] != -1){
      v[u<<1] = sv[u];
      v[u<<1|1] = sv[u];
      sv[u<<1] = sv[u];
      sv[u<<1|1] = sv[u];
      sv[u] = -1;
    }
  }
  void pushup(int u){
    v[u] = min(v[u<<1], v[u<<1|1]);
  }
  void build(){
    build(1,1,n);
  }
  void build(int u, int l, int r){
    sv[u] = -1;
    if(l == r) { v[u] = 0; return; }
    int m = (l+r)/2;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
    pushup(u);
  }
  void f(int l, int r, LL val){
    f(1,1,n,l,r,val);
  }
  void f(int u, int cl, int cr, int ql, int qr, LL val){
    if(ql <= cl && cr <= qr){
      v[u] = sv[u] = val;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) f(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) f(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }
  LL query(int l, int r){
    return query(1,1,n,l,r);
  }
  LL query(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; pushdown(u,cl,cr,m); LL s = LLONG_MAX;
    if(ql <= m) s = min(s, query(u<<1, cl, m, ql, qr));
    if(m+1 <= qr) s = min(s, query(u<<1|1, m+1, cr, ql, qr));
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m); sg.build();
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int l,r,v; scanf("%d%d%d",&l,&r,&v);
      sg.f(l+1,r,v);
    }else{
      int l,r; scanf("%d%d",&l,&r);
      printf("%lld\n",sg.query(l+1,r));
    }
  }

  return 0;
}
