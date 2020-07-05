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

int n;
char s[120];
bool isV[128];

bool ok(){
  if(!isV[s[n-1]] && s[n-1]!='n') return 0;
  FOR(i,0,n){
    if(!isV[s[i]] && s[i]!='n'){
      if(!isV[s[i+1]]) return 0;
    }
  }
  return true;
}

int main(void){
  isV['a'] = isV['e'] = isV['i'] = isV['o'] = isV['u'] = 1;
  scanf("%s",s);
  n = strlen(s);
  printf("%s\n", ok() ? "YES" : "NO");

  return 0;
}
