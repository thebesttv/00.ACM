// Tag: 序列splay i
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

const int MAX = 100020;
const int INF = 0x3f3f3f3f;
int n,a[MAX];

struct Splay{
  struct Node{
    pii v,m; int siz;
    Node *ch[2], *fa, **root;
    bool reversed;

    Node(pii v, Node *fa, Node **root)
      : v(v), m(v), siz(1), fa(fa), root(root), reversed(false) {
        ch[0] = ch[1] = nullptr;
      }

    int relation() { return this == fa->ch[1]; }
    int lsize() { return ch[0] ? ch[0]->siz : 0; }
    int rsize() { return ch[1] ? ch[1]->siz : 0; }
    void maintain(){
      siz = lsize() + rsize() + 1;
      m = min(v, min(ch[0] ? ch[0]->m : v, ch[1] ? ch[1]->m : v));
    }

    Node* pushdown(){
      if(reversed){
        swap(ch[0], ch[1]);
        if(ch[0]) ch[0]->reversed ^= 1;
        if(ch[1]) ch[1]->reversed ^= 1;
        reversed = 0;
      }
      return this;
    }
    void rotate(){
      fa->pushdown(); pushdown();
      Node *p = fa; int x = relation();

      if(p->fa) p->fa->ch[p->relation()] = this;
      fa = p->fa;

      p->ch[x] = ch[x^1];
      if(ch[x^1]) ch[x^1]->fa = p;

      ch[x^1] = p;
      p->fa = this;

      p->maintain(); maintain();

      if(!fa) *root = this;
    }

    Node *splay(Node *tgt = nullptr){
      while(fa != tgt){
        if(fa->pushdown()->fa == tgt) rotate();
        else if(relation() == fa->relation()) fa->rotate(), rotate();
        else rotate(), rotate();
      }
      return this;
    }

    Node *pred(){
      Node *p = splay()->pushdown()->ch[0];
      while(p->pushdown()->ch[1]) p = p->ch[1];
      return p->splay();
    }
    Node *succ(){
      Node *p = splay()->pushdown()->ch[1];
      while(p->pushdown()->ch[0]) p = p->ch[0];
      return p->splay();
    }
  }*root;

  Splay(){
    pii inf{INF,INF};
    root = new Node(inf, nullptr, &root);     // lb
    root->ch[1] = new Node(inf, root, &root); // rb
    root->maintain();
  }

  Node *build(int *a, int l, int r, Node *fa){
    if(l > r) return nullptr;
    int m = (l+r)/2;
    Node *p = new Node({a[m],m}, fa, &root);
    if(l < r){
      p->ch[0] = build(a, l, m-1, p);
      p->ch[1] = build(a, m+1, r, p);
      p->maintain();
    }
    return p;
  }

  Node *select(int k){
    ++k; Node *p = root;
    while(p->pushdown()->lsize() + 1 != k){
      if(k < p->lsize() + 1) p = p->ch[0];
      else k -= p->lsize() + 1, p = p->ch[1];
    }
    return p->splay();
  }
  Node *select(int l, int r){
    Node *lp = select(l-1),
         *rp = select(r+1);
    lp->splay();
    rp->splay(lp);
    return rp->ch[0];
  }

  Node *find(pii v){
    Node *p = root;
    while(p->v != v){
      if(p->ch[0] && p->ch[0]->m == v) p = p->ch[0];
      else p = p->ch[1];
    }
    return p->splay();
  }
  int rank(Node *p){
    return p->lsize();
  }

  void insert(int *a, int n){
    Node *l = root, *r = root->succ();
    l->splay(), r->splay(l);
    Node *p = build(a, 1, n, r);
    r->ch[0] = p;
    r->maintain(); l->maintain();
  }

  void reverse(int l, int r){
    select(l, r)->reversed ^= 1;
  }

  void fetch(pii *a){
    dfs(root, a);
  }
  void dfs(Node *u, pii *&a){
    if(!u) return;
    u->pushdown();
#ifdef DEBUG
    printf("  node {%d, %d}, m: {%d, %d}, siz: %d\n", u->v.FI,u->v.SE,u->m.FI,u->m.SE,u->siz);
#endif
    dfs(u->ch[0], a);
    if(u->v.FI != INF) *a++ = u->v;
    dfs(u->ch[1], a);
  }

  int qMin(int l, int r){
    return rank(find(select(l,r)->m));
  }
}sp;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  sp.insert(a,n);
#ifdef DEBUG
  pii v[MAX]; sp.fetch(v);
  FOR(i,0,n) printf("{%d, %d}, ",v[i].FI,v[i].SE); putchar('\n');
#endif
  FORR(i,1,n){
    int idx = sp.qMin(i, n);
    printf("%d ",idx); fflush(stdout);
    sp.reverse(i,idx);
#ifdef DEBUG
    pii v[MAX]; sp.fetch(v);
    FOR(i,0,n) printf("{%d, %d}, ",v[i].FI,v[i].SE); putchar('\n');
#endif
  }
  putchar('\n');

  return 0;
}
