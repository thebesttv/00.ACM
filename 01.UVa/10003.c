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

const int MAX=60;
int l,n,f[MAX][MAX],r[MAX][MAX],a[MAX],s[MAX];

int main(void){
  while(scanf("%d",&l)==1 && l){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&s[i]);  s[++n]=l;
    ROR(i,n,1) a[i] = s[i]-s[i-1];

    MST(f,0x3f);
    FORR(i,0,n) f[i][i]=0, r[i][i]=i;
    /*
    FORR(len,2,n) FOR(i,1,n){
      int j=len+i-1; if(j>n) break;
      FORR(k,r[i][j-1],r[i+1][j]){
      //FOR(k,i,j){
        int t = f[i][k] + f[k+1][j] + s[j]-s[i-1];
        if(f[i][j] > t) f[i][j]=t, r[i][j]=k;
      }
    }
    */
    ROR(i,n,1) FORR(j,i+1,n) FORR(k,r[i][j-1],r[i+1][j]){
    //ROR(i,n,1) FORR(j,i+1,n) FOR(k,i,j){
      int t = f[i][k] + f[k+1][j] + s[j]-s[i-1];
      if(f[i][j] > t) f[i][j]=t, r[i][j]=k;
    }
#ifdef DEBUG
    FORR(i,1,n){
      FORR(j,1,n)
        if(r[i][j]) printf("%4d",r[i][j]);
        else printf("    ");
      printf("\n");
    }
#endif
    printf("The minimum cutting is %d.\n",f[1][n]);
  }

  return 0;
}
