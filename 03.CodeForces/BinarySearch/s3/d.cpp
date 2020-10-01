// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 1e5 + 20;
const int INF = 0x3f3f3f3f;
int n,m,dis,d[MAX];
struct Edge{
  int v,w;
};
VR<Edge> G[MAX];

bool ok(int x){
  MST(d,0x3f); queue<int> q;
  q.push(n); d[n] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(Edge &e : G[u]) if(e.v < u && e.w <= x && d[e.v] == INF){
      d[e.v] = d[u] + 1;
      q.push(e.v);
    }
  }
#ifdef DEBUG
  printf("ok(%d): d[1]: %d\n",x,d[1]);
#endif
  return d[1] <= dis;
}

void print(int x){
  int u = 1; VR<int> v; v.pb(1);
  while(u != n){
    for(Edge &e : G[u]) if(e.v > u && e.w <= x && d[e.v] + 1 == d[u])
      v.pb(u = e.v);
  }
  printf("%d\n",(int)v.size() - 1);
  for(int x : v) printf("%d ",x); putchar('\n');
}

int main(void){
  n = read(), m = read(), dis = read();
  while(m--){
    int u = read(), v = read(), w = read();
    G[u].pb({v,w}); G[v].pb({u,w});
  }
  int l = 0, r = 1e9;
  while(l < r){
    int m = (l+r)/2;
    if(ok(m)) r = m;
    else l = m+1;
  }

  if(!ok(l)) printf("-1\n");
  else print(l);

  return 0;
}

