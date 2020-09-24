// Tag: 线段树 ii 数列
// 线段树维护最小值，支持区间设置等差数列、区间加
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

const int MAX = 1e6 + 20;
const int INF = 0x3f3f3f3f;
int n,tail; pii a[MAX];
struct Query{
  int type,l,r,d; // type = 1: I, type = 2: Q
};
VR<Query> Q;

int ID(int x){
  return lower_bound(a,a+tail,pii{x,x}) - a + 1;
}

struct ST{
  int n;
  struct Node{
    int l,r,m; LL a, d, vr, vm;  // h[i] = a + d * (i-l)
    void set(int l, int r){
      this->l = l, this->r = r;
    }
    void cal(){
      vr = a + d * (r-l);
      vm = max(a, vr);
    }
    int get(int h){ // first a[i] > h
      if(d <= 0) return l;
      if((h-a)%d == 0)
        return (h-a)/d + l + 1;
      else
        return (h-a+d-1)/d + l;
    }
  }v[MAX<<2];
  LL va[MAX<<2], sa[MAX<<2], sd[MAX<<2];

  void pushup(int u){
    v[u].vm = max(v[u<<1].vm, v[u<<1|1].vm);
  }
  void pushdown(int u){
    if(sa[u] != LLONG_MIN){
      sa[u<<1] = v[u<<1].a = sa[u];
      sd[u<<1] = v[u<<1].d = sd[u];

      sa[u<<1|1] = v[u<<1|1].a = sa[u] + sd[u] * (v[u<<1|1].l - v[u<<1].l);
      sd[u<<1|1] = v[u<<1|1].d = sd[u];

      v[u<<1].cal(), v[u<<1|1].cal();

      va[u<<1] = va[u<<1|1] = 0;

      sa[u] = sd[u] = LLONG_MIN;
    }

    if(va[u]){
      v[u<<1].a += va[u];
      v[u<<1].vm += va[u];
      v[u<<1].vr += va[u];
      va[u<<1] += va[u];

      v[u<<1|1].a += va[u];
      v[u<<1|1].vm += va[u];
      v[u<<1|1].vr += va[u];
      va[u<<1|1] += va[u];
      va[u] = 0;
    }
  }

  void build(pii *a, int n){
    this->n = n;
    build(1,1,n,a);
  }
  void build(int u, int l, int r, pii *a){
    sa[u] = sd[u] = LLONG_MIN;
    if(l == r){
      v[u].set(a[l].FI, a[l].SE);
      return;
    }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    v[u].set(v[u<<1].l, v[u<<1|1].r);
    v[u].m = v[u<<1].r;
  }

  void set(int l, int r, LL a, LL d){
#ifdef DEBUG
    printf("set [%d, %d], a: %lld, d: %lld\n",l,r,a,d);
#endif
    set(1,l,r,a,d);
  }
  void set(int u, int ql, int qr, LL a, LL d){
#ifdef DEBUG
    printf("set [%d, %d](%d) %d, %d, %lld, %lld\n",v[u].l,v[u].r,v[u].m,ql,qr,a,d);
#endif
    if(ql == v[u].l && v[u].r <= qr){
      v[u].a = a, v[u].d = d; v[u].cal();
      sa[u] = a, sd[u] = d; va[u] = 0;
      return;
    }

    pushdown(u);
    if(ql <= v[u].m){
      if(qr <= v[u].m) set(u<<1, ql, qr, a, d);
      else{
        set(u<<1, ql, v[u].m, a, d);
        set(u<<1|1, v[u].m+1, qr, a + d * (v[u].m+1 - ql), d);
      }
    }else{
      set(u<<1|1, ql, qr, a, d);
    }
    pushup(u);
  }

  void add(int l, int r, LL val){
    if(l > r) return;
#ifdef DEBUG
    printf("add [%d, %d] %lld\n",l,r,val);
#endif
    add(1,l,r,val);
  }
  void add(int u, int ql, int qr, LL val){
    if(ql <= v[u].l && v[u].r <= qr){
      v[u].a += val; v[u].vm += val; v[u].vr += val;
      va[u] += val;
      return;
    }
    pushdown(u);
    if(ql <= v[u].m) add(u<<1, ql, qr, val);
    if(v[u].m+1 <= qr) add(u<<1|1, ql, qr, val);
    pushup(u);
  }

  LL getvr(int p){
    if(!p) return 0;
    return getvr(1,1,n,p);
  }
  LL getvr(int u, int l, int r, int p){
    if(l == r) return v[u].vr;
    pushdown(u); int m = (l+r)/2;
    if(p <= v[u].m) return getvr(u<<1, l, m, p);
    else return getvr(u<<1|1, m+1, r, p);
  }

  int query(int h){ // the first > h
    if(v[1].vm <= h) return INF;
    return query(1, 1, n, h);
  }
  int query(int u, int l, int r, int h){
#ifdef DEBUG
    printf("query([%d, %d](%d) [%d, %d] %d\n",v[u].l,v[u].r,v[u].m,l,r,h);
#endif
    if(l == r) return v[u].get(h);
    pushdown(u); int m = (l+r)/2;
    if(v[u<<1].vm > h) return query(u<<1, l, m, h);
    else return query(u<<1|1, m+1, r, h);
  }

  void print(){
    print(1,1,n);
  }
  void print(int u, int l, int r){
    if(l == r)
      printf("node [%d, %d](%d), a: %lld, d: %lld, vr: %lld, vm: %lld\n",
          v[u].l,v[u].r,v[u].m,v[u].a,v[u].d,v[u].vr,v[u].vm);
    if(l == r) return;
    pushdown(u);
    print(u<<1, l, (l+r)/2);
    print(u<<1|1, (l+r)/2+1, r);
  }
}sg;

int main(void){
  scanf("%d",&n); int ch,l,r,h;
  set<int> st;
  while(true){
    do ch=getchar(); while(!isalpha(ch));
    if(ch == 'I'){
      scanf("%d%d%d",&l,&r,&h);
      Q.pb({1,l,r,h});
      st.insert(l), st.insert(r);
    }else if(ch == 'Q'){
      scanf("%d",&h);
      Q.pb({2,0,0,h});
    }else break;
  }

  int last = 0;
  for(int x : st){
    if(last + 1 != x){
      a[tail++] = {last+1, x-1};
    }
    a[tail++] = {x,x}; last = x;
  }
  if(last < n) a[tail++] = {last+1, n};
  if(tail > MAX) printf("WRONG\n");
#ifdef DEBUG
  FOR(i,0,tail) printf("[%d, %d] ",a[i].FI,a[i].SE); putchar('\n');
#endif
  sg.build(a-1,tail);

  for(auto &q : Q){
    if(q.type == 1){
      LL v = sg.getvr(q.l-1), r1 = sg.getvr(q.r);
      sg.set(q.l, q.r, v+q.d, q.d);
      LL r2 = sg.getvr(q.r);
#ifdef DEBUG
      printf("print(%d): r1: %lld, r2: %lld\n",q.r,r1,r2);
#endif
      sg.add(q.r+1, n, r2 - r1);
    }else{
      int v = sg.query(q.d);
      if(v == INF) v = n + 1;
      printf("%d\n",v-1);
    }
#ifdef DEBUG
    sg.print();
#endif
  }

  return 0;
}
