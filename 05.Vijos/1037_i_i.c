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

const int MAXN=120, MAXH=2020;
int n,h[MAXN],s[MAXN];
bool f[MAXH][MAXH];

int main(void){
  f[0][0]=1;
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&h[i]), s[i]=s[i-1]+h[i];

  //FOR(i,0,n) FORR(h1,0,s[i]) FORR(h2,0,h1) if(f[h1][h2]){
  FOR(i,0,n) ROR(h1,s[i],0) ROR(h2,h1,0) if(f[h1][h2]){
    f[h1+h[i+1]][h2]=1;
    if(h2+h[i+1]>h1) f[h2+h[i+1]][h1]=1;
    else f[h1][h2+h[i+1]]=1;
#ifdef DEBUG
    printf("(%d,%d)->(%d,%d), (%d,%d)\n", h1,h2,
        h1+h[i+1], h2, h1,h2+h[i+1]);
#endif
  }
  
  int ans=0;
  ROR(i,s[n],1) if(f[i][i]) { ans=i; break; }
  if(ans>0) printf("%d\n",ans);
  else printf("Impossible\n");

  return 0;
}

/*
// 用 f[i] 更新 f[i+1]
const int MAXN=120, MAXH=2020;
int n,h[MAXN],s[MAXN];
int f[MAXN][MAXH];

int main(void){
  MST(f,-0x3f); f[0][0]=0;
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&h[i]), s[i]=s[i-1]+h[i];

  FOR(i,0,n) FORR(j,0,s[i+1]){
    int &a=f[i][j];
    f[i+1][j] = max(f[i+1][j], a);
    f[i+1][j+h[i+1]] = max(f[i+1][j+h[i+1]], a);
    if(j>=h[i+1]) f[i+1][j-h[i+1]] = max(f[i+1][j-h[i+1]], a + h[i+1]);
    if(h[i+1]>=j) f[i+1][h[i+1]-j] = max(f[i+1][h[i+1]-j], a + j);
  }
  
  int ans=f[n][0];
  if(ans>0) printf("%d\n",ans);
  else printf("Impossible\n");

  return 0;
}
*/

/*
// 用 f[i-1] 计算 f[i]
const int MAXN=120, MAXH=2020;
int n,h[MAXN],s[MAXN];
int f[MAXN][MAXH];  // 注意，第二维 j 最大为 sum{h[i]}

int main(void){
  MST(f,-0x3f); f[0][0]=0;
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&h[i]), s[i]=s[i-1]+h[i];

  FORR(i,1,n){
    FORR(j,0,s[i]){
      int &a=f[i][j];
      a = f[i-1][j];
      if(j>=h[i]) a = max(a, f[i-1][j-h[i]]);
      a = max(a, f[i-1][j+h[i]]+h[i]);
      //if(h[i]-j>=0) // 亦可，h[i]-j<=s[i-1] 非必要
      if(h[i]-j<=s[i-1] && h[i]-j>=0)
        a = max(a, f[i-1][h[i]-j] + h[i]-j );
    }
  }
  
  int ans=f[n][0];
  if(ans>0) printf("%d\n",ans);
  else printf("Impossible\n");

  return 0;
}
*/
