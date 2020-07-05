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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 1e6 + 20;
int n; char s[MAX];
int f[MAX], f2[MAX];

void getF(char *s, int n, int *f){
  int j = 0;
  f[0] = f[1] = 0;
  FOR(i,1,n){
    while(j && s[i]!=s[j]) j = f[j];
    if(s[i] == s[j]) ++j;
    f[i+1] = j;
  }
}

bool ok(int len){
  if(len > n-2) return 0;
  // getF(s,len,f2);
  //printf("  %d\n",len);

  int j = 0;
  FOR(i,1,n){
    while(j && s[i] != s[j]) j = f[j];
    if(s[i] == s[j]) ++j;
    // printf("  i: %d, j: %d\n",i,j);
    if(j==len) return i+1 < n;
  }
  return false;
}

int main(void){
  scanf("%s",s);
  n = strlen(s);

  getF(s,n,f);
  //FORR(i,1,n) printf("%d ",f[i]); putchar('\n');

  int j = f[n];
  bool done = 0;
  while(j){
    if(ok(j)){
      printf("%s\n",s + n - j);
      done = 1; break;
    }
    j = f[j];
  }
  if(!done) printf("Just a legend\n");

  return 0;
}
