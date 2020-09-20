// Tag: notag
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
int n,m,a[MAX];
struct ST{
  LL v[MAX<<2], av[MAX<<2];
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
  void pushdown(int u, int l, int r){
    if(av[u]){
      int m = (l+r)/2;
      v[u<<1] += av[u] * (m-l+1);
      v[u<<1|1] += av[u] * (r-m);
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void add(int l, int r, int val){
    add(1,1,n,l,r,val);
  }
  void add(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      v[u] += 1ll * val * (cr-cl+1);
      av[u] += val; return;
    }
    int m = (cl + cr)/2; pushdown(u,cl,cr);
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r) { v[u] = val; return; }
    int m = (l+r)/2; pushdown(u,l,r);
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  LL sum(int l, int r){
    if(r <= 0) return 0ll;
    return sum(1,1,n,l,r);
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; LL s = 0;
    pushdown(u,cl,cr);
    if(ql <= m) s += sum(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) s += sum(u<<1|1, m+1, cr, ql, qr);
    return s;
  }
  void print(){
    print(1,1,n);
  }
  void print(int u, int l, int r){
    if(l == r) { printf("%lld ",v[u]); return; }
    int m = (l+r)/2;
    pushdown(u,l,r);
    print(u<<1, l, m);
    print(u<<1|1, m+1, r);
  }
}f[41],g;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    f[a[i]].add(i,i,1);
  }

  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int l,r,c=0; scanf("%d%d",&l,&r);
      FORR(i,1,40) if(f[i].sum(l,r)) ++c;
      printf("%d\n",c);
    }else{
      int x,v; scanf("%d%d",&x,&v);
      f[a[x]].add(x,x,-1); a[x] = v;
      f[a[x]].add(x,x,1);
    }
  }

  return 0;
}
