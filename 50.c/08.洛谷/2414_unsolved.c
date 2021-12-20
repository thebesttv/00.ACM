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
int n,ans[MAX];
char t1[MAX],t2[MAX];

struct Question{
  int x,y,num;
  bool operator < (const Question & b) const {
    return y < b.y;
  }
}Q[MAX];

struct AC{
  int to[MAX][TOT],val[MAX],siz;
  int P[MAX];
  int fa[MAX];  //节点 i 的父节点
  int rval[MAX];  //rval[i]=j <==> val[j]=i （有重复串没关系）

  void init() {siz=1;}
  void build(char *s, char *t){
    int ch,tail=0,cnt=0;
    while(ch=*s++){
      if(ch=='B') t[--tail]=0;
      else if(ch=='P') insert(t,++cnt);
      else t[tail++]=ch;
    }
  }
  void insert(char *s, int v_){ //ok
    int u=0,v,ch;
    while(ch=*s++){
      ch-='a';
      if(!to[u][ch]){
        to[u][ch]=siz++;
      }
      v=to[u][ch];
      fa[v]=u; u=v;
    }
    val[u]=v_; rval[v_]=u;
  }
  void getP(){
    queue<int> q; P[0]=0;
    int u,v,j;
    FOR(i,0,TOT){
      u=to[0][i];
      if(u) q.push(u), P[u]=0;
    }
    while(!q.empty()){
      u=q.front(); q.pop();
      FOR(i,0,TOT){
        v=to[u][i];
        if(!v) {to[u][i]=to[P[u]][i]; continue;}
        q.push(v);

        j=P[u];
        while(j && !to[j][i]) j=P[j];
        P[v]=to[j][i];
      }
    }
  }
  int getNode(int j){  //返回 val[i] 为 j 的 i
    return rval[j];
  }
}ac;

struct ST{
  int n,sg[MAX];
  int sum(int x){
    int ans=0;
    while(x) ans+=sg[x], x-=x&-x;
    return ans;
  }
  int sum(int l, int r){
    return sum(r)-sum(l-1);
  }
  void add(int x, int v){
    while(x<=n) sg[x]+=v, x+=x&-x;
  }
}st;

struct FailTree{
  struct Edge{
    int v,next;
  }edge[MAX];
  int se[MAX],tailE;

  struct Node{
    int l,r;
  }node[MAX];
  int cnt;  // dfs 序（从 1 开始）
  void addEdge(int u, int v){
    edge[tailE]=(Edge){v,se[u]}; se[u]=tailE++;
  }

  void clear(){ //删除所有节点在 ST 中的标记
    MST(st.sg,0);
  }
  void build(int *P, int n){
    tailE=1; cnt=0;
    FOR(i,1,n) addEdge(P[i],i);
    dfs(0); //生成 dfs 序
  }
  void dfs(int u){  //生成 dfs 序
    node[u].l=++cnt;
    for(int i=se[u];i;i=edge[i].next){
      dfs(edge[i].v);
    }
    node[u].r=cnt;
  }
  void traval(int y){ //
    //在 Trie 中从 val 为 Y 的节点开始向前遍历，对每个节点 i 使得在 ST 中的 i 为 1
    int u = ac.getNode(y);
    while(u){
      st.add(node[u].l,1);
      u=ac.fa[u];
    }
    st.add(node[0].l,1);
  }
}ft;

int main(void){
  scanf("%s",t1); ac.init();

  //build Trie from t1
  ac.build(t1,t2); ac.getP();

  //build Fail_Tree from P
  ft.build(ac.P,ac.siz);

  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&Q[i].x,&Q[i].y), Q[i].num=i;
  sort(Q,Q+n);  //sort Q by Y

  int i=0; st.n=ft.cnt;
  while(i<n){
    int Y=Q[i].y; ft.clear();

    ft.traval(Y);

    while(Q[i].y==Y){
      ans[Q[i].num] = st.sum( ft.node[Q[i].x].l, ft.node[Q[i].x].r );
      i++;
    }
  }

  FOR(i,0,n) printf("%d\n",ans[i]);

  return 0;
}
