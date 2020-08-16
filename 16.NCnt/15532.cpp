// Tag: 概率期望
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

double k,x,l,r,ans;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%lf%lf",&k,&x);
    l = max(k-x, 0.); r = min(k, x);
    if(l <= r) ans = ((r-l) * (x-k) + (r*r - l*l) / 2) / (x*x) + (x-r)/x;
    else ans = 0;
    printf("%.2lf\n",ans);
  }

  return 0;
}
