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

const int MAX=120;
int n,f[MAX][MAX]; char s[MAX];

bool match(int ch1, int ch2){
  switch(ch1){
    case '(': return ch2==')';
    case '[': return ch2==']';
    case '{': return ch2=='}';
  }
  return 0;
}

int dp(int i, int j){
  int &a=f[i][j];
  if(a!=-1) return a;
  a=0;
  if(i+1==j){
    if(match(s[i],s[j])) a=2;
    else a=0;
  }else if(i<j){
    FOR(k,i,j) a = max(a, dp(i,k) + dp(k+1,j));
    if(match(s[i],s[j])) a = max(a, 2 + dp(i+1,j-1));
  }
  return a;
}

int main(void){
  while(true){
    n=0; int ch;
    do ch=getchar(); while(ch=='\n');
    do { s[++n]=ch; ch=getchar(); } while(ch!='\n');
    if(s[1]=='e') break;

    MST(f,-1);
    printf("%d\n",dp(1,n));
  }

  return 0;
}
