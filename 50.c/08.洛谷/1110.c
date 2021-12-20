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

const int MAXN=500020;
const int MAX=1000020;
int n,m,cnt=0;
int MSG=0x3f3f3f3f;
char t1[20];
struct Node{
  int n,m; Node *next;
  Node() { }
  Node(int n_, int m_, Node *next_): n(n_), m(m_), next(next_) { }
}ori[MAXN];
struct SET{
  int n; set<int> *st;
  SET(int n_, set<int> *st_): n(n_), st(st_) { }
  bool operator < (const SET &b) const {
    return n<b.n;
  }
};
set<SET> mg;
set<int> msg;
set<SET>::iterator it;
set<int>::iterator it1,it2;

void ins_msg(int a){
  if(MSG){
    if(msg.find(a)!=msg.end()) MSG=0;
    else{
      it1=it2=msg.insert(a).first;
      if(it1==msg.begin()){
        it2++;
        MSG=min(MSG, abs((*it2)-a));
      }else if(it1==msg.end()){
        it1--;
        MSG=min(MSG, abs((*it1)-a));
      }else{
        it1--, it2++;
        MSG=min(MSG, min( abs((*it1)-a), abs((*it2)-a)));
      }
    }
  }
}
inline void ins_mg(Node *a, Node *b){
#ifdef DEBUG
  printf("  ins_mg %d-%d\n",a->n,b->n);
#endif
  int t=abs((a->n)-(b->n));
  it=mg.find(SET(t,NULL));
  if(it==mg.end()){
    it=mg.insert(SET(t, new set<int> )).first;
  }
  it->st->insert(a->m);
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n){
    int a; scanf("%d",&a);
    ori[i] = Node(a,cnt++,&ori[i]);

    ins_msg(a);
  }
  FOR(i,1,n){
    int t=abs(ori[i].n-ori[i+1].n);
    it=mg.find(SET(t,NULL));
    if(it==mg.end()){
      it=mg.insert(SET(t, new set<int> )).first;
    }
    it->st->insert(ori[i].m);
  }

  int i,x;
  while(m--){
    scanf("%s",t1);
    if(t1[0]=='I'){
      scanf("%d%d",&i,&x);

      ins_msg(x);

      if(i<n){
        Node *pred=ori[i].next, *succ=&ori[i+1];
        ori[i].next = new Node(x,cnt++,ori[i].next);

        //删除
        int t=abs((pred->n)-(succ->n));
        it=mg.find(SET(t,NULL));
        it->st->erase(pred->m);
        if(it->st->size()==0) mg.erase(it);

        //插入
        ins_mg(pred,ori[i].next);
        ins_mg(ori[i].next,succ);
      }else{
        Node *pred=ori[i].next;
        ori[i].next = new Node(x,cnt++,ori[i].next);
        ins_mg(pred,ori[i].next);
      }
    }else if(t1[4]=='G'){ //MG
      printf("%d\n",mg.begin()->n);
    }else{  //MSG
      printf("%d\n",MSG);
    }
  }

  return 0;
}
