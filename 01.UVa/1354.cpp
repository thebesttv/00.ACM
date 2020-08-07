// Tag: iiii 二叉树枚举 子集枚举
// 枚举左右子树集合
// 子集枚举:
//   for(int left = (st-1)&st; left; left = (left-1)&st){ // left, right 非空
//     right = st ^ left;
//   }
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<double,double> pii;

const int MAX = 10;
int n,v[MAX],sum[1<<MAX]; double r;
VR<pii> tree[1<<MAX];
bool vis[1<<MAX];

void dfs(int st){
  if(vis[st]) return;
  vis[st] = 1;

  if((st-1)&st){
    for(int left = (st-1)&st; left; left = (left-1)&st){
      int right = st ^ left;
      dfs(left), dfs(right);

      double dl = 1.0 * sum[right] / sum[st];
      double dr = 1.0 * sum[left] / sum[st];

      for(auto pl : tree[left]) for(auto pr : tree[right]){
        pii p { max(pl.FI + dl, pr.FI - dr), max(pr.SE + dr, pl.SE - dl) };
        if(p.FI + p.SE < r) tree[st].push_back(p);
      }
    }
  }else tree[st].push_back({0,0});  // leaf
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lf%d",&r,&n);
    FOR(i,0,n) scanf("%d",&v[i]);
    FOR(st,0,1<<n){
      sum[st] = 0; vis[st] = 0;
      tree[st].clear();
      FOR(j,0,n) if(st&(1<<j))
        sum[st] += v[j];
    }

    int root = (1<<n)-1; dfs(root);

    double ansMax = -1;
    for(auto p : tree[(1<<n)-1])
      ansMax = max(ansMax,p.FI+p.SE);
    if(ansMax < 0) printf("-1\n");
    else printf("%.12lf\n",ansMax);
  }

  return 0;
}
