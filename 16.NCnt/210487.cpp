// Tag: 前后依赖的概率DP iii
// f[i][j]: 长为i的队列中，当前在第j个，符合条件（关门时在前k个）的概率
// (1-p1) * f[i][1] = p2 * f[i][i] + p4
// (1-p1) * f[i][2<=j<=k] = p2 * f[i][j-1] + p3 * f[i-1][j-1] + p4
// (1-p1) * f[i][k< j<=i] = p2 * f[i][j-1] + p3 * f[i-1][j-1]
// 每个 f[i][j] 都是依赖 f[i][i] 的，因此令 f[i][j] = a[j] * f[i][i] + b[j]
// 则 a[1] = p2 / (1-p1), b[1] = p4 / (1-p1)
// 之后对 j = 2:i 递推 a[j],b[j]
// 则 f[i][i] = b[i] / (1-a[i])
// 最后对 j = 1:i-1，算出 f[i][j] = a[j] * f[i][i] + b[j] 即可
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

const int MAX = 2020;
int n,m,k; double p1,p2,p3,p4;
double f[MAX][MAX],a[MAX],b[MAX]; // f[i][j] = a[j] * f[i][i] + b[j]

int main(void){
  cin >> n >> m >> k >> p1 >> p2 >> p3 >> p4;
  f[1][1] = p4 / (1-p1-p2);
  FORR(i,2,n){
    // (1-p1) * f[i][1] = p2 * f[i][i] + p4
    a[1] = p2 / (1-p1), b[1] = p4 / (1-p1);
    FORR(j,2,i){
      a[j] = p2 * a[j-1] / (1-p1);
      b[j] = (p2 * b[j-1] + p3 * f[i-1][j-1] + (j<=k ? p4 : 0)) / (1-p1);
    }
    f[i][i] = b[i] / (1-a[i]);
    FOR(j,1,i) f[i][j] = a[j] * f[i][i] + b[j];
  }
  printf("%.5lf\n",f[n][m]);

  return 0;
}
