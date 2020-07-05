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

const int MAX = 22;
int r,s,x,y,w;
double f[MAX][MAX];

void cal() {
  f[0][0] = 1;
  FORR(i,1,y) FORR(j,0,i) {
    f[i][j] = f[i-1][j] * (r-1.0) / s;
    if(j>0) f[i][j] += f[i-1][j-1] * (s - r + 1.0) / s;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d%d",&r,&s,&x,&y,&w);
    cal();
    double sum = 0;
    FORR(i,x,y) sum += f[y][i];
#ifdef DEBUG
    FORR(i,1,y) FORR(j,1,i)
      printf("  f(%d,%d): %lf\n",i,j,f[i][j]);
    printf("  sum: %lf\n",sum);
#endif
    if(sum * w > 1){
      printf("yes\n");
    }else{
      printf("no\n");
    }
  }

  return 0;
}
