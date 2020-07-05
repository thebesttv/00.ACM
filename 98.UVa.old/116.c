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

int m,n,a[MAX][MAX];
int f[MAX][MAX], r[MAX][MAX];  // starting from (i,j), the minimum cost

int main(void){
  while(scanf("%d%d",&m,&n)==2){
    MST(f,0x3f);
    FORR(i,1,m) FORR(j,1,n) scanf("%d",&a[i][j]);
    FORR(i,1,m) f[i][n]=a[i][n], r[i][n]=0;

    ROR(j,n-1,1){
      FORR(i,1,m){
        int v[3]={i-1,i,i+1};
        if(i==1) v[0]=m;
        else if(i==m) v[2]=1;
        sort(v,v+3);

        FOR(k,0,3){
          int t = f[v[k]][j+1]+a[i][j];
          if(f[i][j]>t) f[i][j]=t, r[i][j]=v[k];
        }
      }
    }

    int ansMin=INF, p;
    FORR(i,1,m) if(ansMin>f[i][1]){
      ansMin=f[i][1]; p=i;
    }
    printf("%d",p);
    FOR(j,1,n){
      p=r[p][j];
      printf(" %d",p);
    }
    printf("\n%d\n",ansMin);
  }

  return 0;
}
