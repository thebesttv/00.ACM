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

const int MAX = 1020;
LL X0, Y0, ax, ay, bx, by, sx, sy, t;
LL x[MAX], y[MAX]; int tail;
LL d[MAX];

int main(void){
  cin >> X0 >> Y0 >> ax >> ay >> bx >> by;
  cin >> sx >> sy >> t;

  x[0] = X0, y[0] = Y0; tail = 1;
  FOR(i,1,MAX){
    x[i] = ax * x[i-1] + bx,
    y[i] = ay * y[i-1] + by;
    if(x[i] >= sx && y[i] >= sy
    && (x[i] - sx + y[i] - sy > t))
      break;
    tail = i+1;
  }
  FOR(i,1,tail){
    d[i] = x[i] - x[i-1] + y[i] - y[i-1];
  }

  int ansMax = 0;
  FOR(s, 0, tail){
    LL left = t - llabs(sx - x[s]) - llabs(sy - y[s]);
    if(left < 0) continue;

    ansMax = max(ansMax, 1);

    LL tot = 0;
    ROR(l, s-1, 0){
      tot += d[l+1];
      if(tot <= left)
        ansMax = max(ansMax, s - l + 1);
      else
        break;
    }

    tot = 0;
    FOR(r, s+1, tail){
      tot += d[r];
      if(tot <= left)
        ansMax = max(ansMax, r - s + 1);
      else
        break;
    }
  }
  printf("%d\n",ansMax);

  return 0;
}
