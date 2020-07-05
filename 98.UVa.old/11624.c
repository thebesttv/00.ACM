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
#include<utility>
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
typedef long long LL;
typedef long long unsigned LLU;

typedef pair<int,int> pii;
typedef pair<pii,int> pipi;
const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int MAX=1020, INF=0x3f3f3f3f;
int n,m,fire[MAX][MAX];
char G[MAX][MAX];
bool vis[MAX][MAX];

inline bool inRange(int x, int y){
  return x>=1 && x<=n && y>=1 && y<=m;
}

void bfsFire(VR<pii> &v){
  MST(fire,0x3f);
  queue<pipi> q;
  for(auto &a : v){
    fire[a.first][a.second]=0;
    q.push({a,0});
  }
  while(!q.empty()){
    pipi t = q.front(); q.pop();
    FOR(k,0,4){
      int tx = t.first.first + to[k][0];
      int ty = t.first.second + to[k][1];
      if(inRange(tx,ty) && G[tx][ty]!='#' && fire[tx][ty]==INF){
        fire[tx][ty] = t.second + 1;
        q.push({{tx,ty}, t.second+1});
      }
    }
  }
}

int bfs(pii s){
  queue<pipi> q; MST(vis,0);
  q.push({s,0}); vis[s.first][s.second]=1;
  while(!q.empty()){
    pipi t = q.front(); q.pop();
    FOR(k,0,4){
      int tx = t.first.first + to[k][0];
      int ty = t.first.second + to[k][1];
      if(!inRange(tx,ty)){
        return t.second + 1;
      }else if(G[tx][ty]=='.' && !vis[tx][ty] &&
          t.second + 1 < fire[tx][ty]){
        vis[tx][ty] = 1;
        q.push({{tx,ty},t.second+1});
      }
    }
  }
  return -1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    VR<pii> v; pii s;
    FORR(i,1,n){
      scanf("%s",G[i]+1);
      FORR(j,1,m)
        if(G[i][j]=='F') v.push_back({i,j});
        else if(G[i][j]=='J') s = {i,j};
    }

    bfsFire(v);
    int ans = bfs(s);

    if(ans==-1) printf("IMPOSSIBLE\n");
    else printf("%d\n",ans);
  }

  return 0;
}
