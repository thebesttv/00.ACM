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

const int MAX = 1e7, MAX_ = 1e7 + 20;
int n, cnt[MAX_];
VR<int> G[MAX_];

int main(void){
  scanf("%d",&n);
  int x;
  FOR(i,0,n){
    scanf("%d",&x);
    ++cnt[x];
    G[x].push_back(i+1);
  }

  LL ans = 1ll*MAX_*MAX_, ri, rj;
  FORR(g,1,MAX){
    LL i=-1,j=-1, idxi, idxj;
    for(int k=g;k<=MAX;k+=g) if(cnt[k]){
      for(int idx : G[k])
        if(i==-1){
          i=k; idxi = idx;
        }else{
          j=k; idxj = idx;
          if(i/g*j < ans){
            ans = i/g*j;
            ri = idxi, rj = idxj;
          }
          break;
        }
      if(j!=-1) break;
    }
  }
  printf("%lld %lld\n",min(ri,rj),max(ri,rj));

  return 0;
}
