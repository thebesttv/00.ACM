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

const int MAX=300020;
int n,m;

struct Node{
  Node *ch[2],*fa,*pfa;
  int v,sum;
  bool reversed;

  Node(int v_): v(v_), sum(v_), reversed(0) {
    ch[0]=ch[1]=fa=pfa=NULL;
  }
  int relation(){
    return this==fa->ch[1];
  }
  void maintain(){
    sum = v ^ (ch[0] ? ch[0]->sum : 0) ^ (ch[1] ? ch[1]->sum : 0 );
  }
  void pushDown(){
    if(reversed){
      swap(ch[0],ch[1]);
      if(ch[0]) ch[0]->reversed^=1;
      if(ch[1]) ch[1]->reversed^=1;
      reversed=0;
    }
  }
  void rotate(){
    fa->pushDown(); pushDown();
    Node *p=fa; int d=relation();

    swap(pfa,p->pfa);

    fa=p->fa;
    if(p->fa) p->fa->ch[p->relation()]=this;

    p->ch[d]=ch[d^1];
    if(ch[d^1]) ch[d^1]->fa=p;

    ch[d^1]=p;
    p->fa=this;

    p->maintain();
    maintain();
  }
  void splay(){
    while(fa){
      if(!fa->fa) rotate();
      else{
        fa->fa->pushDown(); fa->pushDown(); //<b> </b>
        if(relation()==fa->relation()) fa->rotate(), rotate();
        else rotate(), rotate();
      }
    }
  }
  void expose(){
    splay(); pushDown();  //<b> </b>
    if(ch[1]){
      ch[1]->pfa=this;
      ch[1]->fa=NULL;
      ch[1]=NULL;
      maintain();
    }
  }
  bool splice(){
    splay();
    if(!pfa) return false;

    pfa->expose();  // pfa 已在 Splay 根
    pfa->ch[1]=this;
    fa=pfa; pfa=NULL;
    fa->maintain();
    maintain();
    return true;
  }
  void access(){
    expose();
    while(splice());
  }
  void evert(){
    access();
    splay();
    reversed^=1;
  }
  Node *findRoot(){
    Node *p=this;
    while(p->fa || p->pfa)
      p = p->fa ? p->fa : p->pfa;
    p->splay();
    return p;
  }
};

struct LCT{
  Node *node[MAX];

  void makeTree(int u, int v){
    node[u] = new Node(v);
  }
  void link(int u, int v){  //<b> </b>
    node[v]->evert();
    node[v]->pfa=node[u];
  }
  void cut(int u, int v){
    node[u]->evert();
    node[v]->access();
    node[v]->splay();
    node[v]->pushDown();
    if(node[v]->ch[0]==node[u]){
      node[u]->fa=NULL;
      node[v]->ch[0]=NULL;
      node[v]->maintain();
    }
  }
  int sum(int v){ //返回 v 到根节点的 sum
    node[v]->access();
    node[v]->splay();
    return node[v]->sum;
  }
  int sum(int u, int v){
    node[u]->evert();
    return sum(v);
  }
  void change(int u, int v){
    node[u]->splay();
    node[u]->v=v;
    node[u]->maintain();
  }
  Node *findRoot(int u){
    return node[u]->findRoot();
  }
}lct;

int main(void){
  scanf("%d%d",&n,&m);
  int a;
  FORR(i,1,n){
    scanf("%d",&a); lct.makeTree(i,a);
  }
  int opt,x,y;
  FOR(i,0,m){
    scanf("%d%d%d",&opt,&x,&y);
    if(opt==0){
      printf("%d\n",lct.sum(x,y));
    }else if(opt==1){
      if(lct.findRoot(x) != lct.findRoot(y))
        //lct.link(x,y);
        lct.link(y,x);  //这是为什么……
    }else if(opt==2){
        lct.cut(x,y);
    }else if(opt==3){
      lct.change(x,y);
    }
  }

  return 0;
}
