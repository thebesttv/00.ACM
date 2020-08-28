// Tag: 前后依赖的概率DP ii
// p[k]: 扔出 x+y+z = k 并且得分不清零的可能
// p[0]: 得分清零的可能
// f[x>=n] = 0
// f[x] = sum{ p[k] * f[x+k] } + p[0] * f[0] + 1
// 令 f[x] = a[x] * f[0] + b[x]
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

const int MAX = 1020;
int n,k1,k2,k3,ka,kb,kc,cnt[MAX];
double a[MAX],b[MAX],p[MAX];

int main(void){
  cin >> n >> k1 >> k2 >> k3 >> ka >> kb >> kc;
  FORR(i,1,k1) FORR(j,1,k2) FORR(k,1,k3) ++cnt[i+j+k];
  --cnt[ka+kb+kc]; ++cnt[0];
  int sum = k1 * k2 * k3, sk = k1+k2+k3;
  FORR(i,0,sk) p[i] = 1.0*cnt[i]/sum;
#ifdef DEBUG
  FORR(i,0,sk) printf("cnt[%d]: %d, p[%d]: %.2lf\n",i,cnt[i],i,p[i]);
#endif

  ROR(i,n,0){
    a[i] = p[0], b[i] = 1;
    FORR(k,3,sk){
      a[i] += p[k]*a[i+k];
      b[i] += p[k]*b[i+k];
    }
  }
  double ans = b[0] / (1 - a[0]);
  printf("%.10lf\n",ans);

  return 0;
}
