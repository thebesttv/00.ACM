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
#include<unordered_map>
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

const int MAX = 1<<20;
int n,m,a[MAX];
VR<int> v;
unordered_map<int, pii> vis;

bool cal(){
  ++vis[0].FI;  // empty set
  FOR(i,1,m){
    auto &p = vis[a[i]];
#ifdef DEBUG
    printf("  vis[%d]: %d, %d, v.size(): %d\n",i,p.FI,p.SE,(int)v.size());
#endif
    if(p.FI >= p.SE) continue;
    // new
    int nn = v.size();
    FOR(st,0,1<<nn){
      int s = a[i];
      FOR(j,0,nn) if(st&(1<<j)){
        s += v[j];
      }
      ++vis[s].FI;
#ifdef DEBUG
      printf("  ++ vis[%d] -> %d\n",s,vis[s].FI);
#endif
    }
    v.push_back(a[i]);
    if(v.size()>n) return false;
#ifdef DEBUG
    for(int x : v) printf(" %d",x); putchar('\n');
#endif
  }

  if(v.size()!=n) return false;
  for(auto p : vis) if(p.SE.FI != p.SE.SE)
    return false;
  return true;
}

int main(void){
  scanf("%d",&n); m=1<<n;
  FOR(i,0,m){
    scanf("%d",&a[i]);
    ++vis[a[i]].SE;
  }
  sort(a,a+m);

  if(!cal()) printf("impossible\n");
  else{
    sort(ALL(v));
    for(int x : v) printf("%d\n",x);
  }

  return 0;
}
