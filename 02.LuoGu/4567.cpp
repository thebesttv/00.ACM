// Tag: 序列splay 坑
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

const int MAX = 2 * (1<<20);
int n; char s[MAX];

struct Splay{
  struct Node{
    char v; int siz;
    Node *ch[2], *fa, **root;
    bool reversed;

    Node(char v, Node *fa, Node **root)
      : v(v), siz(1), fa(fa), root(root), reversed(false) {
        ch[0] = ch[1] = nullptr;
      }

    int relation() { return this == fa->ch[1]; }
    int lsize() { return ch[0] ? ch[0]->siz : 0; }
    int rsize() { return ch[1] ? ch[1]->siz : 0; }
    void maintain() { siz = lsize() + rsize() + 1; }

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
    root = new Node(0, nullptr, &root);     // lb
    root->ch[1] = new Node(0, root, &root); // rb
  }

  Node *build(char *s, int l, int r, Node *fa){
    if(l > r) return nullptr;
    int m = (l+r)/2;
    Node *p = new Node(s[m], fa, &root);
    if(l < r){
      p->ch[0] = build(s, l, m-1, p);
      p->ch[1] = build(s, m+1, r, p);
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
  Node *select_next_k(int k){ // range select, return right bound
    ++k; Node *p = root->ch[1];
    while(p->pushdown()->lsize() + 1 != k){
      if(k < p->lsize() + 1) p = p->ch[0];
      else k -= p->lsize() + 1, p = p->ch[1];
    }
    return p->splay(root);
  }

  void move(int k) { select(k); }

  void insert(char *s, int n){
    Node *fa = select_next_k(0);
    Node *p = build(s, 1, n, fa);
    fa->ch[0] = p;
  }

  void erase(int n){
    select_next_k(n)->ch[0] = nullptr;
  }

  void rotate(int n){
    select_next_k(n)->ch[0]->reversed ^= 1;
  }

  char get(){
    Node *p = root->pushdown()->ch[1];
    while(p->pushdown()->ch[0]) p = p->ch[0];
    return p->v;
  }

  void mpred() { root->pred(); }
  void msucc() { root->succ(); }

  void fetch(char *s){
    dfs(root, s); *s = 0;
  }
  void dfs(Node *u, char *&s){
    if(!u) return;
    dfs(u->ch[0], s);
    if(u->v) *s++ = u->v;
    dfs(u->ch[1], s);
  }
}sp;

int main(void){
  scanf("%d",&n);
  int x; char op[20];
  while(n--){
    scanf("%s",op);
    switch(op[0]){
      case 'M':
        scanf("%d",&x); sp.move(x); break;
      case 'I':
        scanf("%d",&x); getchar();
        FGETS(s); sp.insert(s-1, x);
        break;
      case 'D':
        scanf("%d",&x); sp.erase(x);
        break;
      case 'R':
        scanf("%d",&x); sp.rotate(x);
        break;
      case 'G':
        x = sp.get();
        if(x != '\n') putchar(x);
        putchar('\n');
        break;
        //printf("%c\n",sp.get()); break;
      case 'P': 
        sp.mpred(); break;
      case 'N':
        sp.msucc(); break;
    }
#ifdef DEBUG
    sp.fetch(s);
    printf("(%c): %s\n",sp.get(),s);
#endif
  }

  return 0;
}
