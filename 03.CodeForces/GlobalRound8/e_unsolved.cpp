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

const int MAX = 2e5 + 20;
int n,m,G[MAX][2],in[MAX],q[MAX],head,tail;
int f[MAX][2], r[MAX][2];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    int u, v;
    while(m--){
      scanf("%d%d",&u,&v);
      if(G[u][0]) G[u][1] = v;
      else G[u][0] = v;
      ++in[v];
    }
    head = tail = 0;
    FORR(i,1,n) if(!in[i])
      q[tail++] = i;
    while(head < tail){
      u = q[head++];
      if(v = G[u][0]){
        --in[v];
        if(!in[v]) q[tail++] = v;

        if(v = G[u][1]){
          --in[v];
          if(!in[v]) q[tail++] = v;
        }
      }
    }

    ROR(i,tail-1,0){
      u = q[i];
      if(!G[u][0]){ // leaf
        f[u][0] = f[u][1] = 0;
      }else{
      }
    }
  }

  return 0;
}
