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
#include<numeric>
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

const int MAX = sqrt(INT_MAX+0.5);
LL n; VR<int> prime;
bool vis[MAX+20];

void divide(LL n, VR<LL> &res){
  for(int p : prime) if(n%p==0){
    int t = 1;
    while(n%p==0){
      n/=p, t*=p;
    }
    res.push_back(t);
    if(n==1) return;
  }
  res.push_back(n);
}

int main(void){
  FORR(i,2,MAX) if(!vis[i]){
    prime.push_back(i);
    for(int j=i*i;j<=MAX;j+=i) vis[j]=1;
  }

  int kase=0;
  while(scanf("%lld",&n)==1 && n){
    LL ans;
    if(n==1) ans = 2;
    else{
      VR<LL> res;
      divide(n,res);
#ifdef DEBUG
      for(LL x : res) printf(" %lld",x); putchar('\n');
#endif
      if(res.size()==1) ans = n+1;
      else ans = accumulate(ALL(res),0);
    }
    printf("Case %d: %lld\n",++kase,ans);
  }

  return 0;
}
