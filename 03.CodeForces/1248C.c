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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n, m, ans;
bool v[100][100];

bool ok(){
  FOR(i,0,n) FOR(j,0,m){
    int cnt = 1;
    FOR(k,0,4){
      int tx = i + to[k][0],
          ty = j + to[k][1];
      if(tx<0 || tx>=n || ty<0 || ty>=m) continue;
      if(v[i][j]==v[tx][ty]) ++cnt;
    }
    if(cnt>2) return 0;
  }
  return 1;
}

void dfs(int x, int y){
  //if(x==n && y==m){
  if(x==n){
    if(ok()) ++ans;
    return;
  }

  int tx = y==m-1 ? x+1 : x;
  int ty = y==m-1 ? 0 : y+1;
  v[tx][ty] = 0;
  dfs(tx,ty);
  v[tx][ty] = 1;
  dfs(tx,ty);
}

int main(void){
  //while(scanf("%d%d",&n,&m)==2){
  FORR(i,1,5) FORR(j,1,5){
    n = i, m = j;
    ans = 0;
    dfs(0,0);
    printf("%5d",ans);
    if(j==5) putchar('\n');
  }

  return 0;
}
