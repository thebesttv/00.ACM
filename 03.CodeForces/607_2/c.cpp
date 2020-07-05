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

const LL MOD = 1e9 + 7;
int x; string s;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cin >> x >> s;
    LL ans = s.size();
    FORR(i,1,x){
      ans = ( ans + (ans-i+MOD)%MOD * (s[i-1]-'1') ) % MOD;
      int t = s.size();
      if(s.size()<x) FOR(j,'1',s[i-1]){
        FOR(k,i,t) s.push_back(s[k]);
        if(s.size()>=x) break;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
