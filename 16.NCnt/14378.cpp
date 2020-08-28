// Tag: 概率DP 优化 i
// 对每个 i = n:1，找最大的j，使得 s[j]-s[i-1]<=x
// 显然j是递减的，因此无需二分
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

const int MAX = 100000 + 20;
int n,m,x,a[MAX],aMax,s[MAX];
double f[MAX],g[MAX];

int get(int l){ // biggest r such that sum(a[l:r]) <= x
  int r = upper_bound(s+1, s+1+n, x + s[l-1]) - s;
  while(r>n || s[r]-s[l-1] > x) --r;
  return r;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), aMax = max(aMax, a[i]), s[i]=s[i-1]+a[i];
  while(m--){
    scanf("%d",&x);
    if(x < aMax) { printf("YNOI is good OI!\n"); continue; }
    g[n+1] = g[n+2] = 0;
    int j = n;
    ROR(i,n,1){
      // int j = get(i);
      while(j>i && s[j]-s[i-1]>x) --j;  // j 递减
      f[i] = (g[i+1] - g[j+2])/(j-i+1) + 1;
      g[i] = g[i+1] + f[i];
    }
    printf("%.2lf\n",f[1]);
  }

  return 0;
}
