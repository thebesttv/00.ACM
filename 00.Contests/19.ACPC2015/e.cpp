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

const int MAX = 2e4 + 20;
int a,b,n,l[64],r[64];
LLU v[MAX];
VR<pii> g[64];
bool vis[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0);
    scanf("%d%d",&a,&b);
    n = a + b + 1;
    FORR(i,1,n) scanf("%llu",&v[i]);
    FOR(i,0,64){
      g[i].clear();
      int l=1,r;
      while(l<=n){
        while(l<=n && (v[l]&(1llu<<i))==0) ++l;
        if(l>n) break;
        r = l;
        while(r+1<=n && v[r+1]&(1llu<<i)) ++r;
        g[i].push_back({l,r});
        l = r+1;
      }
#ifdef DEBUG
      if(!g[i].size()) continue;
      printf("  g[%d]:",i);
      for(auto p : g[i]) printf(" (%d,%d)",p.FI,p.SE);
      putchar('\n');
#endif
    }

    FOR(i,0,64)
      if(g[i].size()){
        l[i] = g[i].back().FI;
        r[i] = g[i].back().SE;
      }else{
        l[i] = r[i] = 0;
      }

    int last = n;
    LLU ans = 0;
    ROR(i,63,0) if(l[i]){
      int cnt = last - r[i] + (l[i]!=1);
#ifdef DEBUG
      printf("  i: %d, cnt: %d, last: %d\n",i,cnt,last);
#endif
      if(cnt>b) continue;
      b -= cnt, last -= cnt;
      ans |= 1llu<<i;
    }
    printf("%llu\n",ans);
  }
  return 0;
}
