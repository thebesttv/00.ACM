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

const int MAX = 2020;
const int to[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int offset = 520;
int n,m; char s[1020][1020];
bool blocked[MAX][MAX][4];
bool vis[MAX][MAX];
queue<pii> q;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%s",s[i]+1);

  int type = 0;
  FORR(i,1,n){
    FORR(j,1,m)
      if(s[i][j]=='/'){
        if((i+j)&1) type = 2;
        else type = 1;
        break;
      }else if(s[i][j]=='\\'){
        if((i+j)&1) type = 1;
        else type = 2;
        break;
      }
    if(type) break;
  }

#ifdef DEBUG
  printf("  type: %d\n",type);
#endif

  FORR(i,1,n){
    int x1, y1, x2, y2;
    FORR(j,1,m){
      if(s[i][j] == '/'){
        if(type==2) ++j;

        y1 = y2 = (j-i)/2 + 1 + offset;
        x1 = (i+j)/2 - 1 + offset;
        x2 = (i+j)/2 + offset;

        blocked[x1][y1][2] = 1;
        blocked[x2][y2][0] = 1;
#ifdef DEBUG
        printf("/ at (%d, %d) blocked (%d, %d) (%d, %d)\n",i,j,x1-offset,y1-offset,x2-offset,y2-offset);
#endif
        if(type==2) --j;
      }else if(s[i][j] == '\\'){
        if(type==2) ++j;

        x1 = x2 = (i+j)/2 + offset;
        y1 = (j-i+1)/2 + 1 + offset;
        y2 = (j-i+1)/2 + offset;
        blocked[x1][y1][3] = 1;
        blocked[x2][y2][1] = 1;
#ifdef DEBUG
        printf("\\ at (%d, %d) blocked (%d, %d) (%d, %d)\n",i,j,x1-offset,y1-offset,x2-offset,y2-offset);
#endif
        if(type==2) --j;
      }
    }
  }

  int ans = 0;
  FORR(i,1,2000) FORR(j,1,2000) if(!vis[i][j]){
#ifdef DEBUG
    printf(" (%d, %d)\n",i,j);
#endif
    vis[i][j] = 1; q.push({i,j}); ++ans;
    while(!q.empty()){
      pii t = q.front(); q.pop();
      FOR(d,0,4) if(!blocked[t.FI][t.SE][d]){
        int tx = t.FI + to[d][0];
        int ty = t.SE + to[d][1];
        if(tx<1 || tx>2000 || ty<1 || ty>2000 || vis[tx][ty])
          continue;
        vis[tx][ty] = 1;
        q.push({tx,ty});
      }
    }
  }
  printf("%d\n",ans - 1);

  return 0;
}
