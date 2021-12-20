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

const int TOT=26;
const int MAX=100020;
int n; char ori[MAX],t1[MAX];
char st1[MAX]; int st2[MAX]; int top;

struct AC{
  int to[MAX][TOT],val[MAX],P[MAX],siz;

  void init() {siz=1; MST(to[0],0); val[0]=0;}
  void insert(char *s, int v){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0), val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]=v;
  }
  void getP(){
    queue<int> q; P[0]=0;
    int u;
    FOR(i,0,TOT){
      u=to[0][i];
      if(u) q.push(u), P[u]=0;
    }
    int v,j;
    while(!q.empty()){
      u=q.front(); q.pop();
      FOR(i,0,TOT){
        v=to[u][i];
        if(!v) {to[u][i] = to[P[u]][i]; continue;}  //<b> </b>
        q.push(v);

        //自我匹配
        j=P[u];
        while(j && !to[j][i]) j=P[j];
        j=to[j][i];
        P[v]=j;
      }
    }
  }
  void find(char *s){
    int j=0,ch;
    while(ch=*s++){
      ch-='a';
      //while(j && !to[j][ch]) j=P[j];
      j=to[j][ch];
      st1[top]=ch+'a'; st2[top++]=j;
      if(val[j]){
        top-=val[j]; j=st2[top-1];
      }
    }
  }
}ac;

int main(void){
  scanf("%s%d",ori,&n);
  ac.init();
  FOR(i,0,n) scanf("%s",t1), ac.insert(t1,strlen(t1));

  ac.getP(); ac.find(ori);
  FOR(i,0,top) putchar(st1[i]); putchar('\n');

  return 0;
}

/*
const int TOT=26;
const int MAX=100020;
int n; char t1[MAX],t2[MAX];

struct Node{
  int v,siz; bool bound;  //是否为边界
  Node *ch[2],*fa,**root;

  Node(Node **root_, Node *fa_, int v_): root(root_), fa(fa_), v(v_), siz(1), bound(0){
    ch[0]=ch[1]=NULL;
  }
  int relation() {return this==fa->ch[1];}
  int size(int d) {return ch[d] ? ch[d]->siz : 0 ;}
  void maintain(){
    siz=1;
    if(ch[0]) siz+=ch[0]->siz;
    if(ch[1]) siz+=ch[1]->siz;
  }
  void rotate(){
    Node *p=fa;
    int d=relation();

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
      if(fa==*target) rotate();
      else if(relation()==fa->relation()) fa->rotate(), rotate();
      else rotate(), rotate();
    }
    return this;
  }
};

struct Splay{
  Node *root;

  void build(char *a, int n){
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
  Node *build(Node *fa, char *a, int l, int r){
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
    while((t=p->size(0)+1) != k){
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
  void remove(int l, int r){  //删除 [l,r] XXX
    Node *p=select(l-1), *s=select(r+1);
    p->splay(); s->splay(&p->ch[1]);
    s->ch[0]=NULL; s->maintain(); p->maintain();
  }
  char *fetch(char *a){
    dfs(root,a);
    return a;
  }
  void dfs(Node *o, char* &a){
    if(o->ch[0]) dfs(o->ch[0],a);
    if(!o->bound) *(a++)=o->v;  //<b> </b>
    if(o->ch[1]) dfs(o->ch[1],a);
  }
}sp;

int to[MAX][TOT],val[MAX],siz=1;  // val[i] 表示串 i 的长度
int P[MAX];

void insert(char *s, int v){
  int u=0,ch;
  while(ch=*s++){
    ch-='a';
    if(!to[u][ch]){
      MST(to[siz],0), val[siz]=0;
      to[u][ch]=siz++;
    }
    u=to[u][ch];
  }
  val[u]=v;
}
void getP(){
  queue<int> q; P[0]=0;
  int u;
  FOR(i,0,TOT){
    u=to[0][i];
    if(u) q.push(u), P[u]=0;
  }
  int v,j;
  while(!q.empty()){
    u=q.front(); q.pop();
    FOR(i,0,TOT){
      v=to[u][i];
      if(!v) continue;
      q.push(v);

      //自我匹配
      j=P[u];
      while(j && !to[j][i]) j=P[j];
      j=to[j][i];
      P[v]=j;
    }
  }
}
bool find(int &l, int &r){ //在 Splay 所表示的串中匹配，若成功则 [l,r] 表示匹配到的区间
  int j=0,ch; int n=sp.root->siz-2;
  sp.fetch(t2); char *s=t2;
  l=r=0;
#ifdef DEBUG
  printf("  have string: "); FORR(i,1,n) putchar(sp.select(i)->v); putchar('\n');
#endif
  FORR(i,1,n){
    ch=(*s++)-'a';
    //printf("    get %c\n",ch+'a');
    while(j && !to[j][ch]) j=P[j];
    j=to[j][ch];
    if(val[j]){
      r=i; l=i-val[j]+1;
#ifdef DEBUG
      printf("  find match in [%d,%d], it's last node is %d\n",l,r,j);
#endif
      return true;
    }
  }
  return false;
}

int main(void){
  scanf("%s",t1+1); sp.build(t1,strlen(t1+1));
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%s",t1); insert(t1,strlen(t1));
  }

  getP(); //...
  int l,r;
  while(find(l,r)){
    sp.remove(l,r);
  }
  *sp.fetch(t1)=0;
  printf("%s\n",t1);

  return 0;
}
*/

/*
struct AC{
  int to[MAX][TOT],val[MAX],P[MAX],siz;

  void init() {siz=1; MST(to[0],0); val[0]=0;}
  void insert(char *s, int v){
    int u=0,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        MST(to[siz],0), val[siz]=0;
        to[u][ch]=siz++;
      }
      u=to[u][ch];
    }
    val[u]=v;
  }
  void getP(){
    queue<int> q; P[0]=0;
    int u;
    FOR(i,0,TOT){
      u=to[0][i];
      if(u) q.push(u), P[u]=0;
    }
    int v,j;
    while(!q.empty()){
      u=q.front(); q.pop();
      FOR(i,0,TOT){
        v=to[u][i];
        if(!v) continue;
        q.push(v);

        //自我匹配
        j=P[u];
        while(j && !to[j][i]) j=P[j];
        j=to[j][i];
        P[v]=j;
      }
    }
  }
  void find(char *s){
    int j=0,ch;
    while(ch=*s++){
      ch-='a';
      while(j && !to[j][ch]) j=P[j];
      j=to[j][ch];
      st1[top]=ch+'a'; st2[top++]=j;
      if(val[j]){
        top-=val[j]; j=st2[top-1];
      }
    }
  }
}ac;
*/
