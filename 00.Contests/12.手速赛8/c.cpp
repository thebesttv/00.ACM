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

int n, q;
char a[100][3], b[100][2];
LL f[10][128];

int main(void){
  scanf("%d%d",&n,&q);
  FOR(i,0,q){
    scanf("%s%s",a[i],b[i]);
  }
  f[1]['a'] = 1;
  FOR(i, 1, n) FORR(ch,'a','f') FOR(k,0,q) if(ch == b[k][0]){
    f[i+1][a[k][0]] += f[i][ch];
  }
  LL ans = 0;
  FORR(ch,'a','f') ans += f[n][ch];
  printf("%lld\n",ans);

  return 0;
}
