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

const int MAX = 1e5;
int n,r; bool vis[MAX+20];
VR<int> prime;
int ans;

int main(void){
  FORR(i,2,MAX) if(!vis[i]){
    prime.push_back(i);
    for(LL j=LL(i)*i;j<=MAX;j+=i) vis[j]=1;
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); r = sqrt(n+0.5);
    if(n==2 || n==3) { printf("%d\n",n); continue; }

    LL ans = n; int cnt = 0;
    for(int x : prime){
      if(x > r) break;
      ans = ans - ceil(1.0*ans / x);
      ++cnt;
    }
    ans += cnt;
    printf("%lld\n",ans);
  }

  return 0;
}
