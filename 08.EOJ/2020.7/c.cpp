// Tag: 二维前缀和 i
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

const int MAX = 4000;
int n,m,a,b,G[MAX][MAX],s[MAX][MAX];

int sum(int x1, int y1, int x2, int y2){
  return s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
}

int main(void){
  //scanf("%d%d%d%d",&n,&m,&a,&b);
  scanf("%d%d%d%d",&a,&b,&n,&m);
  FORR(i,1,a) FORR(j,1,b){
    scanf("%d",&G[i][j]);
    s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + G[i][j];
  }

  LL ss = 0, gMax = 0;
  FORR(i,1,n) FORR(j,1,m){
    int x1,y1,x2,y2;
    x2 = min(i, a), y2 = min(j, b);
    x1 = max(1, a-n+i), y1 = max(1, b-m+j);
    G[i][j] = sum(x1,y1,x2,y2);
#ifdef DEBUG
    printf("  i: %d, j: %d, [%d,%d] [%d,%d]\n",i,j,x1,y1,x2,y2);
#endif
    gMax = max(gMax, 1ll*G[i][j]);
    ss += G[i][j];
  }

  FORR(i,1,n){
    FORR(j,1,m){
      G[i][j] = 100 * G[i][j] / gMax;
      printf("%d ",G[i][j]);
    }
    putchar('\n');
  }

  return 0;
}
