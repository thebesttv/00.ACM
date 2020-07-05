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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 520;
int n,a[MAX],b[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&b[i]);

    if((n&1) && a[n/2] != b[n/2]){
      printf("No\n"); continue;
    }

    map<pii, int> mp;
    FOR(i,0,n/2){
      mp[{a[i], a[n-i-1]}]++;
      mp[{a[n-i-1], a[i]}]++;
    }

    bool bad = 0;
    FOR(i,0,n/2){
      if(mp.count({b[i], b[n-i-1]})){
        if(mp[{b[i], b[n-i-1]}] < 1){
          bad = 1; break;
        }
        mp[{b[i], b[n-i-1]}]--;
        mp[{b[n-i-1], b[i]}]--;
      }else{
        bad = 1; break;
      }
    }

    printf("%s\n", bad ? "No" : "Yes");
  }

  return 0;
}
