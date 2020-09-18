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
  struct Node{
    LL sum, msl, msm, msr;
    Node(int x = 0) : sum(x){
      msl = msm = msr = max(x, 0);
    }
  }node[MAX<<2];

  Node merge(const Node &l, const Node &r){
    Node a;
    a.sum = l.sum + r.sum;
    a.msl = max(l.msl, l.sum + r.msl);
    a.msr = max(r.msr, r.sum + l.msr);
    a.msm = max(l.msr + r.msl, max(l.msm, r.msm));
    return a;
  }

  void build(int *a, int n){
    build(1,1,n,a);
  }

  void pushup(int u){
    node[u] = merge(node[u<<1], node[u<<1|1]);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { node[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    pushup(u);
  }
  void set(int p, int val){
    set(1,1,n,p,val);
  }
  void set(int u, int l, int r, int p, int val){
    if(l == r) { node[u] = val; return; }
    int m = (l+r)/2;
    if(p <= m) set(u<<1, l, m, p, val);
    else set(u<<1|1, m+1, r, p, val);
    pushup(u);
  }
  LL maxsum(int l, int r){
    return maxsum(1,1,n,l,r).msm;
  }
  Node maxsum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return node[u];
    int m = (cl+cr)/2; Node l,r;
    if(ql <= m) l = maxsum(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) r = maxsum(u<<1|1, m+1, cr, ql, qr);
    return merge(l,r);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build(a,n);
  printf("%lld\n",sg.maxsum(1,n));
  while(m--){
    int p,v; scanf("%d%d",&p,&v); sg.set(p+1,v);
    printf("%lld\n",sg.maxsum(1,n));
  }

  return 0;
}
