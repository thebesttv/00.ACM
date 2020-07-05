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

const int MAX=24;
const int INF=0x3f3f3f3f;
int n,m,k,s[MAX][MAX];
int f[MAX][MAX][MAX][MAX];

int cherry(int a1, int b1, int a2, int b2){
  return s[a2][b2] - s[a2][b1-1] - s[a1-1][b2] + s[a1-1][b1-1];
}

int main(void){
  int kase=0;
  while(scanf("%d%d%d",&n,&m,&k)==3){
    MST(s,0);
    int x,y;
    FOR(i,0,k) scanf("%d%d",&x,&y), s[x][y]=1;
    FORR(i,1,n) FORR(j,1,m)
      s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    int a2,b2;
    FORR(l1,1,n) FORR(l2,1,m){
      FORR(a1,1,n){
        a2 = a1+l1-1; if(a2>n) break;
        FORR(b1,1,m){
          b2 = b1+l2-1; if(b2>m) break;
          int &a=f[a1][b1][a2][b2];
          int c=cherry(a1,b1,a2,b2);
          if(c==0) a=INF;
          if(c==1) a=0;
          else{
            a=INF;
            FOR(k,b1,b2)
              a = min(a, f[a1][b1][a2][k] + f[a1][k+1][a2][b2] + a2-a1+1);
            FOR(k,a1,a2)
              a = min(a, f[a1][b1][k][b2] + f[k+1][b1][a2][b2] + b2-b1+1);
          }
        }
      }
    }
    printf("Case %d: %d\n",++kase,f[1][1][n][m]);
  }

  return 0;
}

/*
const int MAX=24;
const int INF=0x3f3f3f3f;
int n,m,k,s[MAX][MAX];
int f[MAX][MAX][MAX][MAX];

int cherry(int a1, int b1, int a2, int b2){
  return s[a2][b2] - s[a2][b1-1] - s[a1-1][b2] + s[a1-1][b1-1];
}
int dp(int a1, int b1, int a2, int b2){
  int &a=f[a1][b1][a2][b2];
  if(a!=-1) return a;
  a = INF;
  int c=cherry(a1,b1,a2,b2);
  if(c==0) a=INF;
  else if(c==1) a=0;
  else{
    FOR(k,b1,b2)
      a = min(a, dp(a1,b1,a2,k) + dp(a1,k+1,a2,b2) + a2-a1+1);
    FOR(k,a1,a2)
      a = min(a, dp(a1,b1,k,b2) + dp(k+1,b1,a2,b2) + b2-b1+1);
  }
  return a;
}

int main(void){
  int kase=0;
  while(scanf("%d%d%d",&n,&m,&k)==3){
    MST(s,0); MST(f,-1);
    int x,y;
    FOR(i,0,k) scanf("%d%d",&x,&y), s[x][y]=1;
    FORR(i,1,n) FORR(j,1,m)
      s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];

    printf("Case %d: %d\n",++kase,dp(1,1,n,m));
  }

  return 0;
}
*/
