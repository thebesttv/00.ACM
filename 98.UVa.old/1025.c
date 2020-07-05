#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
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

// 递推
const int MAX=60,MAXT=220;
const int INF=0x3f3f3f3f;
int n,t,duration[MAX];
int m1,m2,d1[MAX],d2[MAX];
int f[MAXT][MAX];
bool hasTrain[MAXT][MAX][2];

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    // init
    MST(hasTrain,0);  // <b>clear all!!!</b>
    scanf("%d",&t);
    FOR(i,1,n) scanf("%d",&duration[i]);
    scanf("%d",&m1); FORR(i,1,m1) scanf("%d",&d1[i]);
    scanf("%d",&m2); FORR(i,1,m2) scanf("%d",&d2[i]);

    // cal arrival time
    // foreward
    FORR(i,1,m1){
      int s=d1[i]; hasTrain[s][1][0]=1;
      FORR(j,2,n){
        s+=duration[j-1];
        if(s>t) break;  // <b> </b>
        hasTrain[s][j][0]=1;
      }
    }
    // backward
    FORR(i,1,m2){
      int s=d2[i]; hasTrain[s][n][1]=1;
      ROR(j,n-1,1){
        s+=duration[j];
        if(s>t) break;  // <b> </b>
        hasTrain[s][j][1]=1;
      }
    }
#ifdef DEBUG
    // 长长一坨调试……
    printf("***\n");
    FORR(i,1,n){
      printf("station %d:",i);
      FORR(j,0,T) if(hasTrain[j][i][0]) printf(" %d",j);
      printf("\n");
    }
    printf("***\n");
    FORR(i,1,n){
      printf("station %d:",i);
      FORR(j,0,T) if(hasTrain[j][i][1]) printf(" %d",j);
      printf("\n");
    }
#endif

    //dp
    MST(f,0x3f); f[t][n]=0;
    ROR(i,t-1,0) FORR(j,1,n){
      int &a=f[i][j];

      // wait
      a = min(a,f[i+1][j]+1);

      // forward
      if(hasTrain[i][j][0] && i+duration[j]<=t){
        a = min(a, f[i+duration[j]][j+1]);
      }

      // backward
      if(hasTrain[i][j][1] && i+duration[j-1]<=t){
        a = min(a, f[i+duration[j-1]][j-1]);
      }
    }

    printf("Case Number %d: ",++kase);
    if(f[0][1]<INF) printf("%d\n",f[0][1]);
    else printf("impossible\n");
  }

  return 0;
}

/*
const int MAX=60,MAXT=220;
const int INF=0x3f3f3f3f;
int n,t,duration[MAX];
int m1,m2,d1[MAX],d2[MAX];
int f[MAXT][MAX];
int a1[MAX][MAX],a2[MAX][MAX];

int dp(int i, int j){
  int &a=f[i][j];
  if(a!=-1) return a;
  a=INF;

  // wait
  if(i<t) a = min(a, dp(i+1,j)+1);

  // forward
  if(j<n){
    int train=-1;
    FORR(k,1,m1) if(a1[k][j]>=i){
      train=k; break;
    }
    if(train!=-1 && a1[train][j+1]>=0){
      a = min(a, dp(a1[train][j+1], j+1) + a1[train][j]-i);
    }
  }

  // backward
  if(j>1){
    int train=-1;
    FORR(k,1,m2) if(a2[k][j]>=i){
      train=k; break;
    }
    if(train!=-1 && a2[train][j-1]>=0){
      a = min(a, dp(a2[train][j-1], j-1) + a2[train][j]-i);
    }
  }

  return a;
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    // init
    scanf("%d",&t);
    FOR(i,1,n) scanf("%d",&duration[i]);
    scanf("%d",&m1); FORR(i,1,m1) scanf("%d",&d1[i]);
    scanf("%d",&m2); FORR(i,1,m2) scanf("%d",&d2[i]);

    // cal arrival time
    // forward
    MST(a1,-1); MST(a2,-1);
    FORR(i,1,m1){
      a1[i][1] = d1[i];
      int tmp;
      FORR(j,2,n){
        tmp = a1[i][j-1] + duration[j-1];
        if(tmp>t) break;
        a1[i][j] = tmp;
      }
    }
    // backward
    FORR(i,1,m2){
      a2[i][n] = d2[i];
      int tmp;
      ROR(j,n-1,1){
        tmp = a2[i][j+1] + duration[j];
        if(tmp>t) break;
        a2[i][j] = tmp;
      }
    }
#ifdef DEBUG
    printf("arrival (forward):\n");
    FORR(i,1,m1){
      FORR(j,1,n) printf("%d ",a1[i][j]);
      printf("\n");
    }
    printf("arrival (backward):\n");
    FORR(i,1,m2){
      FORR(j,1,n) printf("%d ",a2[i][j]);
      printf("\n");
    }
#endif

    //dp
    MST(f,-1); f[t][n]=0;
    int ans=dp(0,1);

    printf("Case Number %d: ",++kase);
    if(ans<INF) printf("%d\n",ans);
    else printf("impossible\n");
  }

  return 0;
}
*/

/*
const int MAX=60, MAXT=220;
const int INF=0x3f3f3f3f;
int n,T,wait[MAX];  // wait[i]: time it takes from station i to i+1
int m1,d[MAX],m2,e[MAX];
int a1[MAX][MAX], a2[MAX][MAX];
// a1[i][j]: the time train i (forward) arrives at station j
int f[MAXT][MAX];

int dp(int t, int s){
  int &a=f[t][s];
  if(a!=-1) return a;
  a=INF;
  if(t>=T) return a;

  // wait
  a = min(a, dp(t+1,s) + 1);

  if(s<n){  // forward
    int train=-1; // which train will arrive immediately after time t
    FORR(i,1,m1) if(a1[i][s]>=t){
      train=i; break;
    }
    if(train!=-1)
      a = min(a, dp( a1[train][s+1], s+1) + a1[train][s]-t);
  }

  if(s>1){  // backward
    int train=-1; // which train will arrive immediately after time t
    FORR(i,1,m2) if(a2[i][s]>=t){
      train=i; break;
    }
    if(train!=-1)
      a = min(a, dp( a2[train][s-1], s-1) + a2[train][s]-t);
  }

  return a;
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    MST(f,-1);
    scanf("%d",&T);
    FOR(i,1,n) scanf("%d",&wait[i]);
    scanf("%d",&m1); FORR(i,1,m1) scanf("%d",&d[i]);
    scanf("%d",&m2); FORR(i,1,m2) scanf("%d",&e[i]);

    // cal arrival time
    FORR(i,1,m1){
      a1[i][1]=d[i];
      FORR(j,2,n) a1[i][j] = a1[i][j-1] + wait[j-1];
    }
    FORR(i,1,m2){
      a2[i][n]=e[i];
      ROR(j,n-1,1) a2[i][j] = a2[i][j+1] + wait[j];
    }
#ifdef DEBUG
    printf("arrival (forward):\n");
    FORR(i,1,m1){
      FORR(j,1,n) printf("%d ",a1[i][j]);
      printf("\n");
    }
    printf("arrival (backward):\n");
    FORR(i,1,m2){
      FORR(j,1,n) printf("%d ",a2[i][j]);
      printf("\n");
    }
#endif

    f[T][n]=0;
    int ans = dp(0,1);

    printf("Case Number %d: ",++kase);
    if(ans<INF) printf("%d\n",ans);
    else printf("impossible\n");
  }

  return 0;
}
*/

/*
// 记忆化
const int MAX=60,MAXT=220;
const int INF=0x3f3f3f3f;
int n,t,duration[MAX];
int m1,m2,d1[MAX],d2[MAX];
int f[MAXT][MAX];
bool hasTrain[MAXT][MAX][2];

int dp(int i, int j){
  int &a=f[i][j];
  if(a!=-1) return a;
  a=INF;

  // wait
  if(i<t) a = min(a, dp(i+1,j)+1);

  // forward
  if(hasTrain[i][j][0] && i+duration[j]<=t){
    a = min(a, dp(i+duration[j],j+1));
  }

  // backward
  if(hasTrain[i][j][1] && i+duration[j-1]<=t){
    a = min(a, dp(i+duration[j-1],j-1));
  }
  return a;
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    // init
    MST(hasTrain,0);  // <b>clear all!!!</b>
    scanf("%d",&t);
    FOR(i,1,n) scanf("%d",&duration[i]);
    scanf("%d",&m1); FORR(i,1,m1) scanf("%d",&d1[i]);
    scanf("%d",&m2); FORR(i,1,m2) scanf("%d",&d2[i]);

    // cal arrival time
    // foreward
    FORR(i,1,m1){
      int s=d1[i]; hasTrain[s][1][0]=1;
      FORR(j,2,n){
        s+=duration[j-1];
        if(s>t) break;  // <b> </b>
        hasTrain[s][j][0]=1;
      }
    }
    // backward
    FORR(i,1,m2){
      int s=d2[i]; hasTrain[s][n][1]=1;
      ROR(j,n-1,1){
        s+=duration[j];
        if(s>t) break;  // <b> </b>
        hasTrain[s][j][1]=1;
      }
    }

    //dp
    MST(f,-1); f[t][n]=0;
    int ans=dp(0,1);

    printf("Case Number %d: ",++kase);
    if(ans<INF) printf("%d\n",ans);
    else printf("impossible\n");
  }

  return 0;
}
*/
