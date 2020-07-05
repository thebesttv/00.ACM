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

const int MAX = 100020;
int n,m; LL ori[MAX];

struct ST{
  LL a[MAX<<2], addVal[MAX<<2];
  void build(int u, int l, int r, LL *ori){
    if(l==r){
      a[u] = ori[l]; return;
    }
    int m=(l+r)>>1;
    build(u<<1,l,m,ori);
    build(u<<1|1,m+1,r,ori);
    a[u] = a[u<<1] + a[u<<1|1];
  }
  void pushDown(int u, int cl, int m, int cr){
    if(addVal[u]){
      a[u<<1] += (m-cl+1) * addVal[u];
      addVal[u<<1] += addVal[u];
      a[u<<1|1] += (cr-m) * addVal[u];
      addVal[u<<1|1] += addVal[u];
      addVal[u] = 0;
    }
  }
  void add(int u, int cl, int cr, int ql, int qr, LL av){
    if(ql <= cl && cr <= qr){
      a[u] += (cr - cl + 1) * av;
      addVal[u] += av;
      return;
    }
    int m = (cl+cr)>>1;
    pushDown(u,cl,m,cr);
    if(ql <= m) add(u<<1, cl, m, ql, qr, av);
    if(qr >= m+1) add(u<<1|1, m+1, cr, ql, qr, av);
    a[u] = a[u<<1] + a[u<<1|1];
  }
  LL sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return a[u];
    }
    int m = (cl + cr) >> 1;
    pushDown(u, cl, m, cr);
    LL s = 0;
    if(ql <= m) s += sum(u<<1, cl, m, ql, qr);
    if(qr >= m+1) s += sum(u<<1|1, m+1, cr, ql, qr);
    return s;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%lld",&ori[i]);
  sg.build(1,1,n,ori);
  int opt, l, r; LL k;
  while(m--){
    scanf("%d%d%d",&opt,&l,&r);
    if(opt==1){
      scanf("%lld",&k);
      sg.add(1,1,n,l,r,k);
    }else{
      printf("%lld\n", sg.sum(1,1,n,l,r));
    }
  }

  return 0;
}
