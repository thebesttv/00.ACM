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

const int MAXN=30020, MAXM=30;
int n,m,f[MAXN];  // f[i][j]: having decided on item 1:i, having used j space, the maxium weight
// f[i][j] = max( f[i-1][j], f[i-1][j-v[i]] + v[i]*w[i] )

int main(void){
  scanf("%d%d",&n,&m);
  int v,w;
  FORR(i,1,m){
    scanf("%d%d",&v,&w);
    ROR(j,n,v) f[j] = max(f[j], f[j-v] + v*w);
  }
  int ansMax=0; FORR(j,0,n) ansMax=max(ansMax,f[j]);
  printf("%d\n",ansMax);

  return 0;
}

/*
const int MAXN=30020, MAXM=30;
int n,m,f[MAXM][MAXN];  // f[i][j]: having decided on item 1:i, having used j space, the maxium weight
// f[i][j] = max( f[i-1][j], f[i-1][j-v[i]] + v[i]*w[i] )

int main(void){
  scanf("%d%d",&n,&m);
  int v,w;
  FORR(i,1,m){
    scanf("%d%d",&v,&w);
    FORR(j,0,n){
      f[i][j] = i==1 ? 0 : f[i-1][j];
      if(j>=v) f[i][j] = max(f[i][j], f[i-1][j-v] + v*w);
    }
  }
  int ansMax=0; FORR(j,0,n) ansMax=max(ansMax,f[m][j]);
  printf("%d\n",ansMax);

  return 0;
}
*/

/*
const int MAXN=30020, MAXM=30;
int n,m,v[MAXM],w[MAXM];
int f[MAXM][MAXN];  // f[i][j]: at item i (about to decide on it), having used j space, the maximum weight

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d%d",&v[i],&w[i]);

  ROR(i,m,1) FORR(j,0,n){
    f[i][j] = i==m ? 0 : f[i+1][j];
    if(j+v[i]<=n) f[i][j]=max(f[i][j],f[i+1][j+v[i]]+v[i]*w[i]);
  }
  printf("%d\n",f[1][0]);

  return 0;
}
*/

/*
const int MAXN=30020, MAXM=30;
int n,m,v[MAXM],w[MAXM];
int f[MAXM][MAXN];  // f[i][j]: at item i, having j space left, the maximum weight

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d%d",&v[i],&w[i]);

  FORR(j,1,n) if(j>=v[m]) f[m][j]=v[m]*w[m];
  ROR(i,m-1,1) FORR(j,0,n)
    if(j>=v[i]) f[i][j] = max(f[i+1][j], f[i+1][j-v[i]] + v[i]*w[i]);
    else f[i][j] = f[i+1][j];

  printf("%d\n",f[1][n]);

  return 0;
}
*/
