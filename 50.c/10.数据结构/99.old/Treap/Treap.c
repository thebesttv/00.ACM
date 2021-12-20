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

struct Node{
  int v,r,siz,cnt;
  Node *ch[2];

  Node() { }
  Node(int v_, Node *NUL): v(v_), r(rand()), siz(1), cnt(1) {
    ch[0]=ch[1]=NUL;
  }
  int cmp(int x) { return x==v ? -1 : x>v; }
  void maintain(){
    siz = cnt + ch[0]->siz + ch[1]->siz;
  }
}*NUL;
struct Treap{
  Node *root;

  void rotate(Node* &o, int d){  //d: 0 为左旋，1 为右旋
    Node *k=o->ch[d^1]; o->ch[d^1]=k->ch[d]; k->ch[d]=o;
    o->maintain(); k->maintain(); o=k;
  }
  void insert(Node* &o, int v){
    if(o==NUL) o = new Node(v,NUL);
    else{
      int d=o->cmp(v);
      if(d==-1) {o->cnt++, o->siz++; return;}
      else{
        insert(o->ch[d],v);
        if(o->ch[d]->r > o->r) rotate(o,d^1);
      }
    }
    o->maintain();
  }
  //void remove(Node* &o, int v){
  //  int d=o->cmp(v);
  //  if(d==-1){
  //    o->cnt--, o->siz--;
  //    if(!o->cnt){  //删除节点
  //      if(o->ch[0]==NUL) o=o->ch[1];
  //      else if(o->ch[1]==NUL) o=o->ch[0];
  //      else{
  //        o->cnt++, o->siz++; //<b> </b>
  //        int d2 = o->ch[0]->r > o->ch[1]->r;
  //        rotate(o,d2); remove(o->ch[d2],v);
  //      }
  //    }
  //  }else remove(o->ch[d],v);
  //  if(o!=NUL) o->maintain();
  //}
  void remove(Node* &o, int v){
    int d=o->cmp(v);
    if(d==-1){
      o->cnt--;
      if(o->cnt<=0){  //删除节点  //<b> 判断是否小于等于0，而非等于0 </b>
        if(o->ch[0]==NUL) o=o->ch[1];
        else if(o->ch[1]==NUL) o=o->ch[0];
        else{
          int d2 = o->ch[0]->r > o->ch[1]->r;
          rotate(o,d2); remove(o->ch[d2],v);
        }
      }
    }else remove(o->ch[d],v);
    if(o!=NUL) o->maintain();
  }
  Node *find(int v){
    Node *o=root;
    while(o!=NUL && o->v!=v){ //<b> o!=NUL </b>
      o=o->ch[o->cmp(v)];
    }
    return o;
  }
  int rank(int v){
    Node *o=root; int r=0,d;
    while(1){
      d=o->cmp(v);
      if(d==-1) { r += o->ch[0]->siz + 1; break; }
      else if(d==1) { r += o->ch[0]->siz + o->cnt; o=o->ch[1]; }
      else o=o->ch[0];
    }
    return r;
  }
  int select(int k){
    Node *o=root; int l,r;
    while(!( (l=o->ch[0]->siz+1)<=k && k<=(r=o->ch[0]->siz+o->cnt) )){
      if(l>k) o=o->ch[0];
      else k-=r, o=o->ch[1];
    }
    return o->v;
  }
}tp;

int main(void){
  srand(time(NULL));
  NUL = new Node(); NUL->v = NUL->r = NUL->siz = NUL->cnt = 0; NUL->ch[0] = NUL->ch[1] = NUL;
  tp.root=NUL;

  int opt,x;
  while(scanf("%d%d",&opt,&x)==2 && opt){
#ifdef DEBUG
    printf("cmd: %d %d\n",opt,x);
#endif
    if(opt==1){ //插入
      tp.insert(tp.root,x);
    }else if(opt==2){ //删除
      if(tp.find(x)!=NUL) tp.remove(tp.root,x);
      else printf("%d doesn't exist\n",x);
    }else if(opt==3){ //查找
      if(tp.find(x)!=NUL) printf("%d exists\n",x);
      else printf("%d doesn't exist\n",x);
    }else if(opt==4){ //rank
      if(tp.find(x)!=NUL) printf("%d exists, with rank %d\n",x,tp.rank(x));
      else printf("%d doesn't exist\n",x);
    }else if(opt==5){ //select
      if(x>=1 && x<=tp.root->siz) printf("the %d element is %d\n",x,tp.select(x));
      else printf("illegal rank\n");
    }

#ifdef DEBUG
    printf("------- ");
    int siz=tp.root->siz;
    FORR(i,1,siz) printf("%d ",tp.select(i));
    printf("-------, ");
#endif
    printf("size: %d\n",tp.root->siz);
  }

  return 0;
}
