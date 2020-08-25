// Tag: 线段树 区间翻转 可出题
// reverse/swap的区间皆为整个线段，因此可以使用线段树维护
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

const int MAX = 1 << 19;
int n,dep,q,a[MAX],rev[19];
struct ST{
  struct Node{
    LL sum;
    Node *lc, *rc;
  }node[MAX],*root,null;
  int tail = 0;
  void build() { tail = 0; root = build(1,n); }
  Node *build(int l, int r){
    Node *u = node + tail++;
    if(l == r){
      u->sum = a[l]; u->lc = u->rc = &null;
      return u;
    }
    int m = (l+r)/2;
    u->lc = build(l, m);
    u->rc = build(m+1, r);
    u->sum = u->lc->sum + u->rc->sum;
    return u;
  }

  void set(int x, int v) { set(root, 1, n, dep, x, v); }
  void set(Node *u, int cl, int cr, int dep, int x, int v){
    if(cl == cr){
      u->sum = v; return;
    }
    int m = (cl+cr)/2;
    if(!rev[dep]){
      if(x <= m) set(u->lc, cl, m, dep-1, x, v);
      else set(u->rc, m+1, cr, dep-1, x, v);
    }else{
      if(x <= m) set(u->rc, cl, m, dep-1, x, v);
      else set(u->lc, m+1, cr, dep-1, x, v);
    }
    u->sum = u->lc->sum + u->rc->sum;
  }

  LL sum(int l, int r) { return sum(root, 1, n, dep, l, r); }
  LL sum(Node *u, int cl, int cr, int dep, int ql, int qr){
    if(ql <= cl && cr <= qr) return u->sum;
    int m = (cl+cr)/2; LL ans = 0;
    if(!rev[dep]){
      if(ql <= m) ans += sum(u->lc, cl, m, dep-1, ql, qr);
      if(qr > m) ans += sum(u->rc, m+1, cr, dep-1, ql, qr);
    }else{
      if(ql <= m) ans += sum(u->rc, cl, m, dep-1, ql, qr);
      if(qr > m) ans += sum(u->lc, m+1, cr, dep-1, ql, qr);
    }
    return ans;
  }
}sg;

int main(void){
  scanf("%d%d",&dep,&q); n = 1<<dep;
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build();
  int op,k,x,l,r;
  while(q--){
    scanf("%d",&op);
    if(op==1){
      scanf("%d%d",&x,&k); sg.set(x,k);
    }else if(op==2){
      scanf("%d",&k);
      FORR(i,0,k) rev[i]^=1;
    }else if(op==3){
      scanf("%d",&k);
      if(k<dep) rev[k+1]^=1;
    }else{
      scanf("%d%d",&l,&r);
#ifdef DEBUG
      printf("rev:");
      FORR(k,0,dep) if(rev[k]) printf(" %d",k);
      putchar('\n');
#endif
      printf("%lld\n",sg.sum(l,r));
    }
  }

  return 0;
}
