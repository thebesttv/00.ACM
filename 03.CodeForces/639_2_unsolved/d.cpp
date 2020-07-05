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
bool G1[MAX][MAX], G2[MAX][MAX], vis[MAX][MAX];
VR<int> row[MAX], col[MAX];

void dfs(int x, int y){
  vis[x][y] = 1;
  FOR(k,0,4){
    int tx = to[k][0] + x,
        ty = to[k][1] + y;
    if(tx < 1 || tx > n || ty < 1 || ty > m)
      continue;
    if(vis[tx][ty] || !G1[tx][ty])
      continue;
    dfs(tx,ty);
  }
}

int cal(){
  FORR(i,1,n){
    if(!row[i].size()) return -1;
    int l = row[i].front(), r = row[i].back();
    FORR(j,l,r) G2[i][j] = 1;
  }
  FORR(j,1,m){
    if(!col[j].size()) return -1;
    int l = col[j].front(), r = col[j].back();
    FORR(i,l,r) G2[i][j] = 1;
  }

  FORR(i,1,n) FORR(j,1,m)
    if(G1[i][j] != G2[i][j])
      return -1;

  int cnt = 0;
  FORR(i,1,n) FORR(j,1,m) if(!vis[i][j] && G1[i][j]){
    ++cnt; dfs(i,j);
  }
  return cnt;
}

int main(void){
  scanf("%d%d",&n,&m);
  bool allEmpty = 1;
  FORR(i,1,n){
    scanf("%s", s+1);
    FORR(j,1,m)
      if(s[j] == '#'){
        G1[i][j] = 1;
        row[i].push_back(j);
        col[j].push_back(i);
        allEmpty = 0;
      }else{
        G1[i][j] = 0;
      }
  }

  if(allEmpty)
    printf("0\n");
  else
    printf("%d\n",cal());

  return 0;
}
