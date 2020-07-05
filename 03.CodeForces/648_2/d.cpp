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

const int MAX = 60;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m; char G[MAX][MAX];
bool vis[MAX][MAX];

bool ok(){
  queue<pii> q;
  if(G[n][m] != '#'){
    q.push({n,m}); vis[n][m] = 1;
  }
  while(!q.empty()){
    pii t = q.front(); q.pop();
    FOR(d,0,4){
      int tx = t.FI + to[d][0],
          ty = t.SE + to[d][1];
      if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if(vis[tx][ty] || G[tx][ty] == '#') continue;
      vis[tx][ty] = 1;
      q.push({tx,ty});
    }
  }

  FORR(i,1,n) FORR(j,1,m)
    if(G[i][j]=='B'){
      if(vis[i][j]) return false;
    }else if(G[i][j]=='G'){
      if(!vis[i][j]) return false;
    }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0);
    scanf("%d%d",&n,&m);
    FORR(i,1,n) scanf("%s",G[i]+1);
    FORR(i,1,n) FORR(j,1,m) if(G[i][j]=='B') FOR(d,0,4){
      char &ch = G[i+to[d][0]][j+to[d][1]];
      if(ch == '.') ch = '#';
    }
    printf("%s\n", ok() ? "Yes" : "No");
  }
  return 0;
}
