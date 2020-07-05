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

const int MAXN=202, MAXH=40*200+2;
int n,a[MAXN],s[MAXN];
bool f[MAXN][MAXN][MAXH];

int main(void){
  MST(f,0x3f); scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];

  f[0][0][0]=1;
  FOR(i,0,n) FORR(j,0,i){
    if(f[i+1][j+1] > abs(f[i][j]+a[i+1])){
      f[i+1][j+1] = f[i][j] + a[i+1];
    }
    if(f[i+1][j] > abs(f[i][j]-a[i+1])){
      f[i+1][j] = abs(f[i][j] - a[i+1]);
    }
  }
#ifdef DEBUG
  FORR(i,1,n) FORR(j,0,i)
    printf("f[%d][%d]: %d\n",i,j,f[i][j]);
#endif

  int l,r,d=f[n][n/2];
  r = (sum+d)/2; l = sum-r;
  if(n&1 && f[n][n/2+1] < f[n][n/2]){
    d=f[n][n/2+1];
    r = (sum+d)/2; l = sum-r;
  }
  if(l>r) swap(l,r);
  printf("%d %d\n",l,r);

  return 0;
}

/*
const int MAXN=202, MAXH=40*200+2;
int n,a[MAXN],f[MAXN][MAXN];

int main(void){
  MST(f,0x3f);
  int sum=0; scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]), sum+=a[i];

  f[0][0]=0;
  FOR(i,0,n) FORR(j,0,i){
    int d=f[i][j];
    f[i+1][j+1] = min(f[i+1][j+1], d + a[i+1]);
    if(d<a[i+1]) f[i+1][j+1] = min(f[i+1][j+1], a[i+1]-d);
    else f[i+1][j] = min(f[i+1][j], d-a[i+1]);
  }
#ifdef DEBUG
  FORR(i,1,n) FORR(j,0,i)
    printf(" f[%d][%d]: %d\n",i,j,f[i][j]);
#endif

  int l,r,d=f[n][n/2];
  r = (sum+d)/2; l = sum-r;
  if(n&1 && f[n][n/2+1]<f[n][n/2]){
    d=f[n][n/2+1];
    r = (sum+d)/2; l = sum-r;
  }
  printf("%d %d\n",l,r);

  return 0;
}
*/
