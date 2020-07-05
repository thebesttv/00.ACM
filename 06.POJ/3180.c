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

const int MAX=10020;
int n,m; VR<int> G[MAX];

int dfn[MAX], dfscnt=0, low[MAX];
int sc[MAX], sccnt=0;
stack<int> st; bool ins[MAX];

void tarjan(int u){
  dfn[u]=low[u]=++dfscnt;
  st.push(u); ins[u]=1;
  //for(int v : G[u]){
  int v;
  FOR(i,0,G[u].size()){
    v=G[u][i];
    if(!dfn[v]){
      tarjan(v);
      if(low[v]<low[u])
        low[u]=low[v];
    }else if(ins[v] && dfn[v]<low[u]){
      low[u]=dfn[v];
    }
  }
  if(dfn[u]==low[u]){
    sccnt++;
    do{
      v=st.top(); st.pop();
      ins[v]=0; sc[sccnt]++;
    }while(v!=u);
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  while(m--){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
  }

  FORR(i,1,n) if(!dfn[i])
    tarjan(i);

  int cnt=0;
  FORR(i,1,sccnt) if(sc[i]>1) cnt++;
  printf("%d\n",cnt);

  return 0;
}
