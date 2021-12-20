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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

LL cnt(LL n){
  LL ans=0; LL sq=sqrt(n);
  for(LL i=1;i<=sq;i++)
    if(n%i==0) ans+=2;
  if(sq*sq==n) ans--;
  return ans;
}

const int MAX=100000;
VR<LL> a[MAX];

int main(void){
  for(LL i=1;i<=100000;i++){
    a[cnt(i)].push_back(i);
  }
  FORR(i,1,MAX) if(a[i].size()){
    printf("%lld:",i);
    FOR(j,0,a[i].size()) printf(" %d",a[i][j]);
    printf("\n");
  }

  return 0;
}
