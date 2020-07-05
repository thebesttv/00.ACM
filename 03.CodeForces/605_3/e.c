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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f; // impossible
int n, v[MAX], f[MAX][2];
VR<int> G[MAX];

struct Node{
  int u, op, f;
  Node(int u, int op, int f):
    u(u), op(op), f(f) { }
};
queue<Node> q;

int main(void){
  scanf("%d",&n);
  MST(f,0x3f);
  FORR(i,1,n){
    scanf("%d",&v[i]);
    q.push({i,v[i]&1,0});
    f[i][v[i]&1]=0;
    if(i+v[i]<=n) G[i+v[i]].push_back(i);
    if(i-v[i]>=1) G[i-v[i]].push_back(i);
  }

  while(!q.empty()){
    Node t = q.front(); q.pop();
#ifdef DEBUG
    printf("  u: %d, op: %d, f: %d\n",t.u,t.op,t.f);
#endif
    int u = t.u;
    for(int v : G[u]){
      if(f[v][t.op] > t.f + 1){
        f[v][t.op] = t.f + 1;
        q.emplace(v, t.op, t.f + 1);
      }
    }
  }

  bool first = 1;
  FORR(i,1,n){
    if(first) first = 0;
    else putchar(' ');

    int op = (v[i]&1) ? 0 : 1;
    printf("%d", f[i][op] == INF ? -1 : f[i][op]);
  }
  putchar('\n');

  return 0;
}

/*
const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f; // impossible
int n, v[MAX], dp[MAX][2];

int f(int u, int op){
  int &a = dp[u][op];
  if(a!=-1) return a;
  if((v[u]&1) == op)
    return a = 0;

  a = -2; // calculating
  int ans = INF;
  if(u + v[u] <= n){
    if(dp[u+v[u]][op] != -2)
      ans = min(ans, f(u+v[u],op) + 1);
  }
  if(u - v[u] >= 1){
    if(dp[u-v[u]][op] != -2)
      ans = min(ans, f(u-v[u],op) + 1);
  }
  return a = ans;
}

int main(void){
  MST(dp,-1); // not calculated
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&v[i]);

  bool first = 1;
  FORR(i,1,n){
    if(first) first = 0;
    else putchar(' ');
    int op = (v[i]&1) ? 0 : 1;
    int ans = f(i,op);
    printf("%d", ans==INF ? -1 : ans);
  }
  putchar('\n');

  return 0;
}
*/
