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

const int MAX=220;
const int INF=0x3f3f3f3f;
int n,f[MAX][MAX],r[MAX][MAX]; char s[MAX];

bool match(char c1, char c2){
  if(c1=='[') return c2==']';
  if(c1=='(') return c2==')';
  return 0;
}

void print(int i, int j){
  if(i>j) return;
  if(i==j){
    if(s[i]=='(' || s[i]==')') printf("()");
    else printf("[]");
  }else{
    if(match(s[i],s[j]) && f[i][j] == f[i+1][j-1]){
      putchar(s[i]); print(i+1,j-1); putchar(s[j]);
    }else{
      print(i,r[i][j]); print(r[i][j]+1,j);
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  getchar();
  FORR(kase,1,T){
    fgets(s+1,SIZ(s)-1,stdin);
    fgets(s+1,SIZ(s)-1,stdin);
    n=strlen(s+1); s[n--]=0;

    MST(f,0x3f);
    ROR(i,n,1){
      f[i][i-1]=0;  // <b> </b>
      f[i][i]=1;
      FORR(j,i+1,n){
        int &a=f[i][j];
        if(match(s[i],s[j])) a = min(a, f[i+1][j-1]);
        FOR(k,i,j){
          int t = f[i][k] + f[k+1][j];
          if(a>t){
            a=t; r[i][j]=k;
          }
        }
      }
    }
    if(kase>1) putchar('\n');
    print(1,n); putchar('\n');
  }

  return 0;
}

/*
const int MAX=220;
const int INF=0x3f3f3f3f;
int n,f[MAX][MAX]; char s[MAX];

bool match(char c1, char c2){
  if(c1=='[') return c2==']';
  if(c1=='(') return c2==')';
  return 0;
}

int dp(int i, int j){
  if(i>j) return 0;
  int &a=f[i][j];
  if(a!=-1) return a;

  a=INF;
  if(match(s[i],s[j])){
    a = min(a, dp(i+1,j-1));
  }
  FOR(k,i,j){
    a = min(a, dp(i,k) + dp(k+1,j));
  }
  return a;
}

void print(int i, int j){
  if(i>j) return;
  if(i==j){
    if(s[i]=='(' || s[i]==')') printf("()");
    else printf("[]");
  }else{
    if(match(s[i],s[j]) && dp(i,j)==dp(i+1,j-1)){
      putchar(s[i]); print(i+1,j-1); putchar(s[j]);
    }else{
      FOR(k,i,j) if(dp(i,j) == dp(i,k) + dp(k+1,j)){
#ifdef DEBUG
        printf(" (%d,%d) <- (%d,%d)(%d,%d)\n",i,j,i,k,k+1,j);
#endif
        print(i,k); print(k+1,j); break;
      }
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  getchar();
  FORR(kase,1,T){
    //scanf("%s",s+1); n=strlen(s+1);
    fgets(s+1,SIZ(s)-1,stdin);
    fgets(s+1,SIZ(s)-1,stdin);
    n=strlen(s+1); s[n--]=0;

    MST(f,-1); FORR(i,1,n) f[i][i]=1;
#ifdef DEBUG
    printf("get %s\n",s+1);
    //FORR(i,1,n) FORR(j,i,n)
    //  if(dp(i,j)<INF) printf(" f(%d,%d): %d\n",i,j,dp(i,j));
#endif
    dp(1,n);
    if(kase>1) putchar('\n');
    print(1,n); putchar('\n');
  }

  return 0;
}
*/
