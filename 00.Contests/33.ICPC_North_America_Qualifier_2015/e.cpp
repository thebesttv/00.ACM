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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 520;
int n,m; int dp[MAX][MAX][2];
char s[20];

int f(int n, int m, bool isH){  // if will fail
  int &a = dp[n][m][isH];
  if(a!=-1) return a;
  if((isH && n==1) || (!isH && m==1)){
    return a = 1;
  }

  a = 1;
  if(isH){  // find one that wins
    FOR(i,1,n){
      int b1 = f(i,m,0),
          b2 = f(n-i,m,0);
      if(b1 && b2){
        a = 0; break;
      }
    }
  }else{
    FOR(j,1,m){
      int b1 = f(n,j,1),
          b2 = f(n,m-j,1);
      if(b1 && b2){
        a = 0; break;
      }
    }
  }
  return a;
}

int main(void){
  MST(dp,-1);
  dp[1][1][0] = dp[1][1][1] = 1;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%s",&m,&n,s);
    if(s[0] == 'H'){
      printf("%s %s win\n",s, f(n,m,1) ? "cannot" : "can");
    }else{
      printf("%s %s win\n",s, f(n,m,0) ? "cannot" : "can");
    }
  }

  return 0;
}

/*
const int MAX = 520;
int n,m; int dp[MAX][MAX][2][2];
char s[20];

int f(int n, int m, bool isH, bool willWin){
  int &a = dp[n][m][isH][willWin];
  if(a != -1) return a;
  if((isH && n==1) || (!isH && m==1)){
    if(willWin) a = 0;
    else a = 1;
    return a;
  }

  if(isH){
    if(willWin){
      FOR(i,1,n){
        bool w1 = f(i,m,0,1),
             l1 = f(i,m,0,0),
             w2 = f(n-i,m,0,1),
             l2 = f(n-i,m,0,0);
        if(l1){
          if(w2) return a = 0;
          else if(l2) return a = 1;
        }else if(l2){
          if(w1) return a = 0;
          else if(l1) return a = 1;
        }
      }
    }else{
      FOR(i,1,n){
        bool w1 = f(i,m,0,1),
             l1 = f(i,m,0,0),
             w2 = f(n-i,m,0,1),
             l2 = f(n-i,m,0,0);
        if(l1){
          if(w2) return a = 1;
          else if(l2) return a = 0;
        }else if(l2){
          if(w1) return a = 1;
          else if(l1) return a = 0;
        }
      }
    }
  }else{
    if(willWin){
      FOR(j,1,m){
        bool w1 = f(n,j,1,1),
             l1 = f(n,j,1,0),
             w2 = f(n,m-j,1,1),
             l2 = f(n,m-j,1,0);
        if(l1){
          if(w2) return a = 0;
          else if(l2) return a = 1;
        }else if(l2){
          if(w1) return a = 0;
          else if(l1) return a = 1;
        }
      }
    }else{
      FOR(j,1,m){
        bool w1 = f(n,j,1,1),
             l1 = f(n,j,1,0),
             w2 = f(n,m-j,1,1),
             l2 = f(n,m-j,1,0);
        if(l1){
          if(w2) return a = 1;
          else if(l2) return a = 0;
        }else if(l2){
          if(w1) return a = 1;
          else if(l1) return a = 0;
        }
      }
    }
  }
}

int main(void){
  MST(dp,-1);
  dp[1][1][1][1] = 0;
  dp[1][1][1][0] = 1;
  dp[1][1][0][1] = 0;
  dp[1][1][0][0] = 1;

  // dp[2][1][1][1] = 1;
  // dp[2][1][1][0] = 0;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%s",&m,&n,s);
    if(s[0] == 'H'){
      printf("%s %s win\n",s, f(n,m,1,1) ? "can" : "cannot");
    }else{
      printf("%s %s win\n",s, f(n,m,0,1) ? "can" : "cannot");
    }
  }

  return 0;
}
*/
