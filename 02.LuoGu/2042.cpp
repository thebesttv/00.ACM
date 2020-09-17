// Tag: 序列Splay ii
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
#include<cassert>
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
const int MAX = 500020;
int n, m, a[MAX]; char op[20];

int read(){
  int x=0,f=1, ch=getchar();
  while (ch<'0' || ch>'9'){if (ch=='-')f=-1;ch=getchar();}
  while ('0'<=ch && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
  return x*f;
}

struct Node;

struct Pool{
  queue<Node*> q;
  void init();
  void ret(Node *p) { q.push(p); }
  Node *get(int v, Node *fa, Node **root);
}pl;

struct Node{
  int v,sum,msl,msr,msm,siz,len;
  Node *ch[2], *fa, **root;
  bool reverse, bound; int set;
  // 左右区间：[l, m-1], [m+1, r]

  Node() { }
  Node(int v, Node *fa, Node **root)
    : v(v), sum(v), msl(v), msr(v), msm(v), siz(1), len(1),
    fa(fa), root(root), reverse(false), bound(false), set(INT_MIN) {
      ch[0] = ch[1] = nullptr;
    }

  int relation() { return this == fa->ch[1]; }
  int lsize() { return ch[0] ? ch[0]->siz : 0; }
  int rsize() { return ch[1] ? ch[1]->siz : 0; }

  void maintain(){
    if(ch[0] && ch[1]){
      ch[0]->pushdown(), ch[1]->pushdown();
      sum = ch[0]->sum + v + ch[1]->sum;
      msl = max(ch[0]->msl, ch[0]->sum + v + max(ch[1]->msl, 0));
      msr = max(ch[1]->msr, ch[1]->sum + v + max(ch[0]->msr, 0));
      msm = max(max(ch[0]->msr, 0) + v + max(ch[1]->msl, 0),
          max(ch[0]->msm, ch[1]->msm));
      siz = ch[0]->siz + 1 + ch[1]->siz;
      len = ch[0]->len + (bound==0) + ch[1]->len;
    }else if(ch[0]){
      ch[0]->pushdown();
      sum = ch[0]->sum + v;
      msl = max(ch[0]->msl, ch[0]->sum + v);
      msr = v + max(ch[0]->msr, 0);
      msm = max(max(ch[0]->msr, 0) + v, ch[0]->msm);
      siz = ch[0]->siz + 1;
      len = ch[0]->len + (bound==0);
    }else if(ch[1]){
      ch[1]->pushdown();
      sum = v + ch[1]->sum;
      msl = v + max(ch[1]->msl, 0);
      msr = max(ch[1]->msr, ch[1]->sum + v);
      msm = max(max(ch[1]->msl, 0) + v, ch[1]->msm);
      siz = 1 + ch[1]->siz;
      len = (bound==0) + ch[1]->len;
    }else{
      sum = msl = msr = msm = v;
      siz = 1;
      len = (bound==0);
    }
  }

  Node *pushdown(){
    if(bound) return this;

    if(reverse){
      swap(ch[0], ch[1]); swap(msl, msr);
      if(ch[0]) ch[0]->reverse ^= 1;
      if(ch[1]) ch[1]->reverse ^= 1;
      reverse = 0;
    }
    if(set != INT_MIN){
#ifdef DEBUG
      printf("  set: %d, len: %d\n",set,len);
#endif
      v = set; sum = len * v;
      if(v >= 0) msl = msm = msr = sum;
      else msl = msm = msr = v;
      if(ch[0]) ch[0]->set = set;
      if(ch[1]) ch[1]->set = set;
      set = INT_MIN;
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
};

void recycle(Node *p){
  if(p->ch[0]) recycle(p->ch[0]);
  if(p->ch[1]) recycle(p->ch[1]);
  pl.ret(p);
}

struct Splay{
  Node *root;

  Splay() : root(nullptr) { }

  void build(int *a, int n){
    root = build(a, 1, n, nullptr);
    Node **lb = &root, *p = nullptr;
    while(*lb){
      p = *lb; p->siz ++;
      lb = &p->ch[0];
    }
    //*lb = new Node(-INF, p, &root);
    *lb = pl.get(-INF, p, &root);
    (*lb)->sum = (*lb)->len = 0; (*lb)->bound = true;

    Node **rb = &root; p = nullptr;
    while(*rb){
      p = *rb; p->siz ++;
      rb = &p->ch[1];
    }
    //*rb = new Node(-INF, p, &root);
    *rb = pl.get(-INF, p, &root);
    (*rb)->sum = (*rb)->len = 0; (*rb)->bound = true;
  }

  Node *build(int *a, int l, int r, Node *fa){
    if(l > r) return nullptr;
    int m = (l+r)/2;
    //Node *p = new Node(a[m],fa,&root);
    Node *p = pl.get(a[m], fa, &root);
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
    lb->splay(), rb->splay(lb);
    return rb->ch[0];
  }
  Node *select2(int l, int r){
    Node *lb = select(l-1), *rb = select(r+1);
    lb->splay(), rb->splay(lb);
    return rb;
  }

  void insert(int x, int *a, int n){  // 在 x 之后插入
    Node *fa = select2(x+1, x);
    Node *p = build(a, 1, n, fa);
    fa->ch[0] = p;
    fa->maintain(), fa->fa->maintain();
  }

  void reverse(int l, int r){
    Node *p = select(l, r);
    p->reverse = 1; p->pushdown();
    p->fa->maintain();
    p->fa->fa->maintain();
  }

  void erase(int l, int r){
    Node *p = select2(l, r);
    recycle(p->ch[0]);
    p->ch[0] = nullptr;
    p->maintain(), p->fa->maintain();
  }

  void set(int l, int r, int v){
    Node *p = select(l, r);
    p->set = v; p->pushdown();
    p->fa->maintain();
    p->fa->fa->maintain();
  }

  int sum(int l, int r){
    return select(l, r)->sum;
  }
  int maxsum(){
    Node *p = select(1, root->siz - 2);
    return max(p->msm, max(p->msl, p->msr));
  }

  void fetch(int *a, int &n){
    n = root->siz - 2; dfs(root, a);
  }
  void dfs(Node *u, int *&a){
    if(!u) return;
    u->pushdown();
    dfs(u->ch[0], a);
    if(!u->bound) *a++ = u->v;
    dfs(u->ch[1], a);
  }
}sp;

void print(){
  int n; sp.fetch(a,n);
  FOR(i,0,n) printf("%d ",a[i]); putchar('\n');
}


Node pool[MAX];
void Pool::init(){
  FOR(i,0,MAX) q.push(pool + i);
#ifdef DEBUG
  printf("inserted %d\n",MAX);
#endif
}

Node *Pool::get(int v, Node *fa, Node **root){
  if(q.empty()) { printf("WRONG\n"); fflush(stdout); exit(1); }
  Node *p = q.front(); q.pop();
  *p = Node(v, fa, root);
  return p;
}

int main(void){
  pl.init();
  n = read(), m = read();
  FORR(i,1,n) a[i] = read();
  sp.build(a,n);
  while(m--){
    int p, t, v; scanf("%s",op);
    if(op[0] == 'M' && op[2] == 'X'){ // MAX-SUM
      printf("%d\n",sp.maxsum());
    }else{
      p = read(), t = read();
      if(op[0] == 'I'){ // INSERT
        if(!t) continue;
        FORR(i,1,t) a[i] = read();
        sp.insert(p,a,t);
      }else if(op[0] == 'D'){ // DELETE
        if(!t) continue;
        sp.erase(p, p+t-1);
      }else if(op[0] == 'M' && op[2] == 'K'){ // MAKE-SAME
        v = read();
        if(!t) continue;
        sp.set(p, p+t-1, v);
      }else if(op[0] == 'R'){ // REVERSE
        sp.reverse(p, p+t-1);
      }else{ // GET-SUM
        printf("%d\n", !t ? 0 : sp.sum(p,p+t-1));
      }
    }
#ifdef DEBUG
    //printf("%s: ",op); print();
#endif
  }

  return 0;
}
