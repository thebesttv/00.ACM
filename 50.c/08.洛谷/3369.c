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

//有重复元素、自顶向下的 Splay
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
  Node *root; //不要先将 root 置空，否则编译时可能报错

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
    erase_one_node(p);
  }
  void erase_one_node(Node *p){
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

int main(void){
  int n,opt,x; scanf("%d",&n);

  while(n--){
    scanf("%d%d",&opt,&x);

    switch(opt){
      case 1: //插入
        sp.insert(x); break;
      case 2: //删除
        sp.erase_one_node(x); break;
      case 3: //rank
        printf("%d\n",sp.rank(sp.find(x))); break;
      case 4: //select
        printf("%d\n",sp.select(x)); break;
      case 5: //pred
        printf("%d\n",sp.pred(x)); break;
      case 6: //succ
        printf("%d\n",sp.succ(x)); break;
    }
  }

  return 0;
}
