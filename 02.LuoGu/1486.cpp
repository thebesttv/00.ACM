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

struct Splay{
  struct Node{
    LL v; int siz,cnt;
    Node *ch[2], *fa, **root;

    Node(LL v, Node *fa, Node **root)
      : v(v), siz(1), cnt(1), fa(fa), root(root) {
        ch[0] = ch[1] = nullptr;
      }
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

    Node *splay(Node *tgt = nullptr){
      while(fa != tgt){
        if(fa->fa == tgt) rotate();
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
  } *root, *lb;

  Splay() : root(nullptr) {
    lb = insert(LLONG_MIN);
    insert(LLONG_MAX);
  }

  Node *find(int v){
    Node *p = root;
    while(p && p->v != v){
      if(v < p->v) p = p->ch[0];
      else p = p->ch[1];
    }
    return p ? p->splay() : nullptr;
  }

  Node *insert(LL v){
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

  Node *select(int k){
    ++k; Node *p = root;
    while(k < p->lsize() + 1 || k > p->lsize() + p->cnt){
      if(k < p->lsize() + 1) p = p->ch[0];
      else k -= p->lsize() + p->cnt, p = p->ch[1];
    }
    return p->splay();
  }

  int erase(LL k){
    Node *p = insert(k)->succ();
    lb->splay();
    p->splay(lb);
    int ans = p->lsize() - 1;
    delete p->ch[0];
    p->ch[0] = nullptr;
    p->maintain();
    lb->maintain();
#ifdef DEBUG
    printf("erase %lld: %d\n",k,ans);
#endif
    return ans;
  }

  int fetch(LL *a){
    return dfs(root, a);
  }
  int dfs(Node *u, LL *&a){
    if(!u) return 0;
    int sum = 0;
    sum += dfs(u->ch[0], a);
    if(u->v != LLONG_MIN && u->v != LLONG_MAX)
      FOR(i,0,u->cnt) *a++ = u->v, ++sum;
    sum += dfs(u->ch[1], a);
    return sum;
  }
}sp;

int n; LL m, delta;

int main(void){
  scanf("%d%lld",&n,&m);
  int op, sum = 0; LL x;
  while(n--){
    do op = getchar(); while(!isalpha(op));
    scanf("%lld",&x);
    if(op == 'I'){
      if(x < m) continue;
      sp.insert(x + delta);
    }else if(op == 'A'){
      delta -= x;
    }else if(op == 'S'){
      delta += x;
      sum += sp.erase(m + delta - 1);  // erase all that's smaller than k + delta
    }else{
      int siz = sp.root->siz - 2;
      printf("%lld\n", x > siz ? -1 : sp.select(siz - x + 1)->v - delta);
    }
#ifdef DEBUG
    LL a[1024]; int n = sp.fetch(a);
    FOR(i,0,n) printf(" %lld",a[i]); putchar('\n');
#endif
  }
  printf("%d\n", sum);

  return 0;
}
