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

const int MAX = 2e5 + 20;
int n,k; char s[MAX];
VR<int> pos;
LL f[MAX];

struct ST{
  LL a[MAX<<2];
  void build(int u, int l, int r){
    if(l==r){
      a[u] = LLONG_MAX; return;
    }
    int m=(l+r)>>1;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
    a[u] = LLONG_MAX;
  }
  void set(int u, int cl, int cr, int ql, int qr, LL v){
    if(ql <= cl && cr <= qr){
      a[u] = v;
      return;
    }
    int m = (cl+cr)>>1;
    if(ql <= m) set(u<<1, cl, m, ql, qr, v);
    if(qr >= m+1) set(u<<1|1, m+1, cr, ql, qr, v);

    a[u] = min(a[u<<1] , a[u<<1|1]);
  }
  LL qMin(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return a[u];
    }
    int m = (cl + cr) >> 1;
    LL s = LLONG_MAX;
    if(ql <= m) s = qMin(u<<1, cl, m, ql, qr);
    if(qr >= m+1) s = min( s, qMin(u<<1|1, m+1, cr, ql, qr) );
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&k);
  scanf("%s",s+1);
  FORR(i,1,n) if(s[i]=='1'){
    pos.push_back(i);
  }
  sg.build(1,1,n);

  f[0] = 0;
  FORR(i,1,n){
    int lMost = max(1, i-k);

    if(s[i]=='0')
      f[i] = i + f[i-1];
    else
      f[i] = i + f[lMost-1];

    auto it = lower_bound(ALL(pos), lMost);
    if(it != pos.end() && *it <=i){
      lMost = max(*it - k, 1);
      LL t = sg.qMin(1,1,n, max(lMost-1,1), max(i-1,1));
      if(lMost==1) t = 0;
      // f[i] = min(f[i], *it + f[lMost-1]);
      f[i] = min(f[i], *it + t);
    }
    sg.set(1,1,n,i,i,f[i]);
  }
  printf("%lld\n",f[n]);

  return 0;
}
