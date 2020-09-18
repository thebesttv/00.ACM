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

const int MAX = 100000 + 20;
int n,m,a[MAX];

struct ST{
  int v[MAX<<2];
  void build(int *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, int *a){
    if(l == r) { v[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    v[u] = v[u<<1] + v[u<<1|1];
  }
  void negate(int p){
    negate(1,1,n,p);
  }
  void negate(int u, int l, int r, int p){
    if(l == r) { v[u] ^= 1; return; }
    int m = (l+r)/2;
    if(p <= m) negate(u<<1, l, m, p);
    else negate(u<<1|1, m+1, r, p);
    v[u] = v[u<<1] + v[u<<1|1];
  }

  int find(int k){
    return find(1,1,n,k);
  }
  int find(int u, int l, int r, int k){
    if(l == r) return l;
    int m = (l+r)/2;
    if(v[u<<1] >= k) return find(u<<1, l, m, k);
    else return find(u<<1|1, m+1, r, k - v[u<<1]);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]);
  sg.build(a,n);

  while(m--){
    int op; scanf("%d",&op);
    if(op == 1){
      int p; scanf("%d",&p); sg.negate(p+1);
    }else{
      int x; scanf("%d",&x);
      printf("%d\n",sg.find(x+1)-1);
    }
  }

  return 0;
}
