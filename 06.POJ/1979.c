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

const int MAX=40;
const int to[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int n,m; char G[MAX][MAX];
bool vis[MAX][MAX];

struct Node{
  int x,y;
};

int main(void){
  while(scanf("%d%d",&m,&n)==2 && n){
    MST(vis,0); int sx=-1,sy=-1;
    FORR(i,1,n){
      scanf("%s",G[i]+1);
      FORR(j,1,m) if(G[i][j]=='@'){
        sx=i, sy=j; break;
      }
    }
    queue<Node> q;
    q.push(Node{sx,sy}); vis[sx][sy]=1;
    int cnt=1;
    while(!q.empty()){
      Node t=q.front(); q.pop();
      FOR(i,0,4){
        int tx=t.x+to[i][0], ty=t.y+to[i][1];
        if(tx<1 || tx>n || ty<1 || ty>m) continue;
        if(G[tx][ty]=='.' && !vis[tx][ty]){
          q.push(Node{tx,ty}); vis[tx][ty]=1;
          cnt++;
        }
      }
    }
    printf("%d\n",cnt);
  }
  return 0;
}
