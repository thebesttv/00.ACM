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

const int MAXN=180,MAXM=60;
int n,m,t,a[MAXN],z[MAXN];
int f[MAXN][MAXM];  // f[i][j]: 1:i，组成 j ，最大的照度
int g[MAXN][MAXN];  // g[i][j]: i:j 为一组，最大照度
int h[50*MAXN]; // package 的计算用数组

int main(void){
  scanf("%d%d%d",&n,&m,&t);
  FORR(i,1,n) scanf("%d%d",&a[i],&z[i]);

  FORR(i,1,n){  // dp 过慢
    MST(h,0); int lim=(n-i+1)*t;
    FORR(j,i,n){
      if(a[j]<=lim) ROR(k,lim,a[j])
        h[k] = max(h[k], h[k-a[j]]+z[j]);
      g[i][j] = h[(j-i+1)*t];
    }
  }

  FORR(i,1,n) FORR(j,1,min(i,m)) FOR(k,j-1,i){
    f[i][j] = max(f[i][j], f[k][j-1] + g[k+1][i]);
  }
  printf("%d\n",f[n][m]);

  return 0;
}

/*
const int MAXN=180,MAXM=60;
int n,m,t,a[MAXN],z[MAXN];
int f[MAXN][MAXM];  // f[i][j]: 1:i，组成 j ，最大的照度
int g[MAXN][MAXN];  // g[i][j]: i:j 为一组，最大照度
int tmp[50*MAXN]; // package 的计算用数组

int package(int *f, int *a, int *z, int n){
  int lim=n*t; FORR(j,0,lim) f[j]=0;
  FORR(i,1,n) if(a[i]<=lim) // <b> for循环第一次不会判断条件，一定要注意，防止 a[i]>lim 导致负下标 </b>
    ROR(j,lim,a[i]) f[j] = max(f[j], f[j-a[i]]+z[i]);
  return f[lim];
}

int main(void){
  scanf("%d%d%d",&n,&m,&t);
  FORR(i,1,n) scanf("%d%d",&a[i],&z[i]);

  FORR(i,1,n) FORR(j,i,n){  // dp 过慢
    g[i][j] = package(tmp,a+i-1,z+i-1,j-i+1);
#ifdef DEBUG
    printf("  g(%d,%d): %d\n",i,j,g[i][j]);
#endif
  }

  FORR(i,1,n) FORR(j,1,min(i,m)) FOR(k,j-1,i){
    f[i][j] = max(f[i][j], f[k][j-1] + g[k+1][i]);
  }
  printf("%d\n",f[n][m]);

  return 0;
}
*/
