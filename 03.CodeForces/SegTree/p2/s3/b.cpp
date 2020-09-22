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

const int MAX = 1e5 + 20;
int n,m;

struct ST{
  int v[MAX<<2],inv[MAX<<2];

  void pushup(int u){
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void pushdown(int u, int l, int r, int m){
    if(inv[u]){
      v[u<<1] = m-l+1 - v[u<<1];
      v[u<<1|1] = r-m - v[u<<1|1];
      inv[u<<1] ^= 1;
      inv[u<<1|1] ^= 1;
      inv[u] ^= 1;
    }
  }

  void inverse(int l, int r){
    inverse(1,1,n,l,r);
  }
  void inverse(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      v[u] = cr - cl + 1 - v[u]; inv[u] ^= 1;
      return;
    }
    int m = (cl+cr)/2; pushdown(u,cl,cr,m);
    if(ql <= m) inverse(u<<1, cl, m, ql, qr);
    if(m+1 <= qr) inverse(u<<1|1, m+1, cr, ql, qr);
    pushup(u);
  }

  int query(int k){
    return query(1,1,n,k);
  }
  int query(int u, int l, int r, int k){
    if(l == r) return l;
    int m = (l+r)/2; pushdown(u,l,r,m);
    if(v[u<<1] >= k) return query(u<<1, l, m, k);
    else return query(u<<1|1, m+1, r, k - v[u<<1]);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int l,r; scanf("%d%d",&l,&r);
      sg.inverse(l+1,r);
    }else{
      int k; scanf("%d",&k);
      printf("%d\n",sg.query(k+1)-1);
    }
  }

  return 0;
}
