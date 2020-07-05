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

const int MAX = 2020, MAXV = 320;
const int INF=0x3f3f3f3f;
int n, m, v, e, c[MAX], d[MAX];
int G[MAXV][MAXV];
double k[MAX], f[MAX][MAX][2];

int main(void){
  scanf("%d%d%d%d",&n,&m,&v,&e);
  FORR(i,1,n) scanf("%d",&c[i]);
  FORR(i,1,n) scanf("%d",&d[i]);
  FORR(i,1,n) scanf("%lf",&k[i]);

  MST(G,0x3f);
  FORR(i,1,v) G[i][i]=0;
  int a, b, w;
  FOR(i,0,e){
    scanf("%d%d%d",&a,&b,&w);
    if(w<G[a][b]) G[a][b]=G[b][a]=w;
  }
  FORR(kk,1,v) FORR(i,1,v) FORR(j,1,v)
    G[i][j] = min(G[i][j], G[i][kk] + G[kk][j]);

  FORR(i,0,n) FORR(j,0,m)
    f[i][j][0]=f[i][j][1]=INF;

  f[1][0][0] = f[1][1][1] = 0;

  FORR(i,2,n){
    int r = min(i,m);
    FORR(j,0,r){
      if(i>j){  // f[i][j][0]
        double &a = f[i][j][0];
        a = f[i-1][j][0] + G[c[i-1]][c[i]];
        a = min(a, f[i-1][j][1] + k[i-1]*G[d[i-1]][c[i]]
                                + (1-k[i-1])*G[c[i-1]][c[i]]);
      }
      if(j){    // f[i][j][1]
        double &a = f[i][j][1];
        a = f[i-1][j-1][0] + k[i]*G[c[i-1]][d[i]]
                           + (1-k[i])*G[c[i-1]][c[i]];
        a = min(a, f[i-1][j-1][1] + k[i]*k[i-1]*G[d[i-1]][d[i]]
                                  + (1-k[i])*k[i-1]*G[d[i-1]][c[i]]
                                  + k[i]*(1-k[i-1])*G[c[i-1]][d[i]]
                                  + (1-k[i])*(1-k[i-1])*G[c[i-1]][c[i]]);
      }
    }
  }
  double ansMin = INF;
  FORR(j,0,m) ansMin = min(ansMin, min(f[n][j][0], f[n][j][1]));
  printf("%.2lf\n",ansMin);

  return 0;
}
