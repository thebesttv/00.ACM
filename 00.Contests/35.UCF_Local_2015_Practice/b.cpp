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

const int MAX = 20;
const int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m,G[MAX][MAX];
bool vis[MAX][MAX];

struct Node{
  int x,y,d;
};

bool bad(int x, int y){
  return x < 1 || x > n || y < 1 || y > m || vis[x][y];
}

int main(void){
  int kase = 0;
  while(scanf("%d%d",&n,&m)==2 && n && m){
    int ch;
    FORR(i,1,n) FORR(j,1,m){
      do ch = getchar(); while(!isalnum(ch));
      G[i][j] = ch;
    }
    printf("Matrix #%d:\nOriginal:\n",++kase);
    FORR(i,1,n){
      putchar(G[i][1]);
      FORR(j,2,m) printf(" %c",G[i][j]);
      putchar('\n');
    }

    printf("Snail:");

    MST(vis,0); vis[1][1] = 1;
    queue<Node> q; q.push({1,1,0});
    int od = -1;
    while(!q.empty()){
      Node t = q.front(); q.pop();
      if(t.d != od){
        od = t.d;
        printf("\n%c",G[t.x][t.y]);
      }else printf("%c",G[t.x][t.y]);

      int tx = t.x + to[t.d][0],
          ty = t.y + to[t.d][1];
      if(bad(tx,ty)){
        t.d = (t.d + 1)%4;
        tx = t.x + to[t.d][0];
        ty = t.y + to[t.d][1];
        if(bad(tx,ty)) continue;
      }
      vis[tx][ty] = 1;
      q.push({tx,ty,t.d});
    }
    putchar('\n');
    putchar('\n');
  }

  return 0;
}
