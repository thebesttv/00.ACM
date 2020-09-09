// Tag: 集合splay
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

struct Splay{
  struct Node{
    int v,siz;
    Node *lc, *rc, *fa, **root;
    Node (int v, Node *fa, Node **root)
      : v(v), siz(1), lc(nullptr), rc(nullptr), fa(fa), root(root) { }

    Node *grandfa(){
      return !fa ? nullptr : fa->fa;
    }
    Node *&child(int x){
      return !x ? lc : rc;
    }
    int relation(){
      return this == fa->lc ? 0 : 1;
    }
    int lsize(){
      return lc ? lc->siz : 0;
    }
    int rsize(){
      return rc ? rc->siz : 0;
    }
    void maintain(){
      siz = lsize() + rsize() + 1;
    }
    void rotate(){
      Node *p = fa;
      int x = relation();

      if(grandfa()) grandfa()->child(p->relation()) = this;
      fa = grandfa();

      p->child(x) = child(x^1);
      if(child(x^1)) child(x^1)->fa = p;

      child(x^1) = p;
      p->fa = this;

      p->maintain();
      maintain();

      if(!fa) *root = this;
    }
    Node *splay(Node **tgt = nullptr){
      if(!tgt) tgt = root;
      while(this != *tgt){
        if(fa == *tgt) rotate();
        else if(relation() == fa->relation())
          fa->rotate(), rotate();
        else
          rotate(), rotate();
      }
      return *tgt;
    }

    Node *pred(){
      Node *p = this;
      while(p->v == v){
        p->splay(); p = p->lc;
        while(p->rc) p = p->rc;
      }
      return p->splay();
    }

    Node *succ(){
      Node *p = this;
      while(p->v == v){
        p->splay(); p = p->rc;
        while(p->lc) p = p->lc;
      }
      return p->splay();
    }
  } *root;

  Splay() : root(nullptr) {
    insert(INT_MIN);
    insert(INT_MAX);
  }

  Node *insert(int v){
    Node **tgt = &root, *fa = nullptr;
    while(*tgt){
      fa = *tgt; fa->siz++;
      if(v < (*tgt)->v) tgt = &(*tgt)->lc;
      else tgt = &(*tgt)->rc;
    }
    *tgt = new Node(v, fa, &root);
    return (*tgt)->splay();
  }

  Node *find(int v){
    Node *p = root;
    while(p && p->v != v){
      if(v < p->v) p = p->lc;
      else p = p->rc;
    }
    return p ? p->pred()->succ()->splay() : nullptr;
  }

  int rank(int v){
    return find(v)->lsize();
  }

  int select(int k){
    ++k; Node *p = root;
    while(p->lsize() + 1 != k){
      if(p->lsize() + 1 > k) p = p->lc;
      else k -= p->lsize() + 1, p = p->rc;
    }
    return p->splay()->v;
  }

  void erase_one(int v){
    Node *p = find(v);
    Node *pred = p->lc;
    while(pred->rc) pred = pred->rc;
    Node *succ = p->rc;
    while(succ->lc) succ = succ->lc;

    pred->splay();
    succ->splay(&pred->rc);

    succ->lc = nullptr;

    succ->maintain();
    pred->maintain();
  }

  void erase(int v) { erase(find(v)); }
  void erase(int l, int r) { erase(find(l), find(r)); }
  void erase(Node *l, Node *r = nullptr){
    if(!r) r = l;
    Node *pred = l->pred(),
         *succ = r->succ();
    pred->splay();
    succ->splay(&pred->rc);

    succ->lc = nullptr;

    succ->maintain();
    pred->maintain();
  }

  int pred(int v){
    Node *p = find(v);
    if(p) return p->pred()->v;
    p = insert(v);
    int res = p->pred()->v;
    erase(p);
    return res;
  }
  int succ(int v){
    Node *p = find(v);
    if(p) return p->succ()->v;
    p = insert(v);
    int res = p->succ()->v;
    erase(p);
    return res;
  }
}sp;

int main(void){
  int n,opt,x; scanf("%d",&n);
  while(n--){
    scanf("%d%d",&opt,&x);
    if(opt == 1) sp.insert(x);
    else if(opt == 2) sp.erase_one(x);
    else if(opt == 3) printf("%d\n",sp.rank(x));
    else if(opt == 4) printf("%d\n",sp.select(x));
    else if(opt == 5) printf("%d\n",sp.pred(x));
    else printf("%d\n",sp.succ(x));
  }

  return 0;
}
