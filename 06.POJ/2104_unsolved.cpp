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

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
int n,m,a[MAX],v[MAX];

struct HJT{
  int v[MAX],n;
  struct Node{
    int s;
    Node *lc, *rc;
  }*node[MAX<<2], *head[MAX];

  void pushup(Node *u){
    u->s = 0;
    if(u->lc) u->s += u->lc->s;
    if(u->rc) u->s += u->rc->s;
  }
  void add(int h, int p){
    head[h] = add(1,1,n,p);
  }
  Node *add(int u, int cl, int cr, int p){
    Node *o = new Node; node[u] = o;
    if(cl==cr){
      ++v[p]; o->s = v[p];
      o->lc = o->rc = 0;
      return o;
    }
    int m = (cl+cr)>>1;
    if(p<=m){
      o->lc = add(u<<1,cl,m,p);
      o->rc = node[u<<1|1];
    }else{
      o->lc = node[u<<1];
      o->rc = add(u<<1|1,m+1,cr,p);
    }
    pushup(o);
    return o;
  }
  int query(int u, int v, int k){
    return query(head[u], head[v],1,n,k);
  }
  int query(Node *u, Node *v, int cl, int cr, int k){
    if(cl==cr) return cl;
    int s = (v && v->lc ? v->lc->s : 0) - (u && u->lc ? u->lc->s : 0);
    int m = (cl+cr)>>1;
    if(s>=k) return query(u ? u->lc : 0, v ? v->lc : 0, cl, m, k);
    else return query(u ? u->rc : 0, v ? v->rc : 0, m+1, cr, k-s);
  }
  int sum(int id, int l, int r){
    return head[id] ? sum(head[id],1,n,l,r) : 0;
  }
  int sum(Node *u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr) return u->s;
    int m = (cl+cr)>>1,s=0;
    if(ql<=m && u->lc) s = sum(u->lc,cl,m,ql,qr);
    if(qr>=m+1 && u->rc) s += sum(u->rc,m+1,cr,ql,qr);
    return s;
  }
}st;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), v[i-1]=a[i];
  sort(v,v+n); int tail = unique(v,v+n)-v;
  st.n = tail;
  FORR(i,1,n){
    a[i] = lower_bound(v,v+tail,a[i])-v+1;
    st.add(i,a[i]);
  }

  int l,r,k;
  while(m--){
    scanf("%d%d%d",&l,&r,&k);
    printf("%d\n",v[st.query(l-1,r,k)-1]);
  }

  return 0;
}
















/*
const int MAX = 2e5 + 20;
int n,m,a[MAX],v[MAX];

struct HJT{
  int n,v[MAX];
  struct Node{
    int s;
    Node *lc, *rc;
    Node() { s=0, lc=rc=0; }
  }*node[MAX<<2], *root[MAX];
  int tail;

  void add(int p, int v){
    root[++tail] = add(1,1,n,p,v);
  }
  void pushup(Node *u){
    if(u->lc) u->s += u->lc->s;
    if(u->rc) u->s += u->rc->s;
  }

  Node *add(int u, int cl, int cr, int p, int addVal){
    Node *t = new Node; node[u] = t;
    if(cl==cr){
      v[cl] += addVal;
      t->s = v[cl];
      t->lc = t->rc = 0;
      return t;
    }
    int m = (cl+cr)>>1;
    if(p<=m){
      t->lc = add(u<<1,cl,m,p,addVal);
      t->rc = node[u<<1|1];
    }else{
      t->lc = node[u<<1];
      t->rc = add(u<<1|1,m+1,cr,p,addVal);
    }
    pushup(t);
    return t;
  }

  int sum(int id, int l, int r){
    return root[id] ? sum(root[id],1,n,l,r) : 0;
  }

  int sum(Node *u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr) return u->s;
    int m = (cl+cr)>>1,s=0;
    if(ql<=m && u->lc) s = sum(u->lc,cl,m,ql,qr);
    if(qr>=m+1 && u->rc) s += sum(u->rc,m+1,cr,ql,qr);
    return s;
  }
}st;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), v[i-1]=a[i];
  int tail = n;
  sort(v,v+tail); tail = unique(v,v+tail) - v;

  st.n = tail; st.tail=0;

  FORR(i,1,n){
    int idx = lower_bound(v,v+tail,a[i]) - v + 1;
    st.add(idx,1);
  }


  int l,r,k;
  while(m--){
    scanf("%d%d%d",&l,&r,&k);
    int vl=1, vr=tail+1;
    while(vl<vr){
      int m = (vl+vr)>>1;
      int s = st.sum(r,1,m) - st.sum(l-1,1,m);
      if(s>=k) vr = m;
      else vl = m+1;
    }
    printf("%d\n",v[vl-1]);
  }

  return 0;
}
*/

/*
const int MAX = 2e5 + 20;
int n,m,a[MAX];
map<int,int> mp;

struct HJT{
  int n,v[MAX];
  struct Node{
    int s;
    Node *lc, *rc;
    Node() { s=0, lc=rc=0; }
  }*node[MAX<<2], *root[MAX];
  int tail;

  void add(int p, int v){
    root[++tail] = add(1,1,n,p,v);
  }
  void pushup(Node *u){
    if(u->lc) u->s += u->lc->s;
    if(u->rc) u->s += u->rc->s;
  }

  Node *add(int u, int cl, int cr, int p, int addVal){
    Node *t = new Node;
    node[u] = t;
    if(cl==cr){
      v[cl] += addVal;
      t->s = v[cl];
      t->lc = t->rc = 0;
      return t;
    }
    int m = (cl+cr)>>1;
    if(p<=m){
      t->lc = add(u<<1,cl,m,p,addVal);
      t->rc = node[u<<1|1];
    }else{
      t->lc = node[u<<1];
      t->rc = add(u<<1|1,m+1,cr,p,addVal);
    }
    pushup(t);
    return t;
  }

  int sum(int id, int l, int r){
    return root[id] ? sum(root[id],1,n,l,r) : 0;
  }

  int sum(Node *u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr) return u->s;
    int m = (cl+cr)>>1,s=0;
    if(ql<=m && u->lc) s = sum(u->lc,cl,m,ql,qr);
    if(qr>=m+1 && u->rc) s += sum(u->rc,m+1,cr,ql,qr);
    return s;
  }
}st;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), mp[a[i]]=0;
  int tail = 0;
  // for(auto &p : mp) p.SE = ++tail;
  for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
    it->SE = ++tail;
  st.n = tail; st.tail=0;

  FORR(i,1,n) st.add(mp[a[i]],1);
  // for(auto p : mp) a[p.SE] = p.FI;
  for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it)
    a[it->SE] = it->FI;

  int l,r,k;
  while(m--){
    scanf("%d%d%d",&l,&r,&k);
    int vl=1, vr=tail+1;
    while(vl<vr){
      int m = (vl+vr)>>1;
      int s = st.sum(r,1,m) - st.sum(l-1,1,m);
      if(s>=k) vr = m;
      else vl = m+1;
    }
    printf("%d\n",a[vl]);
  }

  return 0;
}
*/
