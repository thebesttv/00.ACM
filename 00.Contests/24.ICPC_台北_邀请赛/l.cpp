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

const int MAX = 5000;
int n; pii point[MAX];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

map<pii,VR<pii>> mp;

LL area(pii v1, pii v2){
  int a = v1.FI, b = v1.SE, c = v2.FI;
  v1 = {point[b].FI - point[a].FI, point[b].SE - point[a].SE};
  v2 = {point[c].FI - point[a].FI, point[c].SE - point[a].SE};
  return abs(1ll*v1.FI*v2.SE - 1ll*v1.SE*v2.FI);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    mp.clear();
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&point[i].FI,&point[i].SE);
      FOR(j,0,i){
        pii p{point[j].FI - point[i].FI, point[j].SE - point[i].SE};
        if(p.FI<0){
          p.FI=-p.FI, p.SE=-p.SE;
          mp[p].push_back({j,i});
        }else{
          mp[p].push_back({i,j});
        }
      }
    }

    LL ansMax = 0;
    for(auto p : mp){
      VR<pii> &v = p.SE;
#ifdef DEBUG
      printf("(%d,%d):",p.FI.FI,p.FI.SE);
      for(auto pp : v){
        printf(" {%d,%d}",pp.FI,pp.SE);
      }
      putchar('\n');
#endif
      if(v.size()<2) continue;
      FOR(i,0,v.size()) FOR(j,i+1,v.size()){
        pii v1 = v[i], v2 = v[j];
        ansMax = max(ansMax, area(v1,v2));
      }
    }
    printf("%lld\n",ansMax);
  }

  return 0;
}
