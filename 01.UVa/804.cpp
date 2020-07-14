// Tag: notag
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

const int MAX = 120;
int n,m,f,a[MAX];
struct Place{
  int v;
  VR<int> out;
}plac[MAX];
struct Tran{
  map<int,int> in;
  VR<int> out;
}tran[MAX];

bool ok(int u){
  for(auto p : tran[u].in)
    if(plac[p.FI].v < p.SE) return false;
  return true;
}

int main(void){
  int kase = 0;
  while(scanf("%d",&n)==1 && n){
    FORR(i,1,n) scanf("%d",&plac[i].v), plac[i].out.clear();
    scanf("%d",&m); int v;
    FORR(u,1,m){
      tran[u].in.clear(), tran[u].out.clear();
      while(scanf("%d",&v)==1 && v){
        if(v > 0){  // out
          tran[u].out.push_back(v);
        }else{
          v = -v;
          tran[u].in[v]++;
          plac[v].out.push_back(u);
        }
      }
    }
    scanf("%d",&f);

    int cnt = 0;
    while(cnt < f){
      int u = -1;
      FORR(i,1,m) if(ok(i)) { u = i; break; }
      if(u == -1) break;
      ++cnt;
#ifdef DEBUG
      printf("cnt %d, u: %d\n",cnt,u);
#endif
      for(auto p : tran[u].in) plac[p.FI].v -= p.SE;
      for(int v : tran[u].out) plac[v].v++;
    }
    if(cnt < f) printf("Case %d: dead after %d transitions\n",++kase,cnt);
    else printf("Case %d: still live after %d transitions\n",++kase,cnt);

    printf("Places with tokens:");
    FORR(i,1,n) if(plac[i].v) printf(" %d (%d)",i,plac[i].v);
    printf("\n\n");
  }

  return 0;
}
