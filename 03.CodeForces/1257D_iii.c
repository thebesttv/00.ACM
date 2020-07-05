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

const int MAX=2e5+20;
const int INF=0x3f3f3f3f;
int n,m,a[MAX],f[MAX];  // f[i]: endurance >=i 的最大 power

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int aMax=0, pMax=0;
    scanf("%d",&n);
    FORR(i,1,n){
      scanf("%d",&a[i]);
      aMax=max(aMax,a[i]);
    }

    //MST(f,0);
    FORR(i,1,n) f[i]=0;
    scanf("%d",&m);
    int p,s;
    FOR(i,0,m){
      scanf("%d%d",&p,&s);
      f[s]=max(f[s], p);
      pMax=max(pMax,p);
    }
    if(aMax > pMax){
      printf("-1\n"); continue;
    }

    ROR(i,n-1,1) f[i]=max(f[i],f[i+1]);

    int i = 1, ans = 0;
    while(i<=n){
      int x = 1, aMax = a[i];
      while(i+x<=n){
        aMax = max(aMax,a[i+x]);
        if(aMax > f[x+1]) break;
        x++;
      }
      i += x; ans++;
    }
    printf("%d\n",ans);
  }

  return 0;
}


/*
const int MAX=2e5+20;
const int INF=0x3f3f3f3f;
int n,m,a[MAX],b[MAX], c[MAX];

struct Ind{
  int p, s;
  bool operator < (const Ind &b) const {
    return p < b.p;
  }
};
VR<Ind> ind;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(c,0); ind.clear();

    scanf("%d",&n);
    int aMax=0, pMax=0, tailB=0;
    FOR(i,0,n){
      scanf("%d",&a[i]);
      aMax=max(aMax,b[i]=a[i]);
    }
    sort(b,b+n); tailB = unique(b,b+n) - b;

    scanf("%d",&m);
    FOR(i,0,m){
      int p, s; scanf("%d%d",&p,&s);
      if(p<b[0]) continue;
      pMax=max(pMax,p);

      int j = lower_bound(b,b+tailB,p) - b;
      if(j>=tailB || b[j]>p) --j;

      p = b[j]; c[j] = max(c[j], s);
#ifdef DEBUG
      printf("  get %d, %d\n",p,s);
#endif
    }
    if(aMax > pMax){
      printf("-1\n"); continue;
    }

    FOR(i,0,tailB) if(c[i])
      ind.push_back({b[i], c[i]});

    int i = 0, ans = 0;
    while(i<n){
      int l = lower_bound(ALL(ind), Ind{a[i],0}) - ind.begin();
      int j = i, tMax=0;
      FOR(k,l,m){
        while(j<=n && a[j] <= ind[k].p) j++;
        tMax = max(tMax, min(ind[k].s, j-i));
      }
      i += tMax; ans++;
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
