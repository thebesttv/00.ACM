// Tag: 可出题
// 把 n 变成 1e5 ？
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

int n,a[20];

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1){
    FORR(i,1,n) scanf("%d",&a[i]);
    LL ansMax = 0;
    FORR(l,1,n) FORR(r,l,n){
      LL t = 1; FORR(k,l,r) t *= a[k];
      ansMax = max(ansMax, t);
    }
    printf("Case #%d: The maximum product is %lld.\n\n",++kase,ansMax);
  }

  return 0;
}
