// Tag: notag
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

const int MAX = 120;
int n,m; char G[MAX][MAX];
bool vis[MAX][MAX];

queue<pii> q;
void bfs(int x, int y){
  q.push({x,y}); vis[x][y] = 1;
  while(!q.empty()){
    auto t = q.front(); q.pop();
    FORR(dx,-1,1) FORR(dy,-1,1){
      int tx = t.FI + dx,
          ty = t.SE + dy;
      if(tx<1 || ty<1 || tx>n || ty>m) continue;
      if(vis[tx][ty] || G[tx][ty]=='*') continue;
      q.push({tx,ty}); vis[tx][ty] = 1;
    }
  }
}

int main(void){
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(vis,0);
    FORR(i,1,n) scanf("%s",G[i]+1);
    int cnt = 0;
    FORR(i,1,n) FORR(j,1,m) if(G[i][j]=='@' && !vis[i][j])
      bfs(i,j), ++cnt;
    printf("%d\n",cnt);
  }

  return 0;
}
