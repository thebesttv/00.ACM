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

const int MAX = 40;
const int to[8][2] = {{-2,-1},{-2,1},{2,-1},{2,1},{-1,-2},{1,-2},{-1,2},{1,2}};
int n,x1,Y1,x2,y2;
bool vis[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(vis,0);
    scanf("%d%d%d%d%d",&n,&x1,&Y1,&x2,&y2);

    queue<pair<pii,int>> q;
    q.push({{x1,Y1},0}); vis[x1][Y1] = 1;

    int ans = -1;
    while(!q.empty()){
      auto t = q.front(); q.pop();
      if(t.FI.FI == x2 && t.FI.SE == y2){
        ans = t.SE; break;
      }
      FOR(d,0,8){
        int tx = t.FI.FI + to[d][0],
            ty = t.FI.SE + to[d][1];
        if(tx < 1 || tx > n || ty < 1 || ty > n || vis[tx][ty])
          continue;
        vis[tx][ty] = 1;
        q.push({{tx,ty},t.SE+1});
      }
    }
    printf("Case #%d: %d\n\n",kase,ans);
  }

  return 0;
}
