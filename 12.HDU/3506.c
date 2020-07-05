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

const int MAX=1020*2;
const int INF=0x3f3f3f3f;
int n,a[MAX],s[MAX],f[MAX][MAX],r[MAX][MAX];

int main(void){
  while(scanf("%d",&n)==1){
    FORR(i,1,n) scanf("%d",&a[i]), a[i+n]=a[i];
    MST(f,0x3f);
    FOR(i,1,n<<1){
      s[i]=s[i-1]+a[i];
      f[i][i]=0, r[i][i]=i;
    }
    FORR(len,2,n) FOR(i,1,n<<1){
      int j=len+i-1; if(j>=(n<<1)) break;
      FORR(k,r[i][j-1],r[i+1][j]){
        int t = f[i][k] + f[k+1][j] + s[j] - s[i-1];
        if(f[i][j]>t) f[i][j] = t, r[i][j] = k;
      }
    }
#ifdef DEBUG
    // 判断 s 单调性
    FORR(i,1,n){
      FORR(j,1,n)
        if(i<=j) printf("%4d",r[i][j]);
        else printf("    ");
      printf("\n");
    }
#endif
    int ansMin=INF;
    FORR(i,1,n) ansMin = min(ansMin, f[i][i+n-1]);
    printf("%d\n",ansMin);
  }

  return 0;
}
