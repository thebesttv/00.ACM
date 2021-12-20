/*
您需要写一种数据结构（可参考题目标题），来维护一些数，其中需要提供以下操作：
1. 插入x数
2. 删除x数(若有多个相同的数，因只删除一个)
3. 查询x数的排名(若有多个相同的数，因输出最小的排名)
4. 查询排名为x的数
5. 求x的前驱(前驱定义为小于x，且最大的数)
6. 求x的后继(后继定义为大于x，且最小的数)

Input
第一行为n，表示操作的个数,下面n行每行有两个数opt和x，opt表示操作的序号(1<=opt<=6)

Output
对于操作3,4,5,6每行输出一个数，表示对应答案

Sample Input
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598

Sample Output
106465
84185
492737

Hint
1.n的数据范围：n<=100000
2.每个数的数据范围：[-2e9,2e9]
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
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
typedef long long LL;
typedef long long unsigned LLU;

struct Splay{
  struct Node{
    Node *ch[2],*fa,**root;
    int v,siz;

    ~Node(){
      if(ch[0]) delete ch[0];
      if(ch[1]) delete ch[1];
    }
    Node(Node **root_, Node *fa_, int v_): root(root_), fa(fa_), v(v_), siz(1) {
      ch[0]=ch[1]=NULL;
    }
    int relation() {return this==fa->ch[1];}
    void maintain(){
      siz=1;
      if(ch[0]) siz+=ch[0]->siz;
      if(ch[1]) siz+=ch[1]->siz;
    }
    void rotate(){
      Node *p=fa;
      int d=relation();

      fa=p->fa;
      if(p->fa) p->fa->ch[p->relation()]=this;

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
        if(fa==*target){
          rotate();
        }else if(relation()==fa->relation()){
          fa->rotate(); rotate();
        }else{
          rotate(); rotate();
        }
      }
      return *target;
    }
    Node *pred(){
      Node *p=this;
      while(p->v==v){
        p->splay(); p=p->ch[0];
        while(p->ch[1]) p=p->ch[1];
      }
      return p->splay();  //<b> </b>
    }
    Node *succ(){
      Node *p=this;
      while(p->v==v){
        p->splay(); p=p->ch[1];
        while(p->ch[0]) p=p->ch[0];
      }
      return p->splay();
    }
  }*root;

  Splay(): root(NULL) {
    insert(INT_MIN); insert(INT_MAX);
  }
  Node *find(int v){
    Node *p=root;
    while(p && p->v!=v){
      if(p->v > v) p=p->ch[0];
      else p=p->ch[1];
    }
    if(p) return p->pred()->succ()->splay();
    else return NULL;
  }
  Node *insert(int v){
    Node **p=&root,*fa=NULL;
    while(*p){  //<b> </b>
      fa=*p; fa->siz++; //<b> </b>
      if(fa->v > v) p=&fa->ch[0]; //<b> </b>
      else p=&fa->ch[1];
    }

    *p = new Node(&root,fa,v);
    return (*p)->splay();
  }
  void erase(Node *l, Node *r){ //删除[l,r]
    Node *p=l->pred(),*s=r->succ();
    p->splay();
    s->splay(&p->ch[1]);

    delete s->ch[0];
    s->ch[0]=NULL;

    s->maintain();
    p->maintain();
  }
  void erase(int v){
    Node *p=find(v);
    erase(p,p);
  }
  int pred(int v){
    Node *p=find(v);
    //if(p) return p->pred()->splay()->v;
    if(p) return p->pred()->v;  //不必再次 splay ，在 pred() 结束时已经执行
    else{
      p=insert(v);
      int ans=p->pred()->v;
      erase(p,p);
      return ans;
    }
  }
  int succ(int v){
    Node *p=find(v);
    if(p) return p->succ()->v;
    else{
      p=insert(v);
      int ans=p->succ()->v;
      erase(p,p);
      return ans;
    }
  }
  int rank(int v){
    Node *p=find(v);
    return p->ch[0]->siz; //<b> </b>
  }
  int select(int k){
    k++;  //<b> </b>
    Node *p=root;
    while(p->ch[0] && p->ch[0]->siz +1 != k){
      if(p->ch[0]->siz +1 > k){
        p=p->ch[0];
      }else{
        k -= p->ch[0]->siz +1;
        p=p->ch[1];
      }
    }
    return p->splay()->v;
  }
}splay;

int main(void){
  int n,opt,x;
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d%d",&opt,&x);
    switch(opt){
      case 1: splay.insert(x); break;
      case 2: splay.erase(x); break;
      case 3: printf("%d\n",splay.rank(x)); break;
      case 4: printf("%d\n",splay.select(x)); break;
      case 5: printf("%d\n",splay.pred(x)); break;
      case 6: printf("%d\n",splay.succ(x)); break;
    }
  }

  return 0;
}
