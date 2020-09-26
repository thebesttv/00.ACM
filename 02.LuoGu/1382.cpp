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

const int MAX = 4e5 + 20;
int n; VR<int> v; pii a[MAX];

int ID(int x){
  return lower_bound(ALL(v),x) - v.begin() + 1;
}

struct Rect{
  int l,r,h;
  void read(){
    scanf("%d%d%d",&h,&l,&r); --r;
    v.pb(l), v.pb(r);
  }
}rect[MAX];

struct ST{
  int n;
  struct Node{
    int l,r,m,v;
    void set(int l, int r, int m = 0){
      this->l = l, this->r = r, this->m = m;
    }
  }v[MAX<<2];

  void pushdown(int u){
    v[u<<1].v = max(v[u<<1].v, v[u].v);
    v[u<<1|1].v = max(v[u<<1|1].v, v[u].v);
    v[u].v = 0;
  }
  void build(pii *a, int n){
    this->n = n; build(1,1,n,a);
  }
  void build(int u, int l, int r, pii *a){
    if(l == r){
      v[u].set(a[l].FI,a[l].SE); return;
    }
    int m = (l+r)/2;
    build(u<<1,l,m,a);
    build(u<<1|1,m+1,r,a);
    v[u].set(v[u<<1].l,v[u<<1|1].r,v[u<<1].r);  // [l, r, m]
#ifdef DEBUG
    printf("node(%d) [%d, %d, m: %d]\n",u,v[u].l,v[u].r,v[u].m);
#endif
  }

  void set(int l, int r, int v){
    set(1,l,r,v);
  }
  void set(int u, int ql, int qr, int val){
    if(ql <= v[u].l && v[u].r <= qr){
      v[u].v = max(v[u].v, val); return;
    }
    pushdown(u);
    if(ql <= v[u].m) set(u<<1, ql, qr, val);
    if(v[u].m+1 <= qr) set(u<<1|1, ql, qr, val);
  }

  void fetch(Rect *a){
    fetch(1,1,n,++a);
  }
  void fetch(int u, int l, int r, Rect *&a){
    if(l == r){
      *a++ = Rect{v[u].l, v[u].r, v[u].v};
      return;
    }
    int m = (l+r)/2; pushdown(u);
    fetch(u<<1, l, m, a);
    fetch(u<<1|1, m+1, r, a);
  }
}sg;

void print(){
  VR<pii> ans;
  Rect last{0,0,0};
  FORR(i,1,n){
    if(last.h < rect[i].h){
      ans.pb({rect[i].l, last.h});
      ans.pb({rect[i].l, rect[i].h});
    }else if(last.h > rect[i].h){
      ans.pb({last.r+1, last.h});
      ans.pb({last.r+1, rect[i].h});
    }
    last = rect[i];
  }
  printf("%d\n",(int)ans.size());
  for(auto p : ans) printf("%d %d\n",p.FI,p.SE);
}

int main(void){
  scanf("%d",&n); FORR(i,1,n) rect[i].read();
  sort(ALL(v)), v.erase(unique(ALL(v)), v.end());
  int tail = 0, last = v[0]; a[tail++] = {v[0],v[0]};
  FOR(i,1,v.size()){
    if(last + 1 != v[i])
      a[tail++] = {last+1, v[i]-1};
    a[tail++] = {v[i],v[i]};
    last = v[i];
  }
#ifdef DEBUG
  FOR(i,0,tail) printf(" [%d, %d]",a[i].FI,a[i].SE); putchar('\n');
#endif
  sg.build(a-1, tail);
#ifdef DEBUG
  printf("built\n");
#endif

  FORR(i,1,n) sg.set(rect[i].l, rect[i].r, rect[i].h);

  n = sg.n; sg.fetch(rect);
#ifdef DEBUG
  FORR(i,1,n) printf("[%d, %d, h: %d]\n",rect[i].l,rect[i].r,rect[i].h);
#endif
  rect[++n] = {0,0,0}; print();

  return 0;
}
