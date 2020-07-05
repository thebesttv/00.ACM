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

const int MAX=44;
const int INF=0x3f3f3f3f;
int n,r[5],v[5][MAX];
int f[MAX][MAX][MAX][MAX];

bool match(int s, int c){
  return s & (1<<c);
}

int dfs(int *r, int st, int cnt){
  if(cnt>=5) return 0;
  int &a=f[r[1]][r[2]][r[3]][r[4]];
  if(a!=-1) return a;
  a = 0;
  FORR(i,1,4) if(r[i]<n){
    r[i]++;
    int c = v[i][r[i]];
    if(match(st,c)){
      a = max(a, dfs(r, st&(~(1<<c)), cnt-1) + 1);
    }else if(cnt<4){
      a = max(a, dfs(r, st|(1<<c), cnt+1));
    }
    r[i]--;
  }

  return a;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(f,-1);
    FORR(j,1,n) FORR(i,1,4) scanf("%d",&v[i][j]);
    FORR(i,1,4) r[i]=0;
    int ansMax=dfs(r,0,0);
    printf("%d\n",ansMax);
  }

  return 0;
}

/*
const int MAX=44;
const int INF=0x3f3f3f3f;
int n,v[5][MAX];
int f[MAX][MAX][MAX][MAX],g[MAX][MAX][MAX][MAX];

bool match(int s, int c){
  return s & (1<<c);
}

int dp(int, int, int, int);
void dp(int a1, int a2, int a3, int a4, int c, int &a, int &s){
  int t = dp(a1,a2,a3,a4);
  int ts = g[a1][a2][a3][a4];
  int cnt = 0;
  while(ts) { cnt += ts&1; ts>>=1; }
  ts = g[a1][a2][a3][a4];
  t += match(ts,c);
  if(a < t && cnt<=4){
    a = t;
    if(match(ts,c)){
      s = ts & (~(1<<c));
    }else{
      s = ts | (1<<c);
    }
  }
}

int dp(int a1, int a2, int a3, int a4){
  int &a=f[a1][a2][a3][a4],t;
  if(a!=-1) return a;
  int &s=g[a1][a2][a3][a4],ts;
  a=-INF; s=0;
  
  if(a1>=1) dp(a1-1,a2,a3,a4,v[1][a1],a,s);
  if(a2>=1) dp(a1,a2-1,a3,a4,v[2][a2],a,s);
  if(a3>=1) dp(a1,a2,a3-1,a4,v[3][a3],a,s);
  if(a4>=1) dp(a1,a2,a3,a4-1,v[4][a4],a,s);

  return a;
}

void print(int st){
  ROR(i,20,1) printf("%d",bool(st&(1<<i)));
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(f,-1); f[0][0][0][0]=0, g[0][0][0][0]=0;
    FORR(j,1,n) FORR(i,1,4) scanf("%d",&v[i][j]);
    int ansMax=0;
    FORR(i,1,n) FORR(j,1,n) FORR(k,1,n) FORR(l,1,n){
      ansMax=max(ansMax,dp(i,j,k,l));
    }
#ifdef DEBUG
    FORR(i,0,n) FORR(j,0,n) FORR(k,0,n) FORR(l,0,n){
      printf("  dp(%d,%d,%d,%d): %4d, st: ",i,j,k,l,dp(i,j,k,l));
      print(g[i][j][k][l]);
      putchar('\n');
    }
#endif
    printf("%d\n",ansMax);
  }

  return 0;
}
*/
