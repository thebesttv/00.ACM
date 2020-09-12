// Tag: notag
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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 30;
const int to[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{-1,1},{-1,-1},{1,1},{1,-1}};
// white: 1, black: -1
int cb, cw, G[MAX][MAX];
char s[MAX];

int count(int x, int y, int d){
  int c = 1, o = G[x][y];
  FOR(i,0,4){
    x += to[d][0], y += to[d][1];
    if(x<1 || x>25 || y<1 || y>25) break;
    if(G[x][y] != o) break;
    ++c;
  }
  return c;
}

bool ok(int x){
  FORR(i,1,25) FORR(j,1,25) if(G[i][j] == x){
    FOR(d,0,8) if(count(i,j,d) >= 5) return true;
  }
  return false;
}

int main(void){
  FORR(i,1,25){
    scanf("%s",s+1);
    FORR(j,1,25){
      G[i][j] = s[j] == '.' ? 0 : s[j] == 'x' ? -1 : 1;
      if(s[j] == 'x') ++cb;
      else if(s[j] == 'o') ++cw;
    }
  }

  bool done = false;
  if(cb == cw){ // black now
    FORR(i,1,25) FORR(j,1,25) if(G[i][j]==0){
      G[i][j] = -1;
      if(ok(-1)){
        printf("%d %d\n",i-1,j-1); done = true;
      }
      G[i][j] = 0;
    }
  }else{  // white now
    FORR(i,1,25) FORR(j,1,25) if(G[i][j]==0){
      G[i][j] = 1;
      if(ok(1)){
        printf("%d %d\n",i-1,j-1); done = true;
      }
      G[i][j] = 0;
    }
  }
  if(!done) printf("tie\n");

  return 0;
}
