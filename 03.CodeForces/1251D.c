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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define FI first
#define SE second
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2e5+20;
using pii = pair<int, int>;
int n; LL s;
pii v[MAX], vl[MAX], vr[MAX];

bool rev(const pii &a, const pii &b){
  return a.FI > b.FI;
}

bool ok(int m){
  VR<int> mid;
  int cntL = 0, cntR = 0;
  LL sum = 0;

  FOR(i,0,n){
    if(v[i].FI > m) sum += v[i].FI, cntR++;
    else if(v[i].SE < m) sum += v[i].FI, cntL++;
    else mid.push_back(v[i].FI);
  }
  if(cntL > n/2 || cntR > n/2) return 0;
  if(sum > s) return 0;

  sort(ALL(mid));
  int leftL = n/2 - cntL,
      leftR = n/2 - cntR;

  FOR(i,0,leftL) sum += mid[i];
  if(sum > s) return 0;

  sum += 1ll*(leftR+1)*m;

  return sum <= s;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld",&n,&s);
    FOR(i,0,n){
      scanf("%d%d",&v[i].FI,&v[i].SE);
      vl[i] = {v[i].FI,i};
      vr[i] = {v[i].SE,i};
    }
    sort(vl,vl+n);
    sort(vr,vr+n,rev);

    int l = vl[n/2].FI, r = vr[n/2].FI;
    while(l<r){
      int m = (l+r+1)/2;
      if(ok(m)) l = m;
      else r = m-1;
    }
    printf("%d\n",l);
  }

  return 0;
}

/*
const int MAX=2e5+20;
using pii = pair<int, int>;
int n; LL s;
pii v[MAX], vl[MAX], vr[MAX];
bool vis[MAX];

bool rev(const pii &a, const pii &b){
  return a.FI > b.FI;
}

bool ok(int m){
  MST(vis,0); // vis[i]==1: i must be L or R
  VR<int> mustL, mustR, canBoth;

  int p,j;
  p = upper_bound(vr,vr+n,pii{m,0},rev) - vr; // forall r < m
  FOR(i,p,n){
    j = vr[i].SE; vis[j]=1;
    mustL.push_back(j);
  }

  p = upper_bound(vl,vl+n,pii{m,0}) - vl; // forall l > m
  FOR(i,p,n){
    j = vl[i].SE; vis[j]=1;
    mustR.push_back(j);
  }

  if(mustL.size() > n/2 || mustR.size() > n/2) return 0;

  FOR(i,0,n) if(!vis[i])
    canBoth.push_back(i);

  LL sum = 0;
  for(int x : mustL) sum += v[x].FI;
  for(int x : mustR) sum += v[x].FI;
  if(sum > s) return 0;

  VR<int> tv;
  for(int x : canBoth) tv.push_back(v[x].FI);
  sort(ALL(tv));
  int leftL = n/2 - mustL.size(),
      leftR = n/2 - mustR.size();
  FOR(i,0,leftL) sum += tv[i];
  if(sum > s) return 0;

  sum += 1ll*(leftR+1)*m;

  return sum <= s;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%lld",&n,&s);
    FOR(i,0,n){
      scanf("%d%d",&v[i].FI,&v[i].SE);
      vl[i] = {v[i].FI,i};
      vr[i] = {v[i].SE,i};
    }
    sort(vl,vl+n);
    sort(vr,vr+n,rev);

    int l = vl[n/2].FI, r = vr[n/2].FI;
    while(l<r){
      int m = (l+r+1)/2;
#ifdef DEBUG
      printf(" (%d,%d) %d, %d\n",l,r,m,ok(m));
#endif
      if(ok(m)) l = m;
      else r = m-1;
    }
    printf("%d\n",l);
  }

  return 0;
}
*/
