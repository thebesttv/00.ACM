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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
int n,k,s,m[MAX],dfn[MAX][2];
VR<int> G[MAX];
LL sum[MAX];

struct Query{
  int op,u,x;
}Q[MAX];

int dfncnt=0;
void dfs(int u){
  dfn[u][0] = ++dfncnt;
  for(int v : G[u]) dfs(v);
  dfn[u][1] = dfncnt;
}

struct ST{
  int n; LL v[MAX];
  LL sum(int x){
    LL s = 0;
    while(x) s += v[x], x-=x&-x;
    return s;
  }
  void _add(int x, LL val){
    while(x<=n) v[x]+=val, x+=x&-x;
  }
  void add(int l, int r, LL val){
    _add(l,val); _add(r+1,-val);
  }
  void clear(int x){
    add(x,x,-sum(x));
  }
}st;

int main(void){
  n = 1;
  scanf("%d%d",&k,&s);
  int op,u,x;
  FOR(i,0,k){
    scanf("%d%d",&op,&u);
    if(op==1) G[u].push_back(++n);
    if(op==2 || op==3) scanf("%d",&x);
    Q[i] = {op,u,x};
  }

  dfs(1);

  m[1] = s;
  st.n = n; n = 1;
  FOR(i,0,k){
    Query &q = Q[i];
    if(q.op==1){
      m[++n] = s;
      st.clear(dfn[n][0]);
    }else if(q.op==2){
      sum[q.u] += st.sum(dfn[q.u][0]) * m[q.u];
      st.clear(dfn[q.u][0]);
      m[q.u] = q.x;
    }else if(q.op==3){
      st.add(dfn[q.u][0],dfn[q.u][1],q.x);
    }else{
      printf("%lld\n",sum[q.u] + m[q.u]*st.sum(dfn[q.u][0]));
    }
  }

  return 0;
}
