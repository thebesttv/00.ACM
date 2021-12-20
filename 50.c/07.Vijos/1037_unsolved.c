#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=120;
const int MAXH=1007,MOD=1007;
const int INF=0x3f3f3f3f;
const int NINF=-INF;
int n,a[MAX],s[MAX],f[MAX][MAXH];
/*
  f[i][j]: 选前i个，高度差为j时的较小的塔的最大高度，共有四种决策
    1.不放
      f[i][j] = f[i-1][j]
    2.放在高塔上
      f[i][j] = f[i-1][j-h]
    3.放在低塔上
      1.改变高低塔关系，h-j>=0
        f[i][j] = f[i-1][h-j] + h-j
      2.不改变高低塔关系，j+h<=s[i-1]
        f[i][j] = f[i-1][j+h] + h
*/

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) {scanf("%d",&a[i]); s[i]=s[i-1]+a[i];}

  MST(f,-0x3f); f[0][0]=0;
  FORR(i,1,n){
    int h=a[i],sum=s[i];
    FORR(j,0,sum){
      int & t=f[i][j];
      t=max(t,f[i-1][j]);
      if(j>=h) t=max(t,f[i-1][j-h]);
      if(h>=j) t=max(t,f[i-1][h-j]+h-j);
      if(h+j<=s[i-1]) t=max(t,f[i-1][j+h]+h);
    }
  }
  if(f[n][0]<0) printf("Impossible\n");
  else printf("%d\n",f[n][0]);

  return 0;
}















































/*
//WA
const int MAX=120;
const int MAXH=1007,MOD=1007;
const int INF=0x3f3f3f3f;
const int NINF=-INF;
int n,a[MAX],f[MAX][MAXH];
  //f[i][j]: 选前i个，(h1-h2)%MOD为j时的h1

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  FORR(i,0,n) FOR(j,0,MOD) f[i][j]=NINF;
  f[0][0]=0;
  FORR(i,1,n){
    int h=a[i];
    FOR(j,0,MOD)
      f[i][j] = max(f[i][j], max(f[i-1][(j+h)%MOD]+h, f[i-1][(j-h+MOD)%MOD]));
  }
  int ans=0;
  FORR(i,1,n) ans=max(ans,f[i][0]);
  if(!ans) printf("Impossible\n");
  else printf("%d\n",ans);

  return 0;
}
*/

/*
const int MAX=120;
const int MAXH=1020;
int n,a[MAX],f[MAXH][MAXH];

int main(void){
  scanf("%d",&n);
  int sum=0;
  FORR(i,1,n) {scanf("%d",&a[i]); sum+=a[i];}
  sum>>=1;

  FORR(i,1,n){
    int t=a[i];
    ROR(h1,sum,t) ROR(h2,sum,t)
      //f[i][h1][h2] = max( f[i][h1][h2], max( f[i-1][h1-t][h2]+1, f[i-1][h1][h2-t]+1 ));
      f[h1][h2] = max( f[h1][h2], max( f[h1-t][h2]+1, f[h1][h2-t]+1 ));
  }
  int ans=0;
  ROR(h,sum,1) if(f[h][h]) {ans=h; break;}
  if(!ans) printf("Impossible\n");
  else printf("%d\n",ans);

  return 0;
}
*/

/*
const int MAX=120;
const int MAXH=1020;
const int INF=0x3f3f3f3f;
const int NINF=-INF;
int n,ori[MAX],a[MAX],f[MAXH],p[MAXH],vis[MAX];

bool check(int h){
  FORR(i,1,h) f[i]=NINF;
  int t;
  FORR(i,1,n){
    t=ori[i];
    ROR(j,h,t) if(f[j]<f[j-t]+1){
      f[j]=f[j-t]+1; p[j]=i;
    }
  }
  if(f[h]<0) return false;
  int tail=1; MST(vis,0);
  int i=p[h]; t=h;
  while(i){
    vis[i]=1; t-=ori[i]; i=p[t];
  }
  FORR(i,1,n) if(!vis[i]) a[tail++]=ori[i];
  FORR(i,1,h) f[i]=NINF;
  FOR(i,1,tail){
    t=a[i];
    ROR(j,h,t) if(f[j]<f[j-t]+1){
      f[j]=f[j-t]+1; p[j]=i;
    }
  }
  return f[h]>0;
}

int main(void){
  scanf("%d",&n);
  int sum=0;
  FORR(i,1,n) {scanf("%d",&ori[i]); sum+=ori[i];}

  //int L=0,R=sum/2;
  //while(L<R){ //XXX
  //  printf("  [%d,%d]\n",L,R);
  //  int M=(L+R+1)>>1;
  //  if(check(M)){
  //    L=M;
  //    printf("  %d is ok\n",M);
  //  }else{
  //    R=M-1;
  //    printf("  %d is not ok\n",M);
  //  }
  //}
  if(!L) printf("Impossible\n");
  else printf("%d\n",L);
  int ans=0;
  ROR(i,sum/2,1)
    if(check(i)) {ans=i; break;}
    else printf("  %d is not ok\n",i);
  if(!ans) printf("Impossible\n");
  else printf("%d\n",ans);

  return 0;
}
*/
