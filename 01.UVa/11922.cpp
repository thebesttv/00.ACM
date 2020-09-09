// Tag: 序列splay
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

const int INF = 0x3f3f3f3f;

struct Splay{
  struct Node{
    int v, siz;
    Node *ch[2], *fa, **root;
    bool reversed;

    Node(int v, Node *fa, Node **root)
      : v(v), siz(1), fa(fa), root(root), reversed(false) {
        ch[0] = ch[1] = nullptr;
      }

    int relation() { return this == fa->ch[1]; }
    int lsize() { return ch[0] ? ch[0]->siz : 0; }
    int rsize() { return ch[1] ? ch[1]->siz : 0; }
    void maintain(){
      siz = lsize() + rsize() + 1;
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
  }*root, *lb, *rb;

  Splay(){
    root = lb = new Node(INF, nullptr, &root);     // lb
    root->ch[1] = rb = new Node(INF, root, &root); // rb
    root->maintain();
  }

  void build(int n){
    pushback(build(1,n,nullptr));
  }

  Node *build(int l, int r, Node *fa){
    if(l > r) return nullptr;
    int m = (l+r)/2;
    Node *p = new Node(m, fa, &root);
    if(l < r){
      p->ch[0] = build(l, m-1, p);
      p->ch[1] = build(m+1, r, p);
      p->maintain();
    }
    return p;
  }

  void pushback(Node *p){
    rb->pred();
    rb->ch[0] = p;
    p->fa = rb;
    rb->maintain();
    root->maintain();
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

  int rank(Node *p){
    return p->lsize();
  }

  void reverse(int l, int r){
    select(l, r)->reversed ^= 1;
  }

  void operate(int l, int r){
    Node *p = select(l, r);
    p->reversed ^= 1;
    p->fa->ch[0] = nullptr;
    p->fa->maintain();
    root->maintain();
    pushback(p);
  }

  void fetch(int *a){
    dfs(root, a);
  }
  void dfs(Node *u, int *&a){
    if(!u) return;
    u->pushdown();
    dfs(u->ch[0], a);
    if(u->v != INF) *a++ = u->v;
    dfs(u->ch[1], a);
  }
}sp;

const int MAX = 100020;
int n,m,a[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  sp.build(n); int l,r;
  while(m--){
    scanf("%d%d",&l,&r);
    sp.operate(l,r);
#ifdef DEBUG
    sp.fetch(a);
    FOR(i,0,n) printf("%d ",a[i]); putchar('\n');
#endif
  }
  sp.fetch(a);
  FOR(i,0,n) printf("%d\n",a[i]);

  return 0;
}
