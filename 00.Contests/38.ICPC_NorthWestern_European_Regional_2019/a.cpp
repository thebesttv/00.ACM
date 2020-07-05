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
#define ALL(x) (x).begin(),(x).end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 3e5 + 20;
int n,m;

struct Rank{
  int rk, l, r;
};
VR<Rank> v[int(1e6 + 20)];
VR<LL> vsum[int(1e6 + 20)];

struct Rec{
  int l, r;
  VR<Rank> *v;
};
VR<Rec> ind[MAX];

LL getSum(const VR<Rank> &v, const VR<LL> &vsum, int ql, int qr){
  LL sum = 0;
#ifdef DEBUG
  printf("  query [%d, %d]:",ql,qr);
  for(auto p : v) printf(" (rk %d, %d %d)",p.rk,p.l,p.r);
  putchar('\n');
#endif
  int L, R, l = 0, r = v.size();
  while(l<r){ // smallest v.r such that v.r >= ql
    int m = (l+r)>>1;
    if(v[m].r >= ql)
      r = m;
    else
      l = m+1;
  }
  L = l;

  l = 0, r = v.size() - 1;
  while(l<r){ // biggest v.l such that v.l <= qr
    int m = (l+r+1)>>1;
    if(v[m].l <= qr)
      l = m;
    else
      r = m - 1;
  }
  R = l;

#ifdef DEBUG
  printf("    L: %d, R: %d\n",L,R);
#endif

  if(L==R){
    return 1ll * v[L].rk * (qr - ql + 1);
  }

  if(v[L].l < ql){
    sum += 1ll * v[L].rk * (v[L].r - ql + 1);
    ++L;
  }
  if(v[R].r > qr){
    sum += 1ll * v[R].rk * (qr - v[R].l + 1);
    --R;
  }
  if(L > R) return sum;
  sum += vsum[R] - (L==0 ? 0 : vsum[L-1]);
  return sum;

  /*
  while(it != v.begin() && it->r >= l) --it;
  while(it != v.end() && it->l <= r){
    if(it->r >= l){
      sum += 1ll * it->rk * (min(it->r, r) - max(it->l, l) + 1);
    }
    ++it;
  }
  return sum;
  */
}

int main(void){
  scanf("%d%d",&n,&m);
  int k, x; scanf("%d",&k);
  FOR(i,0,k){
    scanf("%d",&x);
    ind[x].push_back({1,0,v+1});
  }
  FORR(i,1,n) if(ind[i].empty()){
    ind[i].push_back({1,0,v});
  }

  v[0].push_back({k+1,1,0});
  v[1].push_back({1,1,0});

  FORR(i,2,m){
    scanf("%d",&k);
    map<int, int> mp;
    while(k--){
      scanf("%d",&x);
      int st = 0;
      ind[x].back().r = i-1;
      st = ind[x].back().v - v;
      ind[x].push_back({i,0,v+st+1});
#ifdef DEBUG
      printf("  ind %d, -> (%d, %d, v[%d])\n",x,i,0,st+1);
#endif
      ++mp[st];
    }

    for(auto p : mp){
      v[p.FI].back().r = i-1;
#ifdef DEBUG
      printf("  v[se %d] -> (rk %d, %d, %d)\n",p.FI,v[p.FI].back().rk + p.SE, i, 0);
#endif
      v[p.FI].push_back({v[p.FI].back().rk + p.SE, i, 0});
      if(v[p.FI+1].empty()){  // last
        v[p.FI+1].push_back({1,i,0});
#ifdef DEBUG
        printf("  new v[%d] -> (rk %d, %d, %d)\n",p.FI+1,1,i,0);
#endif
      }
    }
  }

  FORR(i,1,n) ind[i].back().r = m;
  FORR(i,0,int(1e6)) if(!v[i].empty()){
    v[i].back().r = m;
    auto &p = v[i].front();
    vsum[i].resize(v[i].size());
    vsum[i][0] = 1ll * p.rk * (p.r - p.l + 1);
    FOR(j,1,v[i].size()){
      auto &p = v[i][j];
      vsum[i][j] = vsum[i][j-1] + 1ll * p.rk * (p.r - p.l + 1);
    }
  }

  FORR(i,1,n){
#ifdef DEBUG
    printf("ind[%d]:\n",i);
#endif
    LL sum = 0;
    for(Rec &r : ind[i]){
      sum += getSum(*(r.v), vsum[r.v-v], r.l, r.r);
    }
    printf("%.10lf\n",1.0*sum/m);
  }

  return 0;
}
