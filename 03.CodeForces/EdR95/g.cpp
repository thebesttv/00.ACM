// Tag: 线段树 构造 iiii
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

const int MAX = 5e5 + 20;
int n; VR<int> pos[MAX];
struct ST{
  int v[MAX<<2], c[MAX<<2], av[MAX<<2];

  void build(int n) { build(1,1,n); }
  void build(int u, int l, int r){
    if(l == r) { c[u] = 1; return; }
    int m = (l+r)/2;
    build(u<<1, l, m);
    build(u<<1|1, m+1, r);
    c[u] = c[u<<1] + c[u<<1|1];
  }

  void pushdown(int u, int l, int r){
    if(av[u]){
      v[u<<1] += av[u];
      v[u<<1|1] += av[u];
      av[u<<1] += av[u];
      av[u<<1|1] += av[u];
      av[u] = 0;
    }
  }
  void pushup(int u){
    v[u] = min(v[u<<1], v[u<<1|1]);
    c[u] = (v[u<<1] == v[u] ? c[u<<1] : 0)
         + (v[u<<1|1] == v[u] ? c[u<<1|1] : 0);
  }

  void add(int l, int r, int val){
#ifdef DEBUG
    printf("add (%d, %d, %d)\n",l,r,val);
#endif
    add(1,1,n,l,r,val);
  }
  void add(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      v[u] += val; av[u] += val;
      return;
    }
    pushdown(u, cl, cr);
    int m = (cl+cr)/2;
    if(ql <= m) add(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) add(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }

  int query(int l, int r) { return query(1, 1, n, l, r); }
  int query(int u, int cl, int cr, int ql ,int qr){
    if(ql <= cl && cr <= qr)
      return v[u] == 0 ? c[u] : 0;
    pushdown(u, cl, cr);
    int sum = 0, m = (cl+cr)/2;
    if(ql <= m) sum += query(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) sum += query(u<<1|1, m+1, cr, ql, qr);
    return sum;
  }

  void print() { print(1,1,n); }
  void print(int u, int l, int r){
    if(l == r) { printf("%d ",v[u]); return; }
    pushdown(u,l,r); int m = (l+r)/2;
    print(u<<1,l,m), print(u<<1|1,m+1,r);
  }
}sg;

int main(void){
  scanf("%d",&n); sg.build(n);
  LL ans = 0;
  FORR(i,1,n){
    int x; scanf("%d",&x);
    VR<int> &v = pos[x]; v.pb(i);

    sg.add(1,i,1); int siz = v.size();
    if(siz >= 2) sg.add(1,v[siz-2],-1);
    if(siz >= 3) sg.add(1,v[siz-3],-1);
    if(siz >= 4) sg.add(1,v[siz-4], 2);
#ifdef DEBUG
    sg.print(); putchar('\n');
#endif
    ans += sg.query(1,i);
  }
  printf("%lld\n",ans);

  return 0;
}
