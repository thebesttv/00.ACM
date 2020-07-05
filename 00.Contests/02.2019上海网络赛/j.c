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

const int MAXN=302,MAXW=502;
const int INF=0x3f3f3f3f;
const LL MOD=1e9+7;
int n,a[MAX];
LL f[MAXW][MAXW][MAXN];
// f[m][w]: forming exactly w wieight, with minium wight m

LL dp(int m, int w){
  LL &a=f[m][w];
  if(a!=-1) return a;
  a=0;
  FOR
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,-1);
    scanf("%d",&n);
    f[0][0]=0;
    FOR(i,0,n){
      scanf("%d",&a[i]);
      f[a[i]][a[i]]=1;
    }
  }

  return 0;
}
