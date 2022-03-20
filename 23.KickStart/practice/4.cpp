// Tag: 
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
#include<numeric>
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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

const int MAX = 120;
const int to[6][2] = {
  {-1, 0}, {-1, 1},
  {0, -1}, {0, 1},
  {1, -1}, {1, 0}
};

int n, nb, nr;
char G[MAX][MAX];
bool vis[MAX][MAX];

void bfs(queue<pii> &q, char ch) {
  while(!q.empty()) {
    pii u = q.front(); q.pop();
    int x = u.FI, y = u.SE;
    FOR(d,0,6) {
      int tx = x + to[d][0];
      int ty = y + to[d][1];
      if (tx < 1 || tx > n || ty < 1 | ty > n)
        continue;
      if (vis[tx][ty] || G[tx][ty] != ch) continue;
      vis[tx][ty] = 1;
      q.push({tx, ty});
    }
  }
}

bool red() {
  MST(vis, 0); queue<pii> q;
  FORR(i,0,n+1) q.push({0,i}), vis[0][i] = 1;
  bfs(q, 'R');
  FORR(i,1,n) if (vis[n][i])
    return true;
  return false;
}

bool blue() {
  MST(vis, 0); queue<pii> q;
  FORR(i,0,n+1) q.push({i,0}), vis[i][0] = 1;
  bfs(q, 'B');
  FORR(i,1,n) if (vis[i][n])
    return true;
  return false;
}

bool badRed() {
  FORR(i,1,n) FORR(j,1,n)
    if (G[i][j] == 'R') {
      G[i][j] = '.';
      bool res = red();
      G[i][j] = 'R';
      if (!res) {
#ifdef DEBUG
        printf("without (%d, %d), red fails\n", i, j);
#endif
        return false;
      }
    }
  return true;
}

bool badBlue() {
  FORR(i,1,n) FORR(j,1,n)
    if (G[i][j] == 'B') {
      G[i][j] = '.';
      bool res = blue();
      G[i][j] = 'B';
      if (!res) {
#ifdef DEBUG
        printf("without (%d, %d), blue fails\n", i, j);
#endif
        return false;
      }
    }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T) {
    scanf("%d",&n);
    nb = nr = 0;
    FORR(i,1,n) {
      scanf("%s", G[i]+1);
      FORR(j,1,n)
        nb += G[i][j] == 'B',
        nr += G[i][j] == 'R';
    }

    printf("Case #%d: ", kase);
    if (abs(nb - nr) > 1) {
      printf("Impossible\n"); continue;
    }

    bool r = red(), b = blue();
#ifdef DEBUG
    printf("r: %d, b: %d\n", r, b);
#endif
    if ((r&&b) || (b && nr > nb) || (r && nb > nr)) {
      printf("Impossible\n"); continue;
    }

    bool br = r ? badRed() : false;
    bool bb = b ? badBlue() : false;

    if (br || bb) {
      printf("Impossible\n");
    } else if (r) {
      printf("Red wins\n");
    } else if (b) {
      printf("Blue wins\n");
    } else {
      printf("Nobody wins\n");
    }
  }

  return 0;
}
