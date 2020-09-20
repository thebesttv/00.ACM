// Tag: 线段树 ii
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
const int INF = 0x3f3f3f3f;
int n,m;

struct ST{
  int v[MAX<<2];

  void build(){
    build(1,1,n);
  }
  void build(int u, int l, int r){
    v[u] = INF;
    if(l == r) return;
    int m = (l+r)/2;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
  }
  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r) { v[u] = val; return; }
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    v[u] = min(v[u<<1], v[u<<1|1]);
  }
  int query(int l, int r, int p){
    return query(1,1,n,l,r,p);
  }
  int query(int u, int cl, int cr, int ql, int qr, int p){
    if(v[u] > p) return 0;
    if(cl == cr) { v[u] = INF; return 1; }
    int m = (cl + cr) / 2, s = 0;
    if(ql <= m) s += query(u<<1, cl, m, ql, qr, p);
    if(m+1 <= qr) s += query(u<<1|1, m+1, cr, ql, qr, p);
    v[u] = min(v[u<<1], v[u<<1|1]);
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m); sg.build();
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int x,v; scanf("%d%d",&x,&v);
      sg.set(x+1,v);
    }else{
      int l,r,p; scanf("%d%d%d",&l,&r,&p);
      printf("%d\n",sg.query(l+1,r,p));
    }
  }

  return 0;
}
