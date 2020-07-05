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

const int MAX=120*2;
const int INF=0x3f3f3f3f;
int n,a[MAX],s[MAX];
int f[MAX][MAX],g[MAX][MAX];  // f: min, g: max

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]), a[i+n]=a[i]; // <b> 断环为链 </b>
  FORR(i,1,n<<1) s[i]=s[i-1]+a[i];  // 计算 1:2n 的前缀和

  MST(f,0x3f), MST(g,-0x3f);
  ROR(i,n<<1,1) FORR(j,i,n<<1){ // 在 1:2n 上 DP
    if(i==j) f[i][j]=g[i][j]=0;
    else FOR(k,i,j){
      f[i][j] = min( f[i][j], f[i][k] + f[k+1][j] + s[j]-s[i-1]);
      g[i][j] = max( g[i][j], g[i][k] + g[k+1][j] + s[j]-s[i-1]);
    }
  }

  int ansMin=INF, ansMax=-INF;
  FORR(i,1,n){
    ansMin=min(ansMin, f[i][i+n-1]);  // 寻找环上最值
    ansMax=max(ansMax, g[i][i+n-1]);
  }
  printf("%d\n%d\n",ansMin,ansMax);

  return 0;
}
