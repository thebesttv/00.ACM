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

typedef pair<LL,LL> pii;

LL cross(pii v1, pii v2){
  return v1.FI * v2.SE - v1.SE * v2.FI;
}

int main(void){
  pii p[4], a;
  int T; scanf("%d",&T);
  while(T--){
    FOR(i,0,3) scanf("%lld%lld",&p[i].FI,&p[i].SE);
    p[3] = p[0];

    scanf("%lld%lld",&a.FI,&a.SE);
    bool ok = 0;
    FOR(i,0,3) if(a==p[i]){
      swap(p[i],p[0]);
      printf("%lf %lf\n",(p[1].FI+p[2].FI)/2.0,(p[1].SE+p[2].SE)/2.0);
      ok = 1; break;
    }
    if(ok) continue;

    FOR(i,0,3){
      pii v1 = {p[i+1].FI - p[i].FI, p[i+1].SE - p[i].SE};
      pii v2 = {a.FI - p[i].FI, a.SE - p[i].SE};
      if(cross(v1,v2)==0 &&  a.FI <= max(p[i].FI,p[i+1].FI) &&
          a.FI >= min(p[i].FI, p[i+1].FI)){
        if(i==0) swap(p[0],p[2]);
        else if(i==2) swap(p[0],p[1]);

        ok = 1; break;
      }
    }
    if(!ok){
      printf("-1\n"); continue;
    }

    if(a.FI * 2 == p[1].FI + p[2].FI){
      printf("%lf %lf\n",p[0].FI,p[1].SE); continue;
    }
    if(p[1].FI > p[2].FI) swap(p[1],p[2]);
    if(a.FI * 2 > p[1].FI + p[2].FI){
      swap(p[1],p[2]);
    }
    double d1 = dis(p[2],a), sint = sin( atan2(v[0];

    double s = fabs(cross({v[0].FI - v[1].FI, v[0].SE - v[1].SE},
                          {v[0].FI - v[2].FI, v[0].SE - v[2].SE}));
  }

  return 0;
}
