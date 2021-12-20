#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

//树状数组+差分
//指针实现树链剖分
const int MAX=50020;
int n,m,p,a[MAX];
struct Node{
  struct Chain *chain;
  struct Edge *se;
  Node *fa,*maxChild;
  int siz,dep,dfn;
  bool vis;
}node[MAX];
struct Edge{
  Node *v;
  Edge *next;
}edge[MAX<<1];
int tailE;
struct Chain{
  Node *top;
  Chain() {}
  Chain(Node *top_): top(top_) {}
};
struct ST{
  int n,s[MAX];

  void add(int x, int d){
    while(x<=n){
      s[x]+=d; x+=x&-x;
    }
  }
  int sum(int x){
    int ans=0;
    while(x){
      ans+=s[x]; x-=x&-x;
    }
    return ans;
  }
}st;

void addEdge(Node *u, Node *v){
  edge[tailE]=(Edge){v,u->se}; u->se=&edge[tailE++];
}
void dfs1(Node *u){
  u->vis=1; u->siz=1;
  for(Edge *i=u->se;i;i=i->next){
    Node *v=i->v;
    if(v->vis) continue;
    v->dep=u->dep+1; v->fa=u;
    dfs1(v);
    u->siz+=v->siz;
    if(!u->maxChild || u->maxChild->siz < v->siz)
      u->maxChild=v;
  }
}
int ts;
void dfs2(Node *u){
  u->dfn=++ts;

  if(!u->fa || u->fa->maxChild!=u) u->chain = new Chain(u);
  else u->chain = u->fa->chain;

  if(u->maxChild) dfs2(u->maxChild);
  for(Edge *i=u->se;i;i=i->next){
    Node *v=i->v;
    if(v==u->fa || v==u->maxChild) continue;
    dfs2(v);
  }
}
void split(){
  node[1].dep=1;
  dfs1(&node[1]); dfs2(&node[1]);
}
void add(Node *x, Node *y, int d){  //对于 c1,c2 组成的路径中的每个节点都加d
  while(x->chain != y->chain){
    if(x->chain->top->dep < y->chain->top->dep) swap(x,y);  //保证 x 所在链深度较大
    st.add(x->chain->top->dfn,d); st.add(x->dfn+1,-d);
    x=x->chain->top->fa;
  }
  if(x->dep > y->dep) swap(x,y);
  st.add(x->dfn,d); st.add(y->dfn+1,-d);
}

int main(void){
  while(scanf("%d%d%d",&n,&m,&p)==3){
    ts=0; tailE=0; MST(node,0); MST(st.s,0);

    FORR(i,1,n) scanf("%d",&a[i]);
    int u,v;
    FOR(i,0,m){
      scanf("%d%d",&u,&v);
      addEdge(&node[u],&node[v]); addEdge(&node[v],&node[u]);
    }
    split();
    st.n=ts+2;
    FORR(i,1,n){
      st.add(node[i].dfn,a[i]); st.add(node[i].dfn+1,-a[i]);
    }

    int ch,c1,c2,k;
    FOR(i,0,p){
      do ch=getchar(); while(!isalpha(ch));
      if(ch=='I' || ch=='D'){
        scanf("%d%d%d",&c1,&c2,&k);
        if(ch=='D') k=-k;
        add(&node[c1],&node[c2],k);
      }else{
        scanf("%d",&c1);
        printf("%d\n",st.sum(node[c1].dfn));
      }
    }
  }

  return 0;
}

/*
//树状数组+差分
const int MAX=50020;
int n,m,p,a[MAX];
struct Edge{
  int v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
struct Chain{
  int top;
  Chain() {}
  Chain(int top_): top(top_) {}
};
struct Node{
  Chain *chain;
  int siz,dep,dfn;
  int fa,maxChild;
}node[MAX];
bool vis[MAX];
struct sNode{
  int l,m,r,sum,addVal;
};
struct ST{
  int n,s[MAX];

  void add(int x, int d){
    while(x<=n){
      s[x]+=d; x+=x&-x;
    }
  }
  int sum(int x){
    int ans=0;
    while(x){
      ans+=s[x]; x-=x&-x;
    }
    return ans;
  }
}st;

void addEdge(int u, int v){
  edge[tailE]=(Edge){v,se[u]}; se[u]=tailE++;
}
void dfs1(int u){
  vis[u]=1;
  Node &t=node[u]; t.siz=1;
  for(int i=se[u];i;i=edge[i].next){
    Edge &e=edge[i];
    if(vis[e.v]) continue;
    node[e.v].dep=t.dep+1; node[e.v].fa=u;
    dfs1(e.v);
    t.siz+=node[e.v].siz;
    if(!t.maxChild || node[t.maxChild].siz<node[e.v].siz)
      t.maxChild=e.v;
  }
}
int ts;
void dfs2(int u){
  Node &t=node[u]; t.dfn=++ts;

  if(!t.fa || node[t.fa].maxChild!=u) t.chain = new Chain(u);
  else t.chain = node[t.fa].chain;

  if(t.maxChild) dfs2(t.maxChild);
  for(int i=se[u];i;i=edge[i].next){
    Edge &e=edge[i];
    if(e.v==t.fa || e.v==t.maxChild) continue;
    dfs2(e.v);
  }
}
void split(){
  node[1].dep=1;
  dfs1(1); dfs2(1);
}
void add(int x, int y, int d){  //对于 c1,c2 组成的路径中的每个节点都加d
  while(node[x].chain!=node[y].chain){
    if(node[node[x].chain->top].dep < node[node[y].chain->top].dep) swap(x,y);  //保证 x 所在链深度较大
    st.add(node[node[x].chain->top].dfn,d); st.add(node[x].dfn+1,-d);
    x=node[node[x].chain->top].fa;
  }
  if(node[x].dep>node[y].dep) swap(x,y);
  st.add(node[x].dfn,d); st.add(node[y].dfn+1,-d);
}

int main(void){
  while(scanf("%d%d%d",&n,&m,&p)==3){
    ts=0; tailE=1; MST(se,0); MST(node,0); MST(vis,0); MST(st.s,0);

    FORR(i,1,n) scanf("%d",&a[i]);
    int u,v;
    FOR(i,0,m){
      scanf("%d%d",&u,&v);
      addEdge(u,v); addEdge(v,u);
    }
    split();
    st.n=ts+2;
    FORR(i,1,n){
      st.add(node[i].dfn,a[i]); st.add(node[i].dfn+1,-a[i]);
    }

    int ch,c1,c2,k;
    FOR(i,0,p){
      do ch=getchar(); while(!isalpha(ch));
      if(ch=='I' || ch=='D'){
        scanf("%d%d%d",&c1,&c2,&k);
        if(ch=='D') k=-k;
        add(c1,c2,k);
      }else{
        scanf("%d",&c1);
        printf("%d\n",st.sum(node[c1].dfn));
      }
    }
  }

  return 0;
}
*/

/*
//线段树
const int MAX=50020;
int n,m,p,a[MAX],ta[MAX];
struct Edge{
  int u,v,next;
}edge[MAX<<1];
int se[MAX],tailE=1;
struct Chain{
  int top;
  Chain() {}
  Chain(int top_): top(top_) {}
};
struct Node{
  Chain *chain;
  int siz,dep,dfn;
  int fa,maxChild;
}node[MAX];
bool vis[MAX];
struct sNode{
  int l,m,r,sum,addVal;
};
struct ST{
  sNode sg[MAX<<2];

  void build(int root, int l, int r){
    sNode &t=sg[root];
    t.l=l; t.r=r; t.m=(l+r)>>1;
    if(l==r) {t.sum=ta[l]; return;}
    build(root<<1,l,t.m); build(root<<1|1,t.m+1,r);
    t.sum=sg[root<<1].sum+sg[root<<1|1].sum;
  }
  void pushDown(int root){
    sNode &t=sg[root];
    if(t.addVal){
      sg[root<<1].addVal+=t.addVal;
      sg[root<<1|1].addVal+=t.addVal;
      sg[root<<1].sum+=t.addVal*(t.m-t.l+1);
      sg[root<<1|1].sum+=t.addVal*(t.r-t.m);
      t.addVal=0;
    }
  }
  void add(int root, int l, int r, int d){
    sNode &t=sg[root];
    if(l<=t.l && r>=t.r){
      t.addVal+=d; t.sum+=d*(t.r-t.l+1);
      return;
    }
    pushDown(root);
    if(l<=t.m) add(root<<1,l,r,d);
    if(r>t.m) add(root<<1|1,l,r,d);
    t.sum=sg[root<<1].sum+sg[root<<1|1].sum;
  }
  int sum(int root, int l, int r){
    sNode &t=sg[root];
    if(l<=t.l && r>=t.r) return t.sum;
    pushDown(root);
    int ans=0;
    if(l<=t.m) ans+=sum(root<<1,l,r);
    if(r>t.m) ans+=sum(root<<1|1,l,r);
    return ans;
  }
}st;

void addEdge(int u, int v){
  edge[tailE]=(Edge){u,v,se[u]}; se[u]=tailE++;
}
void dfs1(int u){
  vis[u]=1;
  Node &t=node[u]; t.siz=1;
  for(int i=se[u];i;i=edge[i].next){
    Edge &e=edge[i];
    if(vis[e.v]) continue;
    node[e.v].dep=t.dep+1; node[e.v].fa=u;
    dfs1(e.v);
    t.siz+=node[e.v].siz;
    if(!t.maxChild || node[t.maxChild].siz<node[e.v].siz)
      t.maxChild=e.v;
  }
}
int ts;
void dfs2(int u){
  Node &t=node[u]; t.dfn=++ts;

  if(!t.fa || node[t.fa].maxChild!=u) t.chain = new Chain(u);
  else t.chain = node[t.fa].chain;

  if(t.maxChild) dfs2(t.maxChild);
  for(int i=se[u];i;i=edge[i].next){
    Edge &e=edge[i];
    if(e.v==t.fa || e.v==t.maxChild) continue;
    dfs2(e.v);
  }
}
void split(){
  node[1].dep=1;
  dfs1(1); dfs2(1);
}
void add(int x, int y, int d){  //对于 c1,c2 组成的路径中的每个节点都加d
  while(node[x].chain!=node[y].chain){
    if(node[node[x].chain->top].dep < node[node[y].chain->top].dep) swap(x,y);  //保证 x 所在链深度较大
    st.add(1,node[node[x].chain->top].dfn,node[x].dfn,d);
    x=node[node[x].chain->top].fa;
  }
  if(node[x].dep>node[y].dep) swap(x,y);
  st.add(1,node[x].dfn,node[y].dfn,d);
}

int main(void){
  while(scanf("%d%d%d",&n,&m,&p)==3){
    ts=0; tailE=1; MST(se,0); MST(node,0); MST(vis,0); MST(st.sg,0);

    FORR(i,1,n) scanf("%d",&a[i]);
    int u,v;
    FOR(i,0,m){
      scanf("%d%d",&u,&v);
      addEdge(u,v); addEdge(v,u);
    }
    split();
    FORR(i,1,n) ta[node[i].dfn]=a[i];
    st.build(1,1,ts);

    int ch,c1,c2,k;
    FOR(i,0,p){
      do ch=getchar(); while(!isalpha(ch));
      if(ch=='I' || ch=='D'){
        scanf("%d%d%d",&c1,&c2,&k);
        if(ch=='D') k=-k;
        add(c1,c2,k);
      }else{
        scanf("%d",&c1);
        printf("%d\n",st.sum(1,node[c1].dfn,node[c1].dfn));
      }
    }
  }

  return 0;
}
*/
