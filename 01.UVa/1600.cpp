// Tag: BFS
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

const int MAX = 24;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,k,G[MAX][MAX],vis[MAX][MAX][MAX];
struct Node { int x,y,d,c; };

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0); scanf("%d%d%d",&n,&m,&k);
    FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);
    queue<Node> q; q.push({1,1,0,0});
    vis[1][1][0] = 1; int ans = -1;
    while(!q.empty()){
      Node t = q.front(); q.pop();
      if(t.x == n && t.y == m){
        ans = t.d; break;
      }
      FOR(d,0,4){
        int tx = t.x + to[d][0],
            ty = t.y + to[d][1];
        if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
        if(G[tx][ty]){
          if(t.c >= k || vis[tx][ty][t.c+1]) continue;  // no more turbo
          q.push({tx,ty,t.d+1,t.c+1}); vis[tx][ty][t.c+1] = 1;
        }else{
          if(vis[tx][ty][0]) continue;
          q.push({tx,ty,t.d+1,0}); vis[tx][ty][0] = 1;
        }
      }
    }
    printf("%d\n",ans);
  }

  return 0;
}
