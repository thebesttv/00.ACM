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

LL a,b,n;
LL ansMax = 0;

void cal(LL k){
  b = k * n / (k-1);
  a = (k*n)^b;
  ansMax = max(a, ansMax);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ansMax = 0;
    scanf("%lld",&n);
    int r = sqrt(n+0.5);
    FORR(i,1,r) if(n%i==0){
      cal(i+1);
      cal(n/i+1);
      // LL k = i+1;
      // printf("kn: %lld, k-1: %lld, %lld\n",k*n,k-1,k*n%(k-1));
    }
    printf("%lld\n",ansMax);
  }

  return 0;
}
