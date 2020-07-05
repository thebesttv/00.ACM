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

const int MAX=120;
const int INF=0x3f3f3f3f;
int n,a[MAX],f[MAX][MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  MST(f,0x3f);
  FOR(i,1,n) f[i][i+1]=0;
  ROR(i,n-1,1) FORR(j,i+1,n) FOR(k,i+1,j){
    f[i][j]=min(f[i][j], f[i][k]+f[k][j]+a[i]*a[k]*a[j]);
  }
  printf("%d\n",f[1][n]);

  return 0;
}

/*
const int MAX=120;
const int INF=0x3f3f3f3f;
int n,a[MAX],f[MAX][MAX];

int dp(int i, int j){
  int &a=f[i][j];
  if(a!=-1) return a;
  a=INF;
  if(i==j || i+1==j) a=0;
  else FOR(k,i+1,j)
}

int main(void){
  MST(f,-1);
  scanf("%d",&n); FORR(i,1,n) scanf("%d",&a[i]);

  int ansMin=INF;
  FOR(k,2,n) ansMin = min( ansMin, dp(i,k)+dp(k+1,j) +
      min(a[i]*a[k]*a[k+1] + a[i]*a[k+1]*a[j],
        a[k]*a[k+1]*a[j] + a[i]*a[k]*a[j]));
  printf("%d\n",ansMin);

  return 0;
}
*/
