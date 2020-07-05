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

const int MAX = 1000;
int n, m;
VR<int> G[MAX];

int main(void){
  scanf("%d",&n); m = n*(n-1)/2;
  int u, v, w;
  while(m--){
    scanf("%d%d%d",&u,&v,&w);
    G[u].push_back(w);
    G[v].push_back(w);
  }
  LL ans = 0;
  FORR(i,1,n){
    sort(ALL(G[i]));
    for(int j=0;j<G[i].size();j+=2)
      ans += G[i][j+1];
  }
  printf("%lld\n",ans);

  return 0;
}
