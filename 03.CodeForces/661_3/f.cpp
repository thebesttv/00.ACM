// Tag: DP DAG
// f[i]: 线段 [li, ri] 区间内可包含的合法线段数
// 对每个 f[i] 分别 DP，类似树上背包
// 显然区间的包含构成一个DAG，因此DP成立
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

const int MAX = 3020;
int n, dp[MAX], vv[MAX][MAX], vv2[MAX][MAX];
struct Node{
  int l, r;
  bool operator < (const Node &b) const {
    return r < b.r;
  }
}v[MAX];

bool overlap(const Node &a, const Node &b){
  return a.l <= b.l && b.r <= a.r;
}

int f(int i){
  int &a = dp[i];
  if(a!=-1) return a;
  a = 1; VR<int> vec;
  FORR(j,1,n) if(i!=j && overlap(v[i],v[j])) vec.pb(j);
  sort(ALL(vec), [&](int x, int y){
    return v[x].r < v[y].r;
  });
#ifdef DEBUG
  printf("[%d, %d]:",v[i].l,v[i].r);
  for(int x : vec) printf(" [%d, %d]",v[x].l,v[x].r); putchar('\n');
#endif
  int *g = vv[i], *h = vv2[i];
  FOR(j,0,vec.size()){
    g[j] = f(vec[j]);
    int l = 0, r = j;
    while(l < r){
      int m =(l+r+1)/2;
      if(v[vec[m]].r < v[vec[j]].l) l = m;
      else r = m-1;
    }
    if(v[vec[l]].r < v[vec[j]].l)
      g[j] = f(vec[j]) + h[l];

    /*
    FOR(k,0,j) if(v[vec[k]].r < v[vec[j]].l){
      g[j] = max(g[j], g[k] + f(vec[j]));
    }
    */
    a = max(a, g[j] + 1);

    if(!j) h[j] = g[j];
    else h[j] = max(h[j-1], g[j]);
  }
#ifdef DEBUG
  printf("f([%d, %d]): %d\n",v[i].l,v[i].r,a);
#endif
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(dp,-1); scanf("%d",&n);
    FORR(i,1,n) scanf("%d%d",&v[i].l, &v[i].r);
    v[0] = {0,int(2e5+20)};

    printf("%d\n",f(0)-1);
  }

  return 0;
}
