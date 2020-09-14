// Tag: iii 转化 DP
// 每个人的话等价于：排名为 a+1，算上自己有 n-a-b 个人和自己分数相同
// 即将所有人分数降序排列，[a+1, n-b] 内的人分数相同
// 显然，如果 n-a-b < 1 则必为假
// 则转化为有 m 个区间，每个区间 [l,r] 权值为 min(r-l+1, 说 [l,r] 的人数)
// 取不相交的区间，使得权值和最大
// 令 f[i] 表示选到点 i 时的最大权
//  f[i] = max{f[i-1], f[lj - 1] + vj | rj = i}
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

const int MAX = 1e5 + 20;
int n,f[MAX]; VR<int> v[MAX];
VR<pii> v2[MAX];

int main(void){
  scanf("%d",&n);
  int a,b;
  FOR(i,0,n){
    scanf("%d%d",&a,&b);
    if(n-a-b<1) continue;
    v[n-b].pb(a+1);
  }

  FORR(r,1,n) if(!v[r].empty()){
    sort(ALL(v[r]));
    int last = -1, cnt = 0;
    for(int l : v[r]){
      if(l != last){
        if(last != -1) v2[r].pb({last, min(cnt, r-last+1)});
        last = l, cnt = 1;
      }else ++cnt;
    }
    if(last != -1) v2[r].pb({last, min(cnt, r-last+1)});
  }

  FORR(i,1,n){
    f[i] = f[i-1];
    for(auto p : v2[i])
      f[i] = max(f[i], f[p.FI-1] + p.SE);
  }
  printf("%d\n",n-f[n]);

  return 0;
}
