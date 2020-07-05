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

const int MAX = 200;
int n, up[MAX][MAX];
char G[MAX][MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%s",G[i]+1);
    FORR(j,1,n) if(G[i][j]=='W')
      up[i][j] = (G[i-1][j]=='W' ? up[i-1][j] : 0) + 1;
  }

  int ans = 0;
  FORR(i,1,n) FORR(j,1,n) if(G[i][j]=='W'){
    int h = 0x3f3f3f3f;
    FORR(k,0,n-j){
      if(G[i][j+k]!='W') break;
      h = min(h, up[i][j+k]);
      ans += h;
    }
  }
  printf("%d\n",ans);

  return 0;
}
