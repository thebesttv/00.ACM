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

int read(){
  int ch, s = 0;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

struct Splay{
  struct Node{
    int v,cnt,siz;
    Node *ch[2], *fa, **root;

    Node(int v, Node *fa, Node **root)
      : v(v), cnt(1), siz(1), fa(fa), root(root) { ch[0] = ch[1] = nullptr; }
    ~Node(){
      if(ch[0]) delete ch[0];
      if(ch[1]) delete ch[1];
    }

    int relation() { return this == fa->ch[1]; }
    int lsize() { return ch[0] ? ch[0]->siz : 0; }
    int rsize() { return ch[1] ? ch[1]->siz : 0; }

    void maintain() { siz = lsize() + rsize() + cnt; }

    void rotate(){
      Node *p = fa;
      int x = relation();

      if(p->fa) p->fa->ch[p->relation()] = this;
      fa = p->fa;

      p->ch[x] = ch[x^1];
      if(ch[x^1]) ch[x^1]->fa = p;

      ch[x^1] = p;
      p->fa = this;

      p->maintain();
      maintain();

      if(!fa) *root = this;
    }

    Node *splay(Node **tgt = nullptr){
      if(!tgt) tgt = root;
      while(this != *tgt){
        if(fa == *tgt) rotate();
        else if(relation() == fa->relation()) fa->rotate(), rotate();
        else rotate(), rotate();
      }
      return this;
    }

    Node *pred(){
      Node *p = splay()->ch[0];
      while(p->ch[1]) p = p->ch[1];
      return p->splay();
    }
    Node *succ(){
      Node *p = splay()->ch[1];
      while(p->ch[0]) p = p->ch[0];
      return p->splay();
    }
  } *root;

  Splay() : root(nullptr) {
    insert(INT_MIN);
    insert(INT_MAX);
  }

  Node *find(int v){
    Node *p = root;
    while(p && p->v != v){
      if(v < p->v) p = p->ch[0];
      else p = p->ch[1];
    }
    return p ? p->splay() : nullptr;
  }

  Node *insert(int v){
    Node **p = &root, *fa = nullptr;
    while(*p && (*p)->v != v){
      fa = *p; fa->siz++;
      if(v < (*p)->v) p = &(*p)->ch[0];
      else p = &(*p)->ch[1];
    }

    if(*p) (*p)->cnt++, (*p)->siz++;
    else *p = new Node(v, fa, &root);

    return (*p)->splay();
  }

  int pred(int v){
    Node *p = find(v);
    if(p) return p->pred()->v;
    p = insert(v);
    int res = p->pred()->v;
    erase_one(p);
    return res;
  }
  int succ(int v){
    Node *p = find(v);
    if(p) return p->succ()->v;
    p = insert(v);
    int res = p->succ()->v;
    erase_one(p);
    return res;
  }

  void erase_one(int v) { erase_one(find(v)); }

  void erase_one(Node *p){
    Node *pred = p->pred();
    Node *succ = p->succ();

    pred->splay();
    succ->splay(&pred->ch[1]);

    --p->cnt, --p->siz;
    if(p->cnt == 0) succ->ch[0] = nullptr;

    succ->maintain();
    pred->maintain();
  }

  int select(int k){
    ++k; Node *p = root;
    while(!(p->lsize() + 1 <= k && k <= p->lsize() + p->cnt)){
      if(p->lsize() + 1 > k) p = p->ch[0];
      else k -= p->lsize() + p->cnt, p = p->ch[1];
    }
    return p->splay()->v;
  }

  int rank(int v){
    Node *p = find(v);
    if(p) return p->lsize();
    p = insert(v);
    int res = p->lsize();
    erase_one(p);
    return res;
  }
}sp;

int main(void){
  int n = read(), m = read(), opt, x;
  while(n--) sp.insert(read());

  int ans = 0, last = 0;
  while(m--){
    opt = read(), x = read() ^ last;
#ifdef DEBUG
    printf("%d, %d\n",opt,x);
#endif
    if(opt == 1) sp.insert(x);
    else if(opt == 2) sp.erase_one(x);
    else if(opt == 3) ans ^= (last = sp.rank(x));
    else if(opt == 4) ans ^= (last = sp.select(x));
    else if(opt == 5) ans ^= (last = sp.pred(x));
    else ans ^= (last = sp.succ(x));
  }
  printf("%d\n",ans);

  return 0;
}
