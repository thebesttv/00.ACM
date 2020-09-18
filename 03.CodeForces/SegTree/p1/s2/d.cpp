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
const int INF = 0x3f3f3f3f;
int n,m,a[MAX];

struct ST{
  LL v[MAX<<2]; int vm[MAX<<2];
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void pushup(int u){
    v[u] = v[u<<1] + v[u<<1|1];
    vm[u] = max(vm[u<<1], vm[u<<1|1]);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { v[u] = vm[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    pushup(u);
  }

  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r) { v[u] = vm[u] = val; return; }
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    pushup(u);
  }

  int find(int l, int x){
    int a = find(1,1,n,l,x);
    return a == INF ? 0 : a;
  }
  int find(int u, int cl, int cr, int ql, int x){
    if(ql <= cl && vm[u] < x) return INF;
    if(cl == cr) return cl;
    int m = (cl+cr)/2;
    if(ql <= m){
      int l = find(u<<1, cl, m, ql, x);
      if(l != INF) return l;
    }
    return find(u<<1|1, m+1, cr, ql, x);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build(a,n);
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int p,v; scanf("%d%d",&p,&v);
      sg.set(p+1,v);
    }else{
      int l,x; scanf("%d%d",&x,&l);
      printf("%d\n",sg.find(l+1, x) - 1);
    }
  }

  return 0;
}
