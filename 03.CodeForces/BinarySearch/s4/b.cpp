// Tag: 二分 i
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
const double EPS = 1e-4;
const int INF = 0x3f3f3f3f;
int n,m,r[MAX]; double d[MAX], f[MAX];
struct Edge { int v,w; };
VR<Edge> G[MAX];

bool vis[MAX];

double dcmp(double x){
  return fabs(x) < EPS ? 0 : x < 0 ? -1 : 1;
}

void dfs(int u, double x){
  if(vis[u]) return;
  vis[u] = 1; d[u] = INF;
  for(Edge &e : G[u]) if(u < e.v){
    dfs(e.v, x);
    if(dcmp(d[u] - (d[e.v] + e.w - x)) > 0){
      d[u] = d[e.v] + e.w - x; r[u] = e.v;
    }
  }
}

bool ok(double x){
  MST(vis,0); d[n] = 0; vis[n] = 1;
  dfs(1, x);
#ifdef DEBUG
  printf("ok(%.2lf):",x);
  FORR(i,1,n) dfs(i, x), printf(" %.2lf",d[i]); putchar('\n');
#endif
  return d[1] <= 0;
}

void print(){
  VR<int> v; int u = 1; v.pb(1);
  while(u != n){
    u = r[u]; v.pb(u);
  }
  printf("%d\n",(int)v.size() - 1);
  for(int x : v) printf("%d ",x); putchar('\n');
}

int main(void){
  n = read(), m = read();
  while(m--){
    int u = read(), v = read(), w = read();
    G[u].pb({v,w}), G[v].pb({u,w});
  }
  double l = -1, r = 101;
  while(r - l > EPS){
    double m = (l+r)/2;
    if(ok(m)) r = m;
    else l = m;
  }

  while(!ok(l)) l += EPS;
  print();

  return 0;
}

