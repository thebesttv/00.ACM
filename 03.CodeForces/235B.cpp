// Tag: 概率DP 递推 i
// 对第 i 个，贡献为 2k - 1 的概率为 (1 - p[i-k]) * p[i-k+1] * p[i-k+2] * ... * p[i]
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
int n; double p[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%lf",&p[i]);
  double ans = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
  FORR(i,1,n){
    x2 = (1 + x2 + 2 * x1) * p[i];
    x1 = (x1 + 1) * p[i];
    x4 = (p[i-1] + x4 + 2 * x3) * p[i];
    x3 = (x3 + p[i-1]) * p[i];
    ans += x2 - x4;
  }
  printf("%.10lf\n",ans);

  return 0;
}
