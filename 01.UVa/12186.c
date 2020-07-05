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

const int MAX=100020;
int n,t;
VR<int> son[MAX];

int dp(int u){
  if(son[u].empty()) return 1;
  VR<int> d;
  for(int v : son[u]){
    d.push_back(dp(v));
  }
  sort(d.begin(),d.end());
  int tot = ceil( t * son[u].size() / 100.0 );
  int ans=0; FOR(i,0,tot) ans += d[i];
  return ans;
}

int main(void){
  while(scanf("%d%d",&n,&t)==2 && n){
    FORR(i,0,n) son[i].clear();
    for(int u,v=1;v<=n;v++){
      scanf("%d",&u); son[u].push_back(v);
    }
    printf("%d\n",dp(0));
  }

  return 0;
}
