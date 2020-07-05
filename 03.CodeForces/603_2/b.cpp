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

const int MAX = 20;
int n; string v[MAX];

bool hasSame(int i, string &s){
  FOR(j,0,n) if(i!=j)
    if(s == v[j]) return true;
  return false;
}

int main(void){
  int T; cin >> T;
  while(T--){
    cin >> n;
    FOR(i,0,n) cin >> v[i];

    int ans = 0;
    FOR(i,1,n) if(hasSame(i, v[i])){
      ++ans;
      bool ok = 0;
      FOR(j,0,4){
        string ori = v[i];
        FORR(k,'0','9'){
          v[i][j] = k;
          if(!hasSame(i, v[i])){
            ok = 1; break;
          }
        }
        if(ok) break;
        v[i] = ori;
      }
    }
    cout << ans << endl;
    FOR(i,0,n) cout << v[i] << endl;
  }

  return 0;
}
