// Tag: 线段树 最长连续子序列
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

const int MAX = 1e5 + 20;
int n,m;

struct ST{
  struct Data{
    LL sum, msl, msr, msm, len;
    Data(LL x = 0) : sum(x), len(1) {
      msl = msm = msr = max(x, 0ll);
    }
    Data(LL x, int len) : sum(x * len), len(len) {
      msl = msm = msr = max(x * len, 0ll);
    }
  }v[MAX<<2];
  LL sv[MAX<<2];

  Data merge(const Data &l, const Data &r){
    Data a;
    a.sum = l.sum + r.sum;
    a.msl = max(l.msl, l.sum + r.msl);
    a.msr = max(r.msr, r.sum + l.msr);
    a.msm = max(l.msr + r.msl, max(l.msm, r.msm));
    return a;
  }

  void pushup(int u){
    v[u] = merge(v[u<<1], v[u<<1|1]);
  }
  void pushdown(int u, int l, int r, int m){
    if(sv[u] != INT_MIN){
      v[u<<1] = Data(sv[u], m-l+1);
      v[u<<1|1] = Data(sv[u], r-m);
      sv[u<<1] = sv[u];
      sv[u<<1|1] = sv[u];
      sv[u] = INT_MIN;
    }
  }
  void build(){
    build(1,1,n);
  }
  void build(int u, int l, int r){
    sv[u] = INT_MIN;
    if(l == r) return;
    int m = (l+r)/2;
    build(u<<1, l, m);
    build(u<<1|1, m+1, r);
  }

  void set(int l, int r, LL val){
    set(1,1,n,l,r,val);
  }
  void set(int u, int cl, int cr, int ql, int qr, LL val){
    if(ql <= cl && cr <= qr){
      v[u] = Data(val, cr-cl+1); sv[u] = val;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) set(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) set(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }
  LL query(){
    return v[1].msm;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  while(m--){
    int l,r,v; scanf("%d%d%d",&l,&r,&v);
    sg.set(l+1,r,v);
    printf("%lld\n",sg.query());
  }

  return 0;
}
