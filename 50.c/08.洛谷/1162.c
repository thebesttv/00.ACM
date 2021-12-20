#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=40;
struct Node{
  int x,y;
};
int n,G[MAX][MAX],ori[MAX][MAX];
bool vis[MAX][MAX];
int to[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int x, int y, int col){
  queue<Node> q;
  q.push((Node){x,y}); vis[x][y]=1;
  while(!q.empty()){
    Node t=q.front(); q.pop();
    x=t.x,y=t.y; G[x][y]=col;
    FOR(i,0,4){
      int tx=x+to[i][0],ty=y+to[i][1];
      if(tx<0 || tx>n+1 || ty<0 || ty>n+1 || vis[tx][ty] || G[tx][ty]) continue;  //<b> tx>n+1, ty>n+1 </b>
      q.push((Node){tx,ty}); vis[tx][ty]=1;
    }
  }
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) FORR(j,1,n) scanf("%d",&ori[i][j]);
  memcpy(G,ori,SIZ(ori));
  bfs(0,0,-1);
  FORR(i,1,n) FORR(j,1,n) if(!G[i][j]) {bfs(i,j,2); break;}
  FORR(i,1,n){
    FORR(j,1,n){
      if(j!=1) putchar(' ');
      putchar(G[i][j]==-1 ? '0' : G[i][j]+'0');
    }
    putchar('\n');
  }

  return 0;
}
