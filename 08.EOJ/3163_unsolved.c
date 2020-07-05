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

const int MAX=1020;
int n,m,k;
bool vis[MAX];

struct Node{
  int l,r,t;
  bool operator < (const Node &b) const {
    return r < b.r;
  }
}node[MAX];

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(vis,0);
    int x,l,r,ans = 0;
    scanf("%d%d%d",&n,&m,&k);
    while(k--){
      scanf("%d",&x); vis[x]=1;
    }
    bool impossible = 0;
    FOR(i,0,m){
      scanf("%d%d%d",&l,&r,&x);
      if(r-l+1 < x){
        printf("Case %d: %d\n",kase,-1);
        impossible = 1; break;
      }
      node[i] = {l,r,x};
    }
    if(impossible) continue;
    sort(node, node+m);

    FOR(i,0,m){
      l = node[i].l, r = node[i].r, x = node[i].t;
      int cnt = 0;
      FORR(j,l,r) if(vis[j]) cnt++;
      if(cnt>=x) continue;

      cnt = x - cnt;
      ROR(j,r,l) if(!vis[j]){
        ans++; vis[j]=1;
        if(--cnt == 0) break;
      }
    }
    printf("Case %d: %d\n",kase,ans);
  }

  return 0;
}
