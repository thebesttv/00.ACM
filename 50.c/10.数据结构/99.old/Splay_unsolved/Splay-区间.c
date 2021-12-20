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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100000;
int a[MAX],n,m;
struct Node{
  int v,siz; bool bound;  //是否为边界
  Node *ch[2],*fa,**root;
  bool reversed;

  Node(Node **root_, Node *fa_, int v_): root(root_), fa(fa_), v(v_), siz(1), bound(0), reversed(0){
    ch[0]=ch[1]=NULL;
  }
  int relation() {return this==fa->ch[1];}
  int size(int d) {return ch[d] ? ch[d]->siz : 0 ;}
  Node *pushDown(){
    if(reversed){
      swap(ch[0],ch[1]);
      if(ch[0]) ch[0]->reversed^=1;
      if(ch[1]) ch[1]->reversed^=1;
      reversed=0;
    }
    return this;
  }
  void maintain(){
    siz=1;
    if(ch[0]) siz+=ch[0]->siz;
    if(ch[1]) siz+=ch[1]->siz;
  }
  void rotate(){
    Node *p=fa->pushDown(); pushDown();
    int d=relation();

    //if(p->fa) p->fa->pushDown()->ch[p->relation()]=this;
    if(p->fa) p->fa->ch[p->relation()]=this;
    fa=p->fa;

    p->ch[d]=ch[d^1];
    if(ch[d^1]) ch[d^1]->fa=p;

    ch[d^1]=p;
    p->fa=this;

    p->maintain();
    maintain();

    if(!fa) *root=this;
  }
  Node *splay(Node **target=NULL){
    if(!target) target=root;
    while(this!=*target){
      fa->pushDown();
      if(fa==*target) rotate();
      else if(relation()==fa->relation()) fa->rotate(), rotate();
      else rotate(), rotate();
    }
    return this;
  }
};

struct Splay{
  Node *root;

  /*
  void build(int *a, int l, int r){
    build(root,NULL,a,l,r);

    Node **lbound=&root,*fa=NULL;
    while(*lbound){
      fa=*lbound; fa->siz++;
      lbound=&fa->ch[0];
    }
    *lbound = new Node(&root,fa,0);
    (*lbound)->siz=0; (*lbound)->bound=1;

    Node **rbound=&root; fa=NULL;
    while(*rbound){
      fa=*rbound; fa->siz++;
      rbound=&fa->ch[1];
    }
    *rbound = new Node(&root,fa,0);
    (*rbound)->siz=0; (*rbound)->bound=1;
  }
  void build(Node* &o, Node *fa, int *a, int l, int r){
    if(l>r) return;
    int m=(l+r)>>1;
    o = new Node(&root,fa,a[m]);
    if(l==r) return;
    build(o->ch[0],o,a,l,m-1);
    build(o->ch[1],0,a,m+1,r);
    o->maintain();
    return o;
  }
  */
  void build(int *a, int n){
    root=build(NULL,a,1,n);

    Node **lbound=&root,*fa=NULL;
    while(*lbound){
      fa=*lbound; fa->siz++;
      lbound=&fa->ch[0];
    }
    *lbound = new Node(&root,fa,0); (*lbound)->bound=1;

    Node **rbound=&root; fa=NULL;
    while(*rbound){
      fa=*rbound; fa->siz++;
      rbound=&fa->ch[1];
    }
    *rbound = new Node(&root,fa,0); (*rbound)->bound=1;
  }
  Node *build(Node *fa, int *a, int l, int r){
    if(l>r) return NULL;
    int m=(l+r)>>1;
    Node *p = new Node(&root,fa,a[m]);
    if(l<r){
      p->ch[0]=build(p,a,l,m-1);
      p->ch[1]=build(p,a,m+1,r);
      p->maintain();
    }
    return p;
  }
  Node *select(int k){  //寻找 rank 为 k 的节点
    k++; int t; Node *p=root;
    while((t=p->pushDown()->size(0)+1) != k){
      if(k<t) p=p->ch[0];
      else k-=t, p=p->ch[1];
    }
    return p->splay();
  }
  Node *select(int l, int r){ //选择 [l,r]
    Node *p=select(l-1),*s=select(r+1);
    p->splay(); s->splay(&p->ch[1]);
    return s->ch[0];
  }
  void reverse(int l, int r){
    Node *p=select(l,r);
    p->reversed^=1;
  }
  void fetch(int *a){
    dfs(root,a);
  }
  void dfs(Node *o, int* &a){
    o->pushDown();  //<b> </b>
    if(o->ch[0]) dfs(o->ch[0],a);
    //*(a++)=o->v;
    if(!o->bound) *(a++)=o->v;  //<b> </b>
    if(o->ch[1]) dfs(o->ch[1],a);
  }
}sp;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sp.build(a,n);
  int l,r;
  while(m--){
    scanf("%d%d",&l,&r); sp.reverse(l,r);
  }
  sp.fetch(a+1);
  FORR(i,1,n) printf("%d ",a[i]); printf("\n");

  return 0;
}
