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

const int MAX = 520;
int n,m,k;

int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool vis[MAX][MAX];
char G[MAX][MAX];
struct Node{
  int x,y;
}q[MAX*MAX];
int head, tail;

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  int sx=0, sy=0;
  FORR(i,1,n){
    scanf("%s",G[i]+1);
    if(sx==0) FORR(j,1,m) if(G[i][j]=='.'){
      sx=i, sy=j; break;
    }
  }
  q[tail++]={sx,sy};
  vis[sx][sy]=1;
  while(head<tail){
    Node t=q[head++];
    FOR(k,0,4){
      int tx=t.x+to[k][0],
          ty=t.y+to[k][1];
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(vis[tx][ty] || G[tx][ty]!='.') continue;
      q[tail++]={tx,ty};
      vis[tx][ty]=1;
    }
  }
  while(k--){
    Node t=q[--tail];
    G[t.x][t.y]='X';
  }
  FORR(i,1,n) printf("%s\n",G[i]+1);

  return 0;
}
