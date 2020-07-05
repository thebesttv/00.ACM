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

const int MOD=47;

int main(void){
  char s1[10], s2[10];
  scanf("%s%s",s1,s2);
  int x1=1, x2=1;
  int len1=strlen(s1), len2=strlen(s2);
  FOR(i,0,len1) x1 = (x1 * (s1[i]-'A'+1))%MOD;
  FOR(i,0,len2) x2 = (x2 * (s2[i]-'A'+1))%MOD;
  printf("%s\n", x1==x2 ? "GO" : "STAY");

  return 0;
}
