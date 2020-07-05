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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=220;
int n,x[MAX],y[MAX];
double G[MAX][MAX];

double dis(int i, int j){
  int dx = x[i]-x[j], dy = y[i] - y[j];
  return sqrt(static_cast<double>(dx*dx + dy*dy));
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n){
      scanf("%d%d",&x[i],&y[i]);
      FOR(j,0,i) G[i][j] = G[j][i] = dis(i,j);
    }
    FORR(k,1,n) FORR(i,1,n) FORR(j,1,n)
      G[i][j] = min(G[i][j], max(G[i][k],G[k][j]));
    printf("Scenario #%d\nFrog Distance = %.3lf\n\n",
        ++kase, G[1][2]);
  }

  return 0;
}
