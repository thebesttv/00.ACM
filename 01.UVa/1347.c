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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=1020;
const double EPS=1e-4;
const double INF=1e10;
int n,x[MAX],y[MAX];
double f[MAX][MAX],d[MAX][MAX];

int main(void){
  while(scanf("%d",&n)==1){
    FORR(i,1,n) scanf("%d%d",&x[i],&y[i]);
    FORR(i,1,n) FORR(j,i,n){
      double dx=x[i]-x[j], dy=y[i]-y[j];
      d[i][j]=d[j][i]= sqrt(dx*dx + dy*dy);
    }

    FORR(j,1,n-2) f[n-1][j] = d[n-1][n] + d[j][n];
    ROR(i,n-2,2) FOR(j,1,i)
      f[i][j] = min( f[i+1][j] + d[i][i+1], f[i+1][i] + d[j][i+1] );
    f[1][1] = f[2][1]+d[1][2];

    printf("%.2lf\n",f[1][1]);
  }

  return 0;
}

/*
const int MAX=1020;
const double EPS=1e-4;
const double INF=1e10;
int n,x[MAX],y[MAX];
double f[MAX][MAX],d[MAX][MAX];

int dcmp(double x, double y){
  if(fabs(x-y)<EPS) return 0;
  return x<y ? -1 : 1;
}

double dp(int i, int j){
  if(i==n || j==n){
    return d[i][n] + d[j][n];
  }
  double &a=f[i][j];
  if(dcmp(a,0)) return a;
  a = INF;

  if(i>j){
    a = min( dp(i+1,j) + d[i][i+1], dp(i,i+1) + d[j][i+1] );
  }else{
    a = min( dp(j+1,j) + d[i][j+1], dp(i,j+1) + d[j][j+1] );
  }
  return a;
}

int main(void){
  while(scanf("%d",&n)==1){
    MST(f,0);
    FORR(i,1,n) scanf("%d%d",&x[i],&y[i]);
    FORR(i,1,n) FORR(j,i,n){
      double dx=x[i]-x[j], dy=y[i]-y[j];
      d[i][j]=d[j][i]= sqrt(dx*dx + dy*dy);
    }
#ifdef DEBUG
    FORR(i,1,n) FORR(j,1,n)
      printf("dp(%d,%d): %.2lf\n",i,j,dp(i,j));
#endif

    printf("%.2lf\n",dp(1,1));
  }

  return 0;
}
*/
