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

//TODO: 无重复元素、自顶向下的 Splay
//用类似 Treap 的 dfs 写法
struct Node{
  int v,siz;
  Node *ch[2];

  Node(int v_): v(v_), siz(1) {
    ch[0]=ch[1]=NULL;
  }
  int cmp(int x) {return x==v ? -1 : x>v;}
  void dfs_maintain(){
    siz=1;
    if(ch[0]) ch[0]->dfs_maintain(), siz+=ch[0]->siz;
    if(ch[1]) ch[1]->dfs_maintain(), siz+=ch[1]->siz;
  }
  void rL(Node* &x, Node* &b){
    b->ch[0]=x; b=x; x=x->ch[0];
  }
  void rR(Node* &x, Node* &s){
    s->ch[1]=x; s=x; x=x->ch[1];
  }
  Node *splay(Node **target){  //将当前节点 Splay 到 target
    Node *small = new Node(0), *big = new Node(0);
    Node *s=small, *b=big;
    int d1,d2;
    Node *x=*target;
    while(x!=this){  //将 x 下放
      d1=x->cmp(v); d2=x->ch[d1]->cmp(v);
      if(d1==0){
        if(d2==-1){ //L
          rL(x,b);
        }else if(d2==1){  //LR
          rL(x,b); rR(x,s);
        }else{  //LL
          b->ch[0]=x->ch[1]; b=b->ch[0];
          x->ch[0]=b->ch[1]; b->ch[1]=x;
          x=b->ch[0];
        }
      }else{
        if(d2==-1){ //R
          rR(x,s);
        }else if(d2==0){  //RL
          rR(x,s); rL(x,b);
        }else{  //RR
          s->ch[1]=x->ch[0]; s=s->ch[1];
          x->ch[1]=s->ch[0]; s->ch[0]=x;
          x=s->ch[1];
        }
      }
    }
    s->ch[1]=x->ch[0];
    b->ch[0]=x->ch[1];

    x->ch[0]=small->ch[1];
    x->ch[1]=big->ch[0];

    *target=this;
    dfs_maintain();
    return this;
  }
  Node *pred(){
    Node *p=splay();
  }
  Node *succ();
};
struct Splay{
  Node *root;

  Splay(){
    root=NULL;
    insert(INT_MIN);
    insert(INT_MAX);
  }
  Node *insert(int v);
  void erase(int v);
  void erase(Node *p);
  void erase(Node *l, Node *r);
  Node *find(int v);
  Node *pred(int v);
  Node *succ(int v);
}



















































/*
//有重复元素、自底向上的 Splay
struct Node{
  int v,siz,cnt;  //siz: 一共的节点数（包括重复元素），cnt: 该元素的重复次数
  Node *ch[2],*fa,**root;

  ~Node(){
    if(ch[0]) delete ch[0];
    if(ch[1]) delete ch[1];
  }
  Node(Node **root_, Node *fa_, int v_): root(root_),fa(fa_),v(v_),siz(1),cnt(1){
    ch[0]=ch[1]=NULL;
  }
  int relation() {return this==fa->ch[1];}
  int sub_size(int d) {return ch[d] ? ch[d]->siz : 0;}  //子树的大小
  void maintain(){
    siz=cnt;
    if(ch[0]) siz+=ch[0]->siz;
    if(ch[1]) siz+=ch[1]->siz;
  }
  void rotate(){
    Node *p=fa; int d=relation();

    if(p->fa) p->fa->ch[p->relation()]=this;
    fa=p->fa;

    p->ch[d]=ch[d^1];
    if(ch[d^1]) ch[d^1]->fa=p;

    ch[d^1]=p;
    p->fa=this;

    p->maintain(); maintain();
    if(!fa) *root=this;
  }
  Node *splay(Node **target=NULL){
    if(!target) target=root;

    while(this != *target){
      if(fa == *target) rotate();
      else if(relation() == fa->relation()) fa->rotate(), rotate();
      else rotate(), rotate();
    }
    return this;
  }
  Node *pred(){
    Node *p=this->splay();
    p=p->ch[0];
    while(p->ch[1]) p=p->ch[1];
    return p->splay();
  }
  Node *succ(){
    Node *p=this->splay();
    p=p->ch[1];
    while(p->ch[0]) p=p->ch[0];
    return p->splay();
  }
};
struct Splay{
  Node *root; //不要先将 root 置空，而要在构造函数中置空，否则编译时可能报错

  Splay(){
    root=NULL;
    insert(INT_MIN);
    insert(INT_MAX);
  }
  Node *find(int v){
    Node *p=root;
    while(p && p->v!=v){
      if(p->v > v) p=p->ch[0];
      else p=p->ch[1];
    }
    if(p) return p->splay();
    else return NULL;
  }
  Node *insert(int v){  //调用前先查找是否存在该节点
    Node **p=&root,*fa=NULL;
    while(*p && (*p)->v!=v){
      fa=*p; fa->siz++;
      if((*p)->v > v) p=&(*p)->ch[0];
      else p=&(*p)->ch[1];
    }
    if(*p) (*p)->cnt++, (*p)->siz++;
    else *p = new Node(&root,fa,v);

    return (*p)->splay();
  }
  void erase_one_node(int v){ //仅删除一个等于 v 的节点，可能的话再进行 Splay
    Node *p=root;
    while(p->v != v){
      p->siz--;
      if(p->v > v) p=p->ch[0];
      else p=p->ch[1];
    }
    //p->cnt--, p->siz--;
    //if(!p->cnt) erase(p);
    //else p->splay();
    erase_one_node(p);
  }
  void erase_one_node(Node *p){ //仅删除 p 指向的节点中的一个元素，可能的话再进行 Splay
    p->cnt--, p->siz--;
    if(!p->cnt) erase(p);
    else p->splay();
  }
  void erase(Node *p) {erase(p,p);} //删除所有等于 l->v 的节点
  void erase(Node *l, Node *r){ //删除 [l->v,r->v] 整个区间
    l=l->pred(); r=r->succ();
    l->splay(); r->splay(&l->ch[1]);
    delete r->ch[0];
    r->ch[0]=NULL;
    r->maintain(); l->maintain();
  }
  int pred(int v){
    Node *p=find(v);
    if(p) return p->pred()->v;
    else{
      p=insert(v);
      int t=p->pred()->v;
      erase(p,p);
      return t;
    }
  }
  int succ(int v){
    Node *p=find(v);
    if(p) return p->succ()->v;
    else{
      p=insert(v);
      int t=p->succ()->v;
      erase(p,p);
      return t;
    }
  }
  int rank(Node *p){  //假设 p 已经 Splay 到根
    return p->ch[0]->siz;
  }
  int select(int k){
    k++;
    Node *p=root; int l,r;
    while(!( (l=p->sub_size(0)+1) <= k && k <= (r=p->sub_size(0)+p->cnt))){
      if(l>k) p=p->ch[0];
      else k-=r, p=p->ch[1];
    }
    return p->splay()->v;
  }
}sp;
*/

/*
//无重复元素、自底向上的 Splay
struct Node{
  int v,siz;
  Node *ch[2],*fa,**root;

  ~Node(){
    if(ch[0]) delete ch[0];
    if(ch[1]) delete ch[1];
  }
  Node(Node **root_, Node *fa_, int v_): root(root_),fa(fa_),v(v_),siz(1){
    ch[0]=ch[1]=NULL;
  }
  int relation() {return this==fa->ch[1];}
  int size(int d) {return ch[d] ? ch[d]->siz : 0;}
  void maintain(){
    siz=1;
    if(ch[0]) siz+=ch[0]->siz;
    if(ch[1]) siz+=ch[1]->siz;
  }
  void rotate(){
    Node *p=fa; int d=relation();

    if(p->fa) p->fa->ch[p->relation()]=this;
    fa=p->fa;

    p->ch[d]=ch[d^1];
    if(ch[d^1]) ch[d^1]->fa=p;

    ch[d^1]=p;
    p->fa=this;

    p->maintain(); maintain();
    if(!fa) *root=this;
  }
  Node *splay(Node **target=NULL){
    if(!target) target=root;

    while(this != *target){
      if(fa == *target) rotate();
      else if(relation() == fa->relation()) fa->rotate(), rotate();
      else rotate(), rotate();
    }
    return this;
  }
  Node *pred(){
    Node *p=this->splay();
    p=p->ch[0];
    while(p->ch[1]) p=p->ch[1];
    return p->splay();
  }
  Node *succ(){
    Node *p=this->splay();
    p=p->ch[1];
    while(p->ch[0]) p=p->ch[0];
    return p->splay();
  }
};
struct Splay{
  Node *root=NULL;

  Splay(){
    insert(INT_MIN);
    insert(INT_MAX);
  }
  Node *find(int v){
    Node *p=root;
    while(p && p->v!=v){
      if(p->v > v) p=p->ch[0];
      else p=p->ch[1];
    }
    if(p) return p->splay();
    else return NULL;
  }
  Node *insert(int v){  //调用前先查找是否存在该节点
    Node **p=&root,*fa=NULL;
    while(*p){
      fa=*p; fa->siz++;
      if((*p)->v > v) p=&(*p)->ch[0];
      else p=&(*p)->ch[1];
    }
    *p = new Node(&root,fa,v);
    return (*p)->splay();
  }
  void erase(Node *p) {erase(p,p);}
  void erase(Node *l, Node *r){
    l=l->pred(); r=r->succ();
    l->splay(); r->splay(&l->ch[1]);
    delete r->ch[0];
    r->ch[0]=NULL;
    r->maintain(); l->maintain();
  }
  int pred(int v){
    Node *p=find(v);
    if(p) return p->pred()->v;
    else{
      p=insert(v);
      int t=p->pred()->v;
      erase(p,p);
      return t;
    }
  }
  int succ(int v){
    Node *p=find(v);
    if(p) return p->succ()->v;
    else{
      p=insert(v);
      int t=p->succ()->v;
      erase(p,p);
      return t;
    }
  }
  int rank(Node *p){  //假设 p 已经 Splay 到根
    return p->ch[0]->siz;
  }
  int select(int k){
    k++;
    Node *p=root; int t;
    while((t=p->size(0)+1) != k){  //<b> </b>
      if(t > k) p=p->ch[0];
      else {k-=t; p=p->ch[1];}
    }
    return p->splay()->v;
  }
}sp;
*/

int main(void){
  int opt,x;

  while(scanf("%d%d",&opt,&x)==2){
    if(opt==1){ //插入
      if(sp.find(x)) printf("%d exists\n",x);
      else sp.insert(x);
    }else if(opt==2){ //删除
      if(!sp.find(x)) printf("%d doesn't exist\n",x);
      else sp.erase(sp.find(x));
    }else if(opt==3){ //查找
      if(sp.find(x)) printf("%d exists\n",x);
      else printf("%d doesn't exist\n",x);
    }else if(opt==4){ //rank
      if(sp.find(x)) printf("%d exists, with rank %d\n",x,sp.rank(sp.find(x)));
      else printf("%d doesn't exist\n",x);
    }else if(opt==5){ //select
      if(x && x<=sp.root->siz-2) printf("the %d element is %d\n",x,sp.select(x));
      else printf("illegal rank\n");
    }
    printf("size: %d\n",sp.root->siz-2);
  }

  return 0;
}
