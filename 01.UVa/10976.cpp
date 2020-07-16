// Tag: 可出题
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

int k;

int main(void){
  while(scanf("%d",&k)==1){
    VR<pii> ans;
    FORR(y,k+1,k*2) if(k*y % (y-k) == 0){
      ans.push_back({k*y/(y-k),y});
    }
    printf("%d\n",(int)ans.size());
    for(auto p : ans) printf("1/%d = 1/%d + 1/%d\n",k,p.FI,p.SE);
  }

  return 0;
}
