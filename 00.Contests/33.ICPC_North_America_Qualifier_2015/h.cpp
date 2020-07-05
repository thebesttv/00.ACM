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

const int MAX_ = 10020, MAX = 120;
int n; char G[MAX][MAX], s[MAX_];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s); n = strlen(s);
    int x = 0, y = 0, r = 1, r2;
    while(r * r < n) ++r;
    r2 = r * r;

    FOR(i,0,r2){
      G[x][y] = i < n ? s[i] : '*';
      if(y == r-1){
        y = 0; ++x;
      }else ++y;
    }
    FOR(j,0,r) ROR(i,r-1,0)
      if(G[i][j]!='*') putchar(G[i][j]);
    putchar('\n');
  }

  return 0;
}
