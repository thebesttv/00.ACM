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

const int MAX=120;
const int MOD=10001;
int n; LL v[MAX];

void gcd(LL a, LL b, LL &d, LL &x, LL &y){
  if(!b) { d = a, x = 1, y = 0; }
  else { gcd(b, a%b, d, y, x); y -= x * (a/b); }
}

bool ok(LL a, LL b){
  FOR(i,0,n-1){
    LL ans = ( a*v[i] + b )%MOD;
    ans = ( a*ans + b)%MOD;
    if(ans != v[i+1]) return 0;
  }
  return 1;
}

int main(void){
  cin >> n;
  FOR(i,0,n) cin >> v[i];

  LL ra=-1, rb=-1;
  FOR(a,0,MOD){
    LL right = ( v[1] - LL(a)*a*v[0] ) % MOD;
    LL d, x, y;

    gcd(a+1, MOD, d, x, y);
    if(right % d) continue;

    x = x * (right / d);
    LL b = (x%MOD + MOD)%MOD;
    if(ok(a,b)){
      ra = a, rb = b; break;
    }
  }
  /*
  FOR(a,0,MOD) FOR(b,0,MOD)
    if(ok(a,b)){
      ra = a, rb = b; break;
    }
  */

  FOR(i,0,n){
    cout << (ra*v[i] + rb)%MOD << endl;
  }

  return 0;
}
