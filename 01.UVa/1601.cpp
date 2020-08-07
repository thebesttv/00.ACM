// Tag: BFS
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
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
const int to[5][2] = {{-1,0},{1,0},{0,-1},{0,1},{0,0}};
int n,m,c,v[3],sx[26],sy[26],ex[26],ey[26];
char G[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX][MAX][MAX];

struct Node{
  int x[3],y[3],d;
  Node() { x[0]=x[1]=x[2]=y[0]=y[1]=y[2]=0; d=0; }
  Node(int x0, int y0, int x1, int y1, int x2, int y2, int d){
    x[0] = x0, x[1] = x1, x[2] = x2;
    y[0] = y0, y[1] = y1, y[2] = y2;
    this->d = d;
  }
};

bool ok(const Node &u){
  FOR(i,0,c) if(u.x[i] != ex[v[i]] || u.y[i] != ey[v[i]])
    return false;
  return true;
}

int bfs(){
  MST(vis,0);
  Node u; FOR(i,0,c) u.x[i] = sx[v[i]], u.y[i] = sy[v[i]];
  queue<Node> q; q.push(u);
  while(!q.empty()){
    u = q.front(); q.pop();
#ifdef DEBUG
    FOR(i,0,c) printf("(%d, %d) ",u.x[i],u.y[i]); printf("%d\n",u.d);
#endif
    if(ok(u)) return u.d;

    FOR(d0,0,5){
      int tx0 = u.x[0] + to[d0][0];
      int ty0 = u.y[0] + to[d0][1];
      if(tx0 < 1 || tx0 > n || ty0 < 1 || ty0 > m || G[tx0][ty0] == '#') continue;
      FOR(d1,c<2 ? 4 : 0,5){
        int tx1 = u.x[1] + to[d1][0];
        int ty1 = u.y[1] + to[d1][1];
        if(c>=2 && (tx1 < 1 || tx1 > n || ty1 < 1 || ty1 > m || G[tx1][ty1] == '#'
              || (tx1 == u.x[0] && ty1 == u.y[0] && tx0 == u.x[1] && ty0 == u.y[1])
              || (tx1 == tx0 && ty1 == ty0))) continue;
        FOR(d2,c<3 ? 4 : 0, 5){
          int tx2 = u.x[2] + to[d2][0];
          int ty2 = u.y[2] + to[d2][1];
          if(c>=3 && (tx2 < 1 || tx2 > n || ty2 < 1 || ty2 > m || G[tx2][ty2] == '#'
                || (tx2 == u.x[0] && ty2 == u.y[0] && tx0 == u.x[2] && ty0 == u.y[2])
                || (tx2 == u.x[1] && ty2 == u.y[1] && tx1 == u.x[2] && ty1 == u.y[2])
                || (tx2 == tx1 && ty2 == ty1)
                || (tx2 == tx0 && ty2 == ty0))) continue;
          bool &vis = ::vis[tx0][ty0][tx1][ty1][tx2][ty2];
          if(vis) continue;
#ifdef DEBUG
          Node tt(tx0,ty0,tx1,ty1,tx2,ty2,u.d+1);
          FOR(i,0,c) printf("(%d, %d) ",u.x[i],u.y[i]); printf("-> ");
          FOR(i,0,c) printf("(%d, %d) ",tt.x[i],tt.y[i]); printf("\n");
#endif
          vis = 1; q.push(Node(tx0,ty0,tx1,ty1,tx2,ty2,u.d+1));
        }
      }
    }
  }
  return -1;
}

int main(void){
  while(scanf("%d%d%d",&m,&n,&c)==3 && n){
    getchar(); int tail = 0;
    FORR(i,1,n){
      fgets(G[i]+1, sizeof(G[i]), stdin);
      FORR(j,1,m)
        if(islower(G[i][j])){
          v[tail] = G[i][j]-'a';
          sx[v[tail]] = i, sy[v[tail]] = j;
          tail++;
        }else if(isupper(G[i][j])){
          ex[G[i][j]-'A'] = i, ey[G[i][j]-'A'] = j;
        }
    }
#ifdef DEBUG
    FORR(i,1,n) printf("%s",G[i]+1);
    FOR(i,0,c) printf("%c: (%d, %d) -> (%d, %d)\n",v[i]+'A', sx[i],sy[i],ex[i],ey[i]);
#endif
    printf("%d\n",bfs());
  }

  return 0;
}
