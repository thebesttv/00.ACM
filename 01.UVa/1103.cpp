// Tag: fun i
// 二维平面，注意四个边界都要扩展
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
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m; char s[MAX];
int G[MAX][MAX];
bool vis[MAX][MAX];
char toChar[6];

// range: [0:n] x [0:m]

void fill(int x, int y, int col){
  int ori = G[x][y]; vis[x][y] = 1;
  queue<pii> q; q.push({x,y});
  while(!q.empty()){
    pii t = q.front(); q.pop();
    G[t.FI][t.SE] = col;
    FOR(d,0,4){
      int tx = t.FI + to[d][0],
          ty = t.SE + to[d][1];
      if(tx < 0 || tx > n+1 || ty < 0 || ty > m+1) continue;
      if(vis[tx][ty] || G[tx][ty] != ori) continue;
      q.push({tx,ty}); vis[tx][ty] = 1;
    }
  }
}

int search(int x, int y){
  int cnt = 0; queue<pii> q;
  q.push({x,y}); vis[x][y] = 1;
  while(!q.empty()){
    pii t = q.front(); q.pop();
    FOR(d,0,4){
      int tx = t.FI + to[d][0],
          ty = t.SE + to[d][1];
      if(tx < 0 || tx > n+1 || ty < 0 || ty > m+1) continue;
      if(vis[tx][ty] || G[tx][ty] == 2) continue;

      if(G[tx][ty] == 1){
        q.push({tx,ty}); vis[tx][ty] = 1;
      }else{  // zero
        ++cnt; fill(tx,ty,0); // inside
      }
    }
  }
#ifdef DEBUG
  printf("  search(%d,%d): %d\n",x,y,cnt);
#endif
  return cnt;
}

int main(void){
  int kase = 0;
  toChar[0] = 'W'; toChar[1] = 'A';
  toChar[2] = 'K'; toChar[3] = 'J';
  toChar[4] = 'S'; toChar[5] = 'D';

  while(scanf("%d%d",&n,&m)==2 && n){
    MST(G,0); MST(vis,0);
    FORR(i,1,n){
      int tail = 1; scanf("%s",s);
      FOR(j,0,m){
        int x = isdigit(s[j]) ? s[j] - '0' : s[j]-'a'+10;
        ROR(k,3,0) G[i][tail++] = (x>>k)&1;
      }
    }
    m *= 4; fill(0,0,2);  // background
#ifdef DEBUG
    FORR(i,0,n+1){
      FORR(j,0,m+1) putchar(G[i][j]+'0');
      putchar('\n');
    }
#endif

    VR<char> ans;
    FORR(i,1,n) FORR(j,1,m) if(G[i][j]==1 && !vis[i][j]){
      ans.push_back(toChar[search(i,j)]);
    }
    sort(ALL(ans));
    printf("Case %d: ",++kase);
    for(auto ch : ans) putchar(ch);
    putchar('\n');
  }

  return 0;
}
