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
const LL MOD = 1000000007;
int n,m,r[MAX],c[MAX];
int G[MAX][MAX];

LL powmod(int c){
  if(c==0) return 1;
  if(c==1) return 2;
  LL x= powmod(c>>1);
  x = (x*x)%MOD;
  if(c&1) x = (x<<1)%MOD;
  return x;
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    scanf("%d",&r[i]);
    FOR(j,0,r[i]) G[i][j]=1;
    if(r[i]<m) G[i][r[i]]=2;
  }
  FOR(j,0,m){
    scanf("%d",&c[j]);
    FOR(i,0,c[j]){
      if(G[i][j]==0) G[i][j]=1;
      else if(G[i][j]==2) {printf("0\n"); return 0;}
    }
    if(c[j]<n){
      if(G[c[j]][j]==0) G[c[j]][j]=2;
      else if(G[c[j]][j]==1) {printf("0\n"); return 0;}
    }
  }
  int cnt=0;
  FOR(i,0,n) FOR(j,0,m) cnt += (G[i][j]==0);

  printf("%lld\n", powmod(cnt));

  return 0;
}
