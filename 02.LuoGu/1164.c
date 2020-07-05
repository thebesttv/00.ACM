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

const int MAXM=10020, MAXN=120;
int n,m,f[MAXM];

int main(void){
  scanf("%d%d",&n,&m);

  f[0]=1;
  FORR(i,1,n){
    int a; scanf("%d",&a);
    ROR(j,m,0) if(j>=a) f[j]+=f[j-a];
  }
  printf("%d\n",f[m]);

  return 0;
}

/*
const int MAXM=10020, MAXN=120;
int n,m,a[MAXN],f[MAXN][MAXM];
// f[i][j]: till i, having used j yuan, number of ways

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);

  f[0][0]=1;
  FORR(i,1,n) FORR(j,0,m){
    f[i][j]=f[i-1][j];
    if(j>=a[i]) f[i][j]+=f[i-1][j-a[i]];
  }
  printf("%d\n",f[n][m]);

  return 0;
}
*/
