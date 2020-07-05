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
int n,m; char s[MAX][12];
struct Edge{
  int u,v,w;
  bool operator < (const Edge &b) const {
    return w < b.w;
  }
};
VR<Edge> edge;

int diff(char *s1, char *s2){
  int sum = 0;
  FOR(i,0,m) if(s1[i] != s2[i]) ++sum;
  return sum;
}

int fa[MAX];
int p(int x){
  return fa[x] < 0 ? x : fa[x] = p(fa[x]);
}

int main(void){
  MST(fa,-1);
  scanf("%d%d",&n,&m);

  FORR(i,1,n){
    scanf("%s",s[i]);
    FOR(j,1,i) edge.push_back({i,j,diff(s[i],s[j])});
  }
  sort(ALL(edge));

  VR<pii> ansv;
  int cnt = 0, ans = 0;
  for(Edge &e : edge){
    int x = p(e.u), y = p(e.v);
    if(x == y) continue;
    fa[x] = y; ans += e.w;
    ansv.push_back({e.u-1,e.v-1});
    if(++cnt >= n-1) break;
  }
  printf("%d\n",ans);
  for(auto p : ansv) printf("%d %d\n",p.SE,p.FI);

  return 0;
}
