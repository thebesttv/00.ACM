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

const int MAX = 2e5 + 20;
int n,m; char s[MAX];

struct ST{
  int v[MAX<<2]; bool f[MAX<<2];
  void build(int u, int l, int r){
    if(l==r){
      v[u] = s[l]=='1'; return;
    }
    int m = (l+r)>>1;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void pushDown(int u, int l, int r){
    if(f[u]){
      int m = (l+r)>>1;
      f[u<<1]^=1;
      v[u<<1] = m - l + 1 - v[u<<1];

      f[u<<1|1]^=1;
      v[u<<1|1] = r - m - v[u<<1|1];

      f[u] = 0;
    }
  }
  void flip(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      f[u] ^= 1; v[u] = cr - cl + 1 - v[u];
      return;
    }
    pushDown(u,cl,cr);
    int m = (cl + cr)>>1;
    if(ql <= m) flip(u<<1,cl,m,ql,qr);
    if(qr >= m+1) flip(u<<1|1,m+1,cr,ql,qr);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  int sum(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return v[u];
    }
    pushDown(u,cl,cr);
    int m = (cl + cr)>>1, s = 0;
    if(ql <= m) s += sum(u<<1, cl, m, ql, qr);
    if(qr >= m+1) s += sum(u<<1|1, m+1, cr, ql, qr);
    return s;
  }
}sg;

int main(void){
  scanf("%d%d%s",&n,&m,s+1);
  sg.build(1,1,n);
  int op, l, r;
  while(m--){
    scanf("%d%d%d",&op,&l,&r);
    if(!op){
      sg.flip(1,1,n,l,r);
    }else{
      printf("%d\n",sg.sum(1,1,n,l,r));
    }
  }

  return 0;
}
