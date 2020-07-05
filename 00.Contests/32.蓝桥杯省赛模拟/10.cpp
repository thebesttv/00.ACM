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

const int MAX = 1020;
int n;

struct Node{
  int x,y,h;
}node[MAX];

double cost(const Node &a, const Node &b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))
          + (a.h-b.h)*(a.h-b.h);
}

struct Edge{
  int u,v; double w;
  bool operator < (const Edge &e) const {
    return w < e.w;
  }
}edge[MAX*MAX];
int tail = 0;

int fa[MAX];
int p(int x){
  return fa[x] < 0 ? x : fa[x] = p(fa[x]);
}

double rnd(double x){
  int t = (x + 0.00501) * 100;
  return t / 100.0;
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].h);
    FOR(j,1,i) edge[tail++] = {i,j,cost(node[i],node[j])};
  }
  sort(edge, edge+tail);

  MST(fa,-1); int cnt = 0;
  double ans = 0;
  FOR(i,0,tail){
    Edge &e = edge[i];
    int x = p(e.u), y = p(e.v);
    if(x==y) continue;
    ans += e.w; fa[x] = y;
    if(++cnt == n-1)
      break;
  }
  printf("%.2lf\n", rnd(ans));

  return 0;
}
