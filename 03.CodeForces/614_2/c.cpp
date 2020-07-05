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

const int MAX = 1e5 + 20;
int n, q;
bool G[2][MAX];

int main(void){
  scanf("%d%d",&n,&q);
  int r, c, cnt = 0;
  FOR(i,0,q){
    scanf("%d%d",&r,&c);
    --r, --c;
    if(!G[r][c]){ // ground -> lava
      if(G[r^1][c]) ++cnt;
      if(c > 0 && G[r^1][c-1]) ++cnt;
      if(c < n-1 && G[r^1][c+1]) ++cnt;
    }else{  // lava
      if(G[r^1][c]) --cnt;
      if(c > 0 && G[r^1][c-1]) --cnt;
      if(c < n-1 && G[r^1][c+1]) --cnt;
    }
    G[r][c] = !G[r][c];
    printf("%s\n", cnt==0 ? "Yes" : "No");
  }

  return 0;
}
