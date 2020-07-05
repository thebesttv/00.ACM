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

const int MAX = 1000020;
int n, m, f[MAX];
char s[MAX], p[MAX];

int main(void){
  scanf("%s%s",s,p);
  n = strlen(s), m = strlen(p);

  int j = 0;
  f[0] = f[1] = 0;
  FOR(i,1,m){
    while(j && p[i]!=p[j]) j = f[j];
    if(p[i] == p[j]) ++j;
    f[i+1] = j;
  }

  j = 0;
  FOR(i,0,n){
    while(j && s[i] != p[j]) j = f[j];
    if(s[i] == p[j]) ++j;
    if(j==m) printf("%d\n",i-j+2), j = f[j];
  }
  FORR(i,1,m) printf("%d ",f[i]); putchar('\n');

  return 0;
}
