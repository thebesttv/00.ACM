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
typedef pair<LL,LL> pii;

const int MAX = 1200;
int n,m;


struct Node{
  LL t, l, r;
}v[MAX];

bool solve(){
  scanf("%d%d",&n,&m);
  map<int, pii> mp;
  mp[0] = {m,m};
  bool bad = 0;
  FORR(i,1,n){
    int t; LL l,r;
    scanf("%d%lld%lld",&t,&l,&r);

    if(mp.count(t)){
      pii p = mp[t];
      if(r < p.FI || l > p.SE)
        bad = 1;
      p.FI = max(l,p.FI);
      p.SE = min(r,p.SE);
      if(p.FI > p.SE)
        bad = 1;
      mp[t] = p;
    }else{
      mp[t] = {l,r};
    }
  }
  if(bad) return false;
  n = mp.size();
#ifdef DEBUG
  printf("  mp size %d\n",(int)mp.size());
#endif

  int tail = 1;
  for(auto p : mp){
    v[tail++] = {p.FI, p.SE.FI, p.SE.SE};
  }

  /*
  FORR(i,2,n){
    FOR(j,1,i){
      LL tl = v[i].l - (v[i].t - v[j].t);
      LL tr = v[i].r + (v[i].t - v[j].t);
      if(v[j].l > tr || v[j].r < tl)
        return false;
    }
  }
  */
  LL l = v[n].l, r = v[n].r;
  ROR(i,n-1,1){
    LL tl = l - (v[i+1].t - v[i].t);
    LL tr = r + (v[i+1].t - v[i].t);
    l = max(tl, v[i].l);
    r = min(tr, v[i].r);
    if(l>r) return false;
  }

  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    printf("%s\n", solve() ? "YES" : "NO");
  }

  return 0;
}
