// Tag: 概率DP
// 取出n次后，共有n+2个球，因此第i次之前，有i+1个球
// f[i] = f[i-1] / (i+1) * (f[i-1] + 1) + (i+1 - f[i-1]) / (i+1) * f[i-1]
//      = f[i-1] * (1 + 1/(i+1)) = f[i-1] * (i+2) / (i+1)
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

const int MAX = 1e6+20;
int n; double f[MAX];

int main(void){
  scanf("%d",&n);
  f[0] = 1;
  FORR(i,1,n) f[i] = f[i-1] * (i+2)/(i+1);
  printf("%.7lf\n",f[n]);

  return 0;
}
