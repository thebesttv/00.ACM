// Tag: iii
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

const int MAX = 100020;
const int INF = 0x3f3f3f3f;
int n,m,d[MAX];
struct Edge { int v,c; };
VR<Edge> G[MAX];

void bfs(int u){
  queue<int> q; q.push(u);
  FORR(i,1,n) d[i] = INF; d[u] = 0;
  while(!q.empty()){
    u = q.front(); q.pop();
    for(Edge e : G[u]) if(d[e.v] == INF){
      q.push(e.v); d[e.v] = d[u] + 1;
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    FORR(i,1,n) G[i].clear();
    int u,v,c;
    while(m--){
      scanf("%d%d%d",&u,&v,&c);
      G[u].push_back({v,c});
      G[v].push_back({u,c});
    }

    bfs(n); printf("%d\n",d[1]);
    set<int> st; st.insert(1);  // 用 set 防止一点访问多次
    bool first = 1;
    while(true){
      int cMin = INF; set<int> st2;
      for(int u : st) for(Edge e : G[u]) if(d[e.v]+1 == d[u]){
        if(e.c == cMin) st2.insert(e.v);
        else if(e.c < cMin){
          cMin = e.c; st2.clear(); st2.insert(e.v);
        }
      }
      if(st2.empty()) break;
      if(first) first = 0;
      else putchar(' ');
      printf("%d",cMin);
      st = st2;
    }
    putchar('\n');
  }

  return 0;
}
