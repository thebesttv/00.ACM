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

const int MAX = 1020;
const int INF = 0x3f3f3f3f;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m,q,d[MAX][MAX]; pii ori[MAX][MAX];
char G[MAX][MAX];

struct Node{
  int x, y, ox, oy;
};
void cal(){
  queue<Node> q;
  FORR(i,1,n) FORR(j,1,m){
    bool flip = 0; int tx, ty;
    FOR(d,0,4){
      tx = i + to[d][0],
      ty = j + to[d][1];
      if(tx < 1 || tx > n || ty < 1 || ty > m)
        continue;
      if(G[tx][ty] == G[i][j]){
        flip = 1; break;
      }
    }

    if(flip){
      ori[i][j]={i,j}; d[i][j] = 0; 
      q.push({i,j,i,j});
    }
  }

  while(!q.empty()){
    Node t = q.front(); q.pop();
    int td = d[t.x][t.y];
    FOR(dir,0,4){
      int tx = t.x + to[dir][0],
          ty = t.y + to[dir][1];
      if(tx < 1 || tx > n || ty < 1 || ty > m)
        continue;
      if(d[tx][ty] > td + 1){
        d[tx][ty] = td + 1;
        ori[tx][ty] = {t.ox, t.oy};
        q.push({tx,ty,t.ox,t.oy});
      }
    }
  }
}

int main(void){
  MST(d,0x3f);
  scanf("%d%d%d",&n,&m,&q);
  FORR(i,1,n) scanf("%s",G[i]+1);

  cal();
  int x, y, c; LL k;
  while(q--){
    scanf("%d%d%lld\n",&x,&y,&k);
    if(d[x][y] == INF || k < d[x][y]){
      printf("%c\n",G[x][y]);
    }else{
      c = G[ori[x][y].FI][ori[x][y].SE] - '0';
      printf("%lld\n", c^(k&1));
    }
  }

  return 0;
}
