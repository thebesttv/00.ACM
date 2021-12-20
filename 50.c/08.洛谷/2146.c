/*
题目描述
Linux用户和OSX用户一定对软件包管理器不会陌生。通过软件包管理器，你可以通过一行命令安装某一个软件包，然后软件包管理器会帮助你从软件源下载软件包，同时自动解决所有的依赖（即下载安装这个软件包的安装所依赖的其它软件包），完成所有的配置。Debian/Ubuntu使用的apt-get，Fedora/CentOS使用的yum，以及OSX下可用的homebrew都是优秀的软件包管理器。

你决定设计你自己的软件包管理器。不可避免地，你要解决软件包之间的依赖问题。如果软件包A依赖软件包B，那么安装软件包A以前，必须先安装软件包B。同时，如果想要卸载软件包B，则必须卸载软件包A。现在你已经获得了所有的软件包之间的依赖关系。而且，由于你之前的工作，除0号软件包以外，在你的管理器当中的软件包都会依赖一个且仅一个软件包，而0号软件包不依赖任何一个软件包。依赖关系不存在环（若有m(m≥2)个软件包A1,A2,A3,⋯,Am，其中A1依赖A2，A2依赖A3，A3依赖A4，……，A[m-1]依赖Am，而Am依赖A1，则称这m个软件包的依赖关系构成环），当然也不会有一个软件包依赖自己。

现在你要为你的软件包管理器写一个依赖解决程序。根据反馈，用户希望在安装和卸载某个软件包时，快速地知道这个操作实际上会改变多少个软件包的安装状态（即安装操作会安装多少个未安装的软件包，或卸载操作会卸载多少个已安装的软件包），你的任务就是实现这个部分。注意，安装一个已安装的软件包，或卸载一个未安装的软件包，都不会改变任何软件包的安装状态，即在此情况下，改变安装状态的软件包数为0。

输入输出格式
输入格式：
输入文件的第1行包含1个整数n，表示软件包的总数。软件包从0开始编号。
随后一行包含n−1个整数，相邻整数之间用单个空格隔开，分别表示1,2,3,⋯,n−2,n−1号软件包依赖的软件包的编号。
接下来一行包含1个整数q，表示询问的总数。之后q行，每行1个询问。询问分为两种：
install x：表示安装软件包x
uninstall x：表示卸载软件包x
你需要维护每个软件包的安装状态，一开始所有的软件包都处于未安装状态。
对于每个操作，你需要输出这步操作会改变多少个软件包的安装状态，随后应用这个操作（即改变你维护的安装状态）。

输出格式：
输出文件包括q行。
输出文件的第i行输出1个整数，为第i步操作中改变安装状态的软件包数。

输入输出样例
输入样例#1：
7
0 0 0 1 1 5
5
install 5
install 6
uninstall 1
install 4
uninstall 0

输出样例#1：
3
1
3
2
3

输入样例#2：
10
0 1 2 1 3 0 0 3 2
10
install 0
install 3
uninstall 2
install 7
install 5
install 9
uninstall 9
install 4
install 1
install 9

输出样例#2：
1
3
2
1
3
1
1
1
0
1
*/

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

const int MAX=100020;
int n,q;
struct Node{
  struct Chain *chain;
  struct Edge *se;
  Node *fa,*maxChild;
  int siz,dep,l,r;
}node[MAX];
struct Chain{
  Node *top;
  Chain(Node *top_): top(top_) {}
};
struct Edge{
  Node *v; Edge *next;
}edge[MAX];
int tailE;
struct sNode{
  int l,r,m,sum[2];
  bool set[2];
};
struct ST{
  sNode sg[MAX<<2];

  void pushDown(int root){
    sNode *t=&sg[root];
    sNode *lc=&sg[root<<1],*rc=&sg[root<<1|1];
    FORR(d,0,1) if(t->set[d]){
      lc->set[d]=1; lc->set[d^1]=0;
      rc->set[d]=1; rc->set[d^1]=0;
      lc->sum[d] = lc->r - lc->l + 1; lc->sum[d^1]=0;
      rc->sum[d] = rc->r - rc->l + 1; rc->sum[d^1]=0;
      t->set[d]=0;
    }
  }
  void build(int root, int l, int r){
    sNode &t=sg[root];
    t.l=l; t.r=r; t.m=(l+r)>>1;
    if(l==r) {t.sum[0]=1; return;}
    build(root<<1,l,t.m); build(root<<1|1,t.m+1,r);
    t.sum[0]=sg[root<<1].sum[0]+sg[root<<1|1].sum[0];
  }
  void set(int root, int l, int r, int d){
    sNode &t=sg[root];
    if(l<=t.l && r>=t.r){
      t.sum[d]=t.r-t.l+1; t.sum[d^1]=0;
      t.set[d]=1; t.set[d^1]=0;
      return;
    }
    pushDown(root);
    if(l<=t.m) set(root<<1,l,r,d);
    if(r>t.m) set(root<<1|1,l,r,d);
    t.sum[0]=sg[root<<1].sum[0]+sg[root<<1|1].sum[0];
    t.sum[1]=sg[root<<1].sum[1]+sg[root<<1|1].sum[1];
  }
  int sum(int root, int l, int r, int d){
    sNode &t=sg[root];
    if(l<=t.l && r>=t.r) return t.sum[d];
    pushDown(root);
    int ans=0;
    if(l<=t.m) ans+=sum(root<<1,l,r,d);
    if(r>t.m) ans+=sum(root<<1|1,l,r,d);
    return ans;
  }
}st;

void addEdge(Node *u, Node *v){
  edge[tailE]=(Edge){v,u->se}; u->se=&edge[tailE++];
}
void dfs1(Node *u){
  u->siz=1;
  for(Edge *e=u->se;e;e=e->next){
    if(e->v->siz) continue;
    e->v->fa=u; e->v->dep=u->dep+1;
    dfs1(e->v);
    u->siz+=e->v->siz;
    if(!u->maxChild || u->maxChild->siz < e->v->siz)
      u->maxChild=e->v;
  }
}
int ts;
void dfs2(Node *u){
  u->l=++ts;

  if(!u->fa || u->fa->maxChild!=u) u->chain = new Chain(u);
  else u->chain = u->fa->chain;

  if(u->maxChild) dfs2(u->maxChild);
  for(Edge *e=u->se;e;e=e->next){
    if(e->v==u->fa || e->v==u->maxChild) continue;
    dfs2(e->v);
  }
  u->r=ts;
}
void split(){
  node[1].dep=1;
  dfs1(node+1); dfs2(node+1);
}

int main(void){
  scanf("%d",&n);
  int x;
  FORR(i,2,n){
    scanf("%d",&x); addEdge(node+x+1,node+i);
  }
  split();
  st.build(1,1,ts);

  char s1[14];
  scanf("%d",&q);
  FOR(i,0,q){
    scanf("%s%d",s1,&x);
    Node *t=&node[x+1];
    if(s1[0]=='i'){
      int sum=0;
      while(t){
        sum+=st.sum(1,t->chain->top->l,t->l,0); //统计 0 的个数
        st.set(1,t->chain->top->l,t->l,1);  //全设成 1
        t=t->chain->top->fa;
      }
      printf("%d\n",sum);
    }else{
      printf("%d\n",st.sum(1,t->l,t->r,1)); //统计 1 的个数
      st.set(1,t->l,t->r,0);  //全设成 0
    }
  }

  return 0;
}
