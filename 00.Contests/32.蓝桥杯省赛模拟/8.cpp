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
const int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n,m,sx,sy,G[MAX][MAX];
struct Node{
  int x, y, d, no;
};
queue<Node> q;

int main(void){
  scanf("%d%d",&n,&m);
  scanf("%d%d",&sx,&sy);

  queue<Node> q;
  q.push({1,1,0,1});
  G[1][1] = 1;
  while(!q.empty()){
    Node t = q.front(); q.pop();
    int tx = t.x + to[t.d][0],
        ty = t.y + to[t.d][1];
    if(tx < 1 || tx > n || ty < 1 || ty > m || G[tx][ty]) {
      t.d = (t.d + 1)%4;
      tx = t.x + to[t.d][0];
      ty = t.y + to[t.d][1];
      if(tx < 1 || tx > n || ty < 1 || ty > m || G[tx][ty])
        continue;
    }
    G[tx][ty] = t.no + 1;
    q.push({tx,ty,t.d,t.no+1});
  }
#ifdef DEBUG
  FORR(i,1,n){
    FORR(j,1,m){
      printf("%2d ",G[i][j]);
    }
    putchar('\n');
  }
#endif
  printf("%d\n",G[sx][sy]);

  return 0;
}
