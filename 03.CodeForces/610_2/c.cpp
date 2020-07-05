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

const int MAX = 2e5 + 20;
int n,tot,a,b;

struct Node{
  int t, isH;
  bool operator < (const Node &b) const {
    return t!=b.t ? t < b.t : isH < b.isH;
  }
}node[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&tot,&a,&b);
    LL cntE=0, cntH=0;
    FORR(i,1,n){
      scanf("%d",&node[i].isH);
      if(node[i].isH) ++cntH;
      else ++cntE;
    }
    FORR(i,1,n) scanf("%d",&node[i].t);

    sort(node+1,node+1+n);
    node[n+1].t = tot + 1;  // <b> </b>

    LL s = 0, ans = 0;
    FORR(i,0,n){
      if(i){
        s += node[i].isH ? b : a;
        if(node[i].isH) --cntH;
        else --cntE;
      }

      if(s >= node[i+1].t) continue;
      if(s > tot) break;

#ifdef DEBUG
      printf("  for %d, s: %lld, cntE: %d, cntH: %d\n",
          i,s,cntE,cntH);
#endif

      LL left = (node[i+1].t - 1) - s, tans = i;

      LL tn = min( left / a, cntE);
      tans += tn; left -= tn*a;

      tn = min( left / b, cntH);
      tans += tn; left -= tn*b;

      ans = max(ans, tans);
    }
    printf("%lld\n",ans);
  }

  return 0;
}
