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

const int MAX = 40;
const int MOD = 1e9 + 7;
LL frac[MAX];
int n,ex,ey,len[1<<20];
struct Node{
  int x, y;
}p[MAX];

int _len(int x){
  int s = 0;
  while(x) s += x&1, x>>=1;
  return s;
}

map<LL, map<LL,VR<int>>> mp1, mp2;
void cal(int beg, int n, map<LL, map<LL,VR<int>>> &mp){
  FOR(st,0,1<<n){
    LL x = 0, y = 0;
    FOR(i,0,n) if(st&(1<<i)){
      x += p[beg+i].x;
      y += p[beg+i].y;
    }
    mp[x][y].push_back(len[st]);
#ifdef DEBUG
    printf("  mp(%lld, %lld), st: %d, len: %d\n",x,y,st,len[st]);
#endif
  }
}

int cnt1[MAX], cnt2[MAX];
LL proc(const VR<int> &v1, const VR<int> &v2){
#ifdef DEBUG
  printf("v1:"); for(int x : v1) printf(" %d",x); putchar('\n');
  printf("v2:"); for(int x : v2) printf(" %d",x); putchar('\n');
#endif
  if(1ll*v1.size()*v2.size() < 20){
    LL ans = 0;
    for(int x : v1) for(int y : v2)
      ans = (ans + frac[x+y])%MOD;
    return ans;
  }

  MST(cnt1, 0), MST(cnt2, 0);
  for(int x : v1) ++cnt1[x];
  for(int x : v2) ++cnt2[x];

  LL ans = 0;
  FORR(i,0,16) if(cnt1[i])
    FORR(j,0,16) if(cnt2[j]) {
      ans = (ans + 1ll*cnt1[i]*cnt2[j]%MOD*frac[i+j]%MOD)%MOD;
    }
  return ans;
}

int main(void){
  frac[0] = frac[1] = 1;
  FORR(i,2,32) frac[i] = frac[i-1]*i%MOD;
  FOR(i,0,1<<17) len[i] = _len(i);

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&ex,&ey);
    FOR(i,0,n) scanf("%d%d",&p[i].x, &p[i].y);
    if(n==1){
      printf("%d\n", p[0].x == ex && p[0].y == ey);
      continue;
    }

    mp1.clear(); mp2.clear();
    int r = n/2;
    cal(0, r, mp1);
    cal(r, n-r, mp2);

    LL ans = 0;
    for(const auto &px : mp1){
      LL dx = ex - px.FI;
      if(!mp2.count(dx))
        continue;
      for(const auto &py : px.SE) {
        LL dy = ey - py.FI;
        if(!mp2[dx].count(dy)) continue;
#ifdef DEBUG
        printf("  proc (%lld, %lld), (%lld, %lld)\n",px.FI,py.FI,dx,dy);
#endif
        ans = (ans + proc(py.SE, mp2[dx][dy]))%MOD;
      }
    }
    printf("%lld\n",ans);
  }

  return 0;
}
