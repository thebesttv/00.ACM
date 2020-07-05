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

const int MAX = 120;
int n,m, cntp[26], cnth[26];
char p[MAX], h[MAX];

bool ok(int s){
  MST(cnth,0);
  FOR(i,0,n) ++cnth[h[i+s]-'a'];
  FOR(i,0,26) if(cntp[i] != cnth[i])
    return false;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(cntp,0);
    scanf("%s%s",p,h);
    n = strlen(p);
    m = strlen(h);
    FOR(i,0,n) ++cntp[p[i]-'a'];

    bool done = 0;
    FORR(i,0,m-n) if(ok(i)){
      done = 1; break;
    }
    printf("%s\n",done ? "YES" : "NO");
  }

  return 0;
}
