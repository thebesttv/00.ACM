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

const int MAX = 520;
const int to[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m; char G[MAX][MAX];

bool ok(){
  FORR(i,1,n) FORR(j,1,m) if(G[i][j]=='W')
    FOR(d,0,4){
      int tx = i + to[d][0],
          ty = j + to[d][1];
      if(tx<1 || tx>n || ty<1 || ty>m) continue;
      if(G[tx][ty] == 'S') return false;
    }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%s",G[i]+1);
  if(!ok()) printf("No\n");
  else{
    printf("Yes\n");
    FORR(i,1,n){
      FORR(j,1,m) putchar(G[i][j]=='.' ? 'D' : G[i][j]);
      putchar('\n');
    }
  }

  return 0;
}
