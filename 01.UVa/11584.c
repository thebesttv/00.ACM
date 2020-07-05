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

// 0ms
// 用邻接表代替邻接矩阵
const int MAX=1020;
int n,f[MAX]; char s[MAX];
VR<int> G[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0x3f);
    scanf("%s",s+1); n=strlen(s+1);
    FORR(i,1,n) G[i].clear();

    FORR(i,1,n) FOR(j,0,i){
      if(i+j<=n && s[i-j]==s[i+j]) G[i+j].push_back(i-j);
      else break;
    }
    FORR(i,1,n) FOR(j,0,i){
      if(i+j+1<=n && s[i-j]==s[i+j+1]) G[i+j+1].push_back(i-j);
      else break;
    }
    f[0]=0;
    FORR(i,1,n) for(int j : G[i])
      f[i] = min( f[i], f[j-1]+1 ); // <b> f[j-1] </b>
    printf("%d\n",f[n]);
  }

  return 0;
}

/*
// 30ms
const int MAX=1020;
int n,f[MAX]; char s[MAX];
bool g[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0x3f); MST(g,0);
    scanf("%s",s+1); n=strlen(s+1);

    FORR(i,1,n) FOR(j,0,i){
      if(i+j<=n && s[i-j]==s[i+j]) g[i-j][i+j]=1;
      else break;
    }
    FORR(i,1,n) FOR(j,0,i){
      if(i+j+1<=n && s[i-j]==s[i+j+1]) g[i-j][i+j+1]=1;
      else break;
    }
    f[0]=0;
    FORR(i,1,n) FOR(j,0,n) if(g[j+1][i])
      f[i] = min( f[i], f[j]+1 );
    printf("%d\n",f[n]);
  }

  return 0;
}
*/

/*
// 60ms
const int MAX=1020;
int n,f[MAX]; char s[MAX];
bool g[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0x3f); MST(g,1);
    scanf("%s",s+1); n=strlen(s+1);
    ROR(i,n,1) FORR(j,i+1,n)
      g[i][j] = g[i+1][j-1] && (s[i]==s[j]);
    f[0]=0;
    FORR(i,1,n) FOR(j,0,n) if(g[j+1][i])
      f[i] = min( f[i], f[j]+1 );
    printf("%d\n",f[n]);
  }

  return 0;
}
*/

/*
// 90ms
const int MAX=1020;
int n,f[MAX]; char s[MAX];
bool g[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0x3f); MST(g,0);
    scanf("%s",s+1); n=strlen(s+1);
    ROR(i,n,1) FORR(j,1,n)
      if(i>=j) g[i][j]=1;
      else g[i][j] = g[i+1][j-1] && (s[i]==s[j]);
    f[0]=0;
    FORR(i,1,n) FOR(j,0,n) if(g[j+1][i])
      f[i] = min( f[i], f[j]+1 );
    printf("%d\n",f[n]);
  }

  return 0;
}
*/
