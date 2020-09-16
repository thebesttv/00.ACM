// Tag: 可持久化 线段树
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
int n,m,q,st[MAX],len[MAX],v[MAX];

struct Node { int x,l,t; };

struct ST1{ // cache
  int n; Node v[MAX<<2], sv[MAX<<2];

  void pushdown(int u, int l, int r, int m){
    if(sv[u].x){
      v[u<<1] = sv[u];
      v[u<<1|1] = sv[u];
      sv[u<<1] = sv[u];
      sv[u<<1|1] = sv[u];
      sv[u] = {0, 0, 0};
    }
  }
  void set(int l, int r, Node p){
#ifdef DEBUG
    printf("set(%d, %d, {%d, %d, %d})\n",l,r,p.x,p.l,p.t);
#endif
    set(1,1,n,l,r,p);
  }
  void set(int u, int cl, int cr, int ql, int qr, Node p){
    if(ql <= cl && cr <= qr){
      sv[u] = v[u] = p; return;
    }
    int m = (cl + cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) set(u<<1, cl, m, ql, qr, p);
    if(m+1 <= qr) set(u<<1|1, m+1, cr, ql, qr, p);
  }

  Node get(int x){
#ifdef DEBUG
    Node p = get(1,1,n,x);
    printf("get(%d): {%d, %d, %d}\n",x,p.x,p.l,p.t);
#endif
    return get(1,1,n,x);
  }
  Node get(int u, int l, int r, int p){
    if(l == r) return v[u];
    int m = (l+r)/2; pushdown(u,l,r,m);
    if(p <= m) return get(u<<1, l, m, p);
    else return get(u<<1|1, m+1, r, p);
  }
}cg;

struct ST2{ // data
  int n;
  struct Node{
    LL v; Node *l, *r;
  }*head[MAX<<1], *cur[MAX<<2];

  void init(int n){
    this->n = n;
    int n4 = n*4; Node *p = new Node;
    p->v = 0; p->l = p->r = p;
    FORR(i,1,n4) cur[i] = p;
    head[0] = p;
  }

  void add(int l, int r, int k){
    _add(l, 1, k*2-1); _add(r+1, -1, k*2);
  }
  void _add(int p, int v, int ts){
#ifdef DEBUG
    printf("add(%d, %d, ts: %d)\n",p,v,ts);
#endif
    head[ts] = add(1,1,n,p,v);
  }
  Node *add(int u, int l, int r, int x, LL v){
    Node *p = new Node;
    if(l == r){
      p->v = cur[u]->v + v;
      p->l = p->r = nullptr;
      return cur[u] = p;
    }

    int m = (l+r)>>1;
    if(x <= m){
      p->l = cur[u<<1] = add(u<<1, l, m, x, v);
      p->r = cur[u<<1|1];
    }else{
      p->l = cur[u<<1];
      p->r = cur[u<<1|1] = add(u<<1|1, m+1, r, x, v);
    }
    p->v = p->l->v + p->r->v;
    return cur[u] = p;
  }

  LL sum(int x, int k){
    if(!k) return 0;
#ifdef DEBUG
    printf("sum(%d, ts: %d): %lld\n",x,k*2,sum(head[k*2], 1, n, 1, x));
#endif
    return sum(head[k*2], 1, n, 1, x);
  }
  LL sum(Node *u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return u->v;
    int m = (cl + cr)/2, s = 0;
    if(ql <= m) s += sum(u->l, cl, m, ql, qr);
    if(m+1 <= qr) s += sum(u->r, m+1, cr, ql, qr);
    return s;
  }
}dg;

int main(void){
  scanf("%d%d%d",&n,&m,&q); int tail = 1;
  FORR(i,1,m){
    st[i] = tail;
    int l,x; scanf("%d",&l); len[i] = l;
    while(l--) scanf("%d",&x), v[tail++] = x;
#ifdef DEBUG
    printf("data %d: [%d, %d]\n",i,st[i],st[i]+len[i]-1);
#endif
  }
  cg.n = n; dg.init(st[m] + len[m]);

  int last = 0;
  FORR(k,1,q){
    int op,l,r,x;
    scanf("%d",&op);
    if(op == 1){
      scanf("%d%d",&x,&l);
      cg.set(l, l + len[x] - 1, Node{x, l, last});
    }else if(op == 2){
      scanf("%d",&x); Node p = cg.get(x);
      if(!p.x) printf("0\n");
      else{
        LL ans = v[st[p.x] + (x - p.l)] + dg.sum(st[p.x] + (x - p.l), last);
        printf("%lld\n",ans % 256);
      }
    }else{
      last = k; scanf("%d%d%d",&x,&l,&r);
      dg.add(st[x] + l - 1, st[x] + r - 1, k);
    }
  }

  return 0;
}
