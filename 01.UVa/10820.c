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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int n, phi[MAX];

void init(int n){
  phi[1] = 1;
  FORR(i,2,n) if(!phi[i]){
    for(int j=i;j<=n;j+=i){
      if(!phi[j]) phi[j]=j;
      phi[j] = phi[j] / i * (i-1);
    }
  }
}

int main(void){
  init(50000);
  FORR(i,2,50000) phi[i]+=phi[i-1];

  while(scanf("%d",&n)==1 && n){
    printf("%d\n",phi[n] * 2 - 1);
  }

  return 0;
}
