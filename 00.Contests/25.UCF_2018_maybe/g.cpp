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

const int MAX = 200000 + 20;
const LL MOD = 1000000007;
int n; char s[MAX];

LL sum(LL l, LL r){
  if(l>r) return 0;
  return (l+r)*(r-l+1)/2%MOD;
}

int main(void){
  scanf("%d%s",&n,s+1);
  int last = 0;
  LL ans = 0;
  FORR(i,1,n){
    if(s[i]=='1') last = i;
    ans = (ans + last*sum(i-last+1,i))%MOD;
  }
  printf("%lld\n",ans);

  return 0;
}
