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
map<int, int> mp;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mp.clear();
    scanf("%d",&n); int x;
    FOR(i,0,n){
      scanf("%d",&x); ++mp[x];
    }

    auto it = mp.rbegin();
    //printf("%d, %d\n",it->first, it->second);
    int g = 0, s = 0, b = 0;

    g = it->second; ++it;

    while(it!=mp.rend() && s <= g){
      s += it->second; ++it;
    }

    while(it!=mp.rend()){
      if(g + s + b + it->second > n/2) break;
      b += it->second; ++it;
    }

    bool ok = 1;
    if(g<=0 || s<=0 || b<=0) ok = 0;
    if(g>=s || g>=b) ok = 0;
    if(g + s + b > n/2) ok = 0;

    if(!ok) g=s=b=0;

    printf("%d %d %d\n",g,s,b);
  }

  return 0;
}
