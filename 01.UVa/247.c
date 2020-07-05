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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAXN=30, MAXM=MAXN*MAXN;
int n,m;

struct Edge{
  int v,w; Edge *next;
};
struct Base{
  Edge edge[MAXM], *head[MAXN];
  int tail=0;
  void addEdge(int u, int v, int w){
    edge[tail]=Edge{v,w,head[u]}; head[u] = edge + tail++;
  }
};

struct Tarjan: public Base{
  int n;
  int dfn[MAXN], dfscnt=0, low[MAXN];
  stack<int> st; bool inst[MAXN];
  int belong[MAXN], sccnt=0;

  void init(int _n){
    n = _n;
    MST(head,0); tail=0;
    MST(dfn,0); dfscnt=0; MST(low,0);
    while(!st.empty()) st.pop();
    MST(inst,0); MST(belong,0); sccnt=0;
  }

  void tarjan(){
    FORR(i,1,n) if(!dfn[i])
      tarjan(i);
  }
  void tarjan(int u){
    int v;
    dfn[u] = low[u] = ++dfscnt;
    st.push(u); inst[u]=1;

    for(Edge *e=head[u];e;e=e->next){
      v = e->v;
      if(!dfn[v]){
        tarjan(v);
        if(low[u] > low[v])
          low[u] = low[v];
      }else if(inst[v] && low[u] > dfn[v]){
        low[u] = dfn[v];
      }
    }

    if(dfn[u]!=low[u]) return;
    ++sccnt;
    do{
      v = st.top(); st.pop();
      inst[v]=0; belong[v]=sccnt;
    }while(v!=u);
  }
}tar;

map<string, int> mp;
string v[MAXN];
int cnt=0;
int ID(string &s){
  if(mp.count(s)) return mp[s];
  mp[s]=++cnt; v[cnt]=s;
  return cnt;
}

bool vis[MAXN];

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&m)==2 && n){
    mp.clear(); cnt=0; tar.init(n);

    FOR(i,0,m){
      string s1, s2; cin >> s1 >> s2;
      int u = ID(s1), v = ID(s2);
      tar.addEdge(u,v,1);
    }

    tar.tarjan();

    if(kase) putchar('\n');
    printf("Calling circles for data set %d:\n",++kase);
    FORR(i,1,tar.sccnt){
      bool first=1;
      FORR(j,1,n) if(tar.belong[j]==i){
        if(first) first=0;
        else printf(", ");
        cout << v[j];
      }
      putchar('\n');
    }
  }

  return 0;
}

/*
const int MAX=30;
int n,m; bool G[MAX][MAX];

map<string, int> mp;
string v[MAX];
int cnt=0;
int ID(string &s){
  if(mp.count(s)) return mp[s];
  mp[s]=++cnt; v[cnt]=s;
  return cnt;
}

bool vis[MAX];
int p[MAX];
int fa(int x){
  return p[x]<0 ? x : p[x]=fa(p[x]);
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&m)==2 && n){
    mp.clear(); cnt=0; MST(G,0); MST(vis,0); MST(p,-1);

    FORR(i,1,n) G[i][i]=1;
    FOR(i,0,m){
      string s1, s2; cin >> s1 >> s2;
      int u = ID(s1), v = ID(s2);
      G[u][v]=1;
    }
    FORR(k,1,cnt) FORR(i,1,cnt) FORR(j,1,cnt)
      G[i][j] = G[i][j] || (G[i][k] && G[k][j]);

    if(kase) putchar('\n');
    printf("Calling circles for data set %d:\n",++kase);
    FORR(i,1,cnt) if(!vis[i]){
      bool first=1;
      FORR(j,i,cnt) if(G[i][j] && G[j][i] && !vis[j]){
        if(first) first=0;
        else printf(", ");
        cout << v[j]; vis[j]=1;
      }
      putchar('\n');
    }
  }

  return 0;
}
*/
