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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=304;
const int INF=0x3f3f3f3f;
const int to[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int m,G[MAX][MAX];  // G[i][j]: time when (i,j) is hit
bool vis[MAX][MAX];

struct Node{
  int x,y,t;
  Node(int x, int y, int t): x(x), y(y), t(t) { }
};
queue<Node> q;

int main(void){
  MST(G,0x3f);
  scanf("%d",&m);
  FOR(i,0,m){
    int x,y,t; scanf("%d%d%d",&x,&y,&t);
    G[x][y]=min(G[x][y],t);
    FOR(k,0,4){
      int tx=x+to[k][0], ty=y+to[k][1];
      if(tx>=0 && ty>=0) G[tx][ty]=min(G[tx][ty],t);
    }
  }
  q.push(Node(0,0,0)); vis[0][0]=1;
  int ans=-1;
  while(!q.empty()){
    Node t=q.front(); q.pop();
    FOR(k,0,4){
      int tx=t.x+to[k][0], ty=t.y+to[k][1];
      if(tx<0 || ty<0) continue;
      if(G[tx][ty]>t.t+1 && !vis[tx][ty]){
        q.push(Node(tx,ty,t.t+1));
        vis[tx][ty]=1;
        if(G[tx][ty]==INF){
          ans=t.t+1; break;
        }
      }
    }
    if(ans!=-1) break;
  }
  printf("%d\n",ans);

  return 0;
}
