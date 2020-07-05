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

const int MAXN=120, MAXW=100020;
int n,w,a[MAXN],s[MAXN];
int f[MAXN][MAXW];
// f[i][j]: i:n 个，恰好组成 j

int main(void){
  scanf("%d%d",&w,&n);
  FORR(i,1,n) scanf("%d",&a[i]), s[i]=s[i-1]+a[i];
  w = s[n]-w;

  f[n+1][0]=1;  // <b> </b>
  ROR(i,n,1) ROR(j,w,0){
    if(j>=a[i]) f[i][j] = f[i+1][j] + f[i+1][j-a[i]];
    else f[i][j]=f[i+1][j];
  }

  if(f[1][w]!=1) printf("%d\n",f[1][w] ? -1 : 0);
  else{
    int p=w;
    while(p) FORR(i,1,n) if(f[i][p] && f[i+1][p-a[i]] && f[i][p] == f[i+1][p] + f[i+1][p-a[i]]){
      printf("%d ",i); p-=a[i];
    }
    printf("\n");
  }
  return 0;
}
