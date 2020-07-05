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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=104;
const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,G[MAX][MAX],f[MAX][MAX];
string name;

int dp(int x, int y){
  int &a=f[x][y];
  if(a) return a;
  a = 1;
  FOR(i,0,4){
    int tx = x + to[i][0];
    int ty = y + to[i][1];
    if(tx<1 || tx>n || ty<1 || ty>m) continue;
    if(G[tx][ty] < G[x][y]) a = max(a, dp(tx,ty)+1);
  }
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0);
    cin >> name >> n >> m;
    FORR(i,1,n) FORR(j,1,m) scanf("%d",&G[i][j]);
    int ansMax=1;
    FORR(i,1,n) FORR(j,1,m) ansMax = max(ansMax, dp(i,j));
    cout << name << ": " << ansMax << endl;
  }

  return 0;
}

/*
const int MAX=104;
const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,f[MAX*MAX]; string name;
int ori[MAX][MAX];
VR<int> G[MAX*MAX];

inline int idx(int i, int j){
  return (i-1)*m + j;
}
inline void addEdge(int u, int v){
  G[u].push_back(v);
}

int dp(int u){
  int &a = f[u];
  if(a) return a;
  a = 1;
  for(int v : G[u]){
    a = max(a, dp(v) + 1);
  }
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cin >> name >> n >> m;
    MST(f,0); FORR(i,1,n*m) G[i].clear();
    FORR(i,1,n) FORR(j,1,m) scanf("%d",&ori[i][j]);
    FORR(x,1,n) FORR(y,1,m) FOR(i,0,4){
      int tx = x + to[i][0];
      int ty = y + to[i][1];
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(ori[tx][ty] < ori[x][y]){
        addEdge(idx(x,y), idx(tx,ty));
      }
    }
    int ansMax=1;
    FORR(i,1,n*m) ansMax = max(ansMax, dp(i));
    cout << name << ": " << ansMax << endl;
  }

  return 0;
}
*/

/*
const int MAX=120;
const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m; string name;
int G[MAX][MAX];
bool vis[MAX][MAX];

struct Node{
  int x, y, cnt;
  Node(int x, int y, int cnt): x(x), y(y), cnt(cnt) { }
};

int bfs(int x, int y){
  MST(vis,0); vis[x][y]=1;
  queue<Node> q;
  q.push(Node(x,y,1));
  int ans = 1;
  while(!q.empty()){
    Node t = q.front(); q.pop();
    x = t.x, y = t.y;
    FOR(i,0,4){
      int tx = x + to[i][0];
      int ty = y + to[i][1];
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(!vis[tx][ty] && G[tx][ty]<G[x][y]){
        q.push(Node(tx,ty,t.cnt+1));
        ans = max(ans, t.cnt+1);
      }
    }
  }
  return ans;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cin >> name >> n >> m;
    FORR(i,1,n) FORR(j,1,m)
      scanf("%d",&G[i][j]);
    int ansMax=1;
    FORR(i,1,n) FORR(j,1,m) ansMax = max(ansMax, bfs(i,j));
    cout << name << ": " << ansMax << endl;
  }

  return 0;
}
*/
