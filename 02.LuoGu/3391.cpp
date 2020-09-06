// Tag: splay
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
int n,m,a[MAX],l,r;

struct Splay{
  struct Node{
    int v,siz;
    Node *ch[2], *fa, **root;
    bool reverse, bound;

    Node(int v, Node *fa, Node **root) : v(v), siz(1), fa(fa), root(root), reverse(false), bound(false) {
      ch[0] = ch[1] = nullptr;
    }

    int relation() { return this == fa->ch[1]; }
    int lsize() { return ch[0] ? ch[0]->siz : 0; }
    int rsize() { return ch[1] ? ch[1]->siz : 0; }
    void maintain(){
      siz = lsize() + rsize() + 1;
    }

    Node* pushdown(){
      if(reverse){
        swap(ch[0], ch[1]);
        if(ch[0]) ch[0]->reverse ^= 1;
        if(ch[1]) ch[1]->reverse ^= 1;
        reverse = 0;
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

    /*
    Node *splay(Node **tgt = nullptr){
      if(!tgt) tgt = root;
      while(this != *tgt){
        fa->pushdown();
        if(fa == *tgt) rotate();
        else if(relation() == fa->relation()) fa->rotate(), rotate();
        else rotate(), rotate();
      }
      return this;
    }
    */
    Node *splay(Node *tgt = nullptr){
      while(fa != tgt){
        if(fa->pushdown()->fa == tgt) rotate();
        else if(relation() == fa->relation()) fa->rotate(), rotate();
        else rotate(), rotate();
      }
      return this;
    }
  }*root;

  void build(int *a, int n){
    root = build(a, 1, n, nullptr);

    Node **lb = &root, *p = nullptr;
    while(*lb){
      p = *lb; p->siz ++;
      lb = &p->ch[0];
    }
    *lb = new Node(0, p, &root); (*lb)->bound = true;

    Node **rb = &root; p = nullptr;
    while(*rb){
      p = *rb; p->siz ++;
      rb = &p->ch[1];
    }
    *rb = new Node(0, p, &root); (*rb)->bound = true;
  }
  Node *build(int *a, int l, int r, Node *fa){
    if(l > r) return nullptr;
    int m = (l+r)/2;
    Node *p = new Node(a[m], fa, &root);
#ifdef DEBUG
    printf("  a[%d]: %d\n",m,a[m]);
#endif
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
    Node *lb = select(l-1), *rb = select(r+1);
    lb->splay();
    rb->splay(lb);
    return rb->ch[0];
  }
  void reverse(int l, int r){
    select(l, r)->reverse ^= 1;
  }
  void fetch(int *a) { dfs(root, a); }
  void dfs(Node *u, int *&a){
    if(!u) return;
    u->pushdown();
    dfs(u->ch[0], a);
    if(!u->bound) *a++ = u->v;
    dfs(u->ch[1], a);
  }
}sp;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) a[i] = i;
  sp.build(a, n);
  while(m--){
    scanf("%d%d",&l,&r);
    sp.reverse(l,r);
  }
  sp.fetch(a+1);
  FORR(i,1,n) printf("%d ",a[i]); putchar('\n');

  return 0;
}
