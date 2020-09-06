// Tag: 递推 可出题
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
const int MOD = 1e9 + 7;
int n,w,h;
bool vis[40][40]; pii rec[20];

struct Poly{
  VR<pii> v; LL h; int a, b;
  Poly(int n) : v(vector<pii>(rec, rec+n)), h(0), a(0), b(0) {
    norm(); VR<LL> vh;
    auto record = [&](){
      FOR(i,0,4) vh.pb(hash()), rotate();
      return;
    };

    for(auto p : v) a = max(a, p.FI), b = max(b, p.SE);

    record();
    flip(); record();
    sort(ALL(vh));
    for(auto x : vh) h = (h * 224737 + x)%MOD;
  }
  bool operator < (const Poly &b) const {
    return h < b.h;
  }
  bool operator == (const Poly &b) const {
    return h == b.h;
  }
  LL hash(){
    LL hx = 0, hy = 0;
    for(auto p : v){
      hx = (hx * 1299709 + p.FI * 7919);
      hy = (hy * 1299709 + p.SE * 7919);
    }
    return (hx * 2750159 + hy) %MOD;
  }
  void norm(){
    int xm = 100, ym = 100;
    for(auto p : v) xm = min(xm, p.FI), ym = min(ym, p.SE);
    --xm, --ym;
    for(auto &p : v) p.FI -= xm, p.SE -= ym;
    sort(ALL(v));
  }
  void rotate(){  // rotate 90 degrees counterclockwise
    for(auto &p : v) p = {-p.SE, p.FI};
    norm();
  }
  void flip(){
    for(auto &p : v) p = {-p.FI, p.SE};
    norm();
  }
};
VR<Poly> vec[11];

void expand(int n){ // 从 n-1 构造 n
  for(auto poly : vec[n-1]){
    FOR(i,0,n-1){
      rec[i] = poly.v[i];
      vis[rec[i].FI][rec[i].SE] = 1;
    }
    for(auto p : poly.v) FOR(d,0,4){
      int tx = p.FI + to[d][0];
      int ty = p.SE + to[d][1];
      if(vis[tx][ty]) continue;
      rec[n-1] = {tx,ty};
      vec[n].pb(Poly(n));
    }
    for(auto p : poly.v) vis[p.FI][p.SE] = 0;
  }
}

int main(void){
  rec[0] = {0,0}; vec[1].pb(Poly(1));
  for(n=2;n<=10;++n){
    expand(n);
    sort(ALL(vec[n])); vec[n].erase(unique(ALL(vec[n])), vec[n].end());
#ifdef DEBUG
    printf("%d: %d\n",n,(int)vec[n].size());
#endif
  }
#ifdef DEBUG
  for(auto p : vec[5]){
    // printf("size: (%d, %d)\n",p.a,p.b);
    printf("Graphics@{");
    bool first = true;
    for(auto v : p.v){
      if(first) first = 0;
      else putchar(',');
      printf("Rectangle[{%d,%d}]",v.FI,v.SE);
    }
    printf("}\n");
  }
#endif

  while(scanf("%d%d%d",&n,&w,&h)==3){
    int cnt = 0;
    for(auto p : vec[n])
      if((p.a <= w && p.b <= h) || (p.a <= h && p.b <= w))
        ++cnt;
    printf("%d\n",cnt);
  }

  return 0;
}
