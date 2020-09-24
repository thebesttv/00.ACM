// Tag: 线段树
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

const int MAX = 1e6 + 20;
int n = 1e6+4, mid = 5e5 + 1, m;

struct ST{
  struct Data{
    int sum, cnt; bool l, r;
    Data(int s = 0) : sum(s) {  // whole segment
      if(s) cnt = 1, l = r = true;
      else cnt = 0, l = r = false;
    }
  }v[MAX<<2];
  int sv[MAX<<2];

  Data merge(const Data &l, const Data &r){
    Data a;
    a.sum = l.sum + r.sum;
    a.cnt = l.cnt + r.cnt - (l.r && r.l);
    a.l = l.l, a.r = r.r;
    return a;
  }

  void pushup(int u){
    v[u] = merge(v[u<<1], v[u<<1|1]);
  }
  void pushdown(int u, int l, int r, int m){
    if(sv[u] != -1){
      v[u<<1] = sv[u] * (m-l+1);
      v[u<<1|1] = sv[u] * (r-m);
      sv[u<<1] = sv[u<<1|1] = sv[u];
      sv[u] = -1;
    }
  }
  void build(){
    build(1,1,n);
  }
  void build(int u, int l, int r){
    sv[u] = -1;
    if(l == r) return;
    int m = (l+r)/2;
    build(u<<1, l, m);
    build(u<<1|1, m+1, r);
  }

  void set(int l, int r, int val){
    set(1,1,n,l,r,val);
  }
  void set(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      v[u] = val * (cr - cl + 1); sv[u] = val;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) set(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) set(u<<1|1, m+1, cr, ql, qr, val);
    pushup(u);
  }

  pii query(){
    return {v[1].cnt, v[1].sum};
  }
}sg;

int main(void){
  scanf("%d",&m); sg.build();
  while(m--){
    int ch, l, r;
    do ch = getchar(); while(ch != 'W' && ch != 'B');
    scanf("%d%d\n",&l,&r); r = l + r - 1;
    sg.set(l+mid, r+mid, ch == 'B' ? 1 : 0);
    printf("%d %d\n",sg.query().FI,sg.query().SE);
  }

  return 0;
}
