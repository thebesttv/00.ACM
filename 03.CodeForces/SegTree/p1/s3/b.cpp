// Tag: 逆序对 i
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
int n, a[MAX], b[MAX];

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

  void add(int p, int val){
    add(1,1,n,p,val);
  }
  void add(int u, int l, int r, int p, int val){
    v[u] += val;
    if(l == r) return;
    int m = (l+r)/2;
    if(p <= m) add(u<<1, l, m, p, val);
    else add(u<<1|1, m+1, r, p, val);
  }

  int find(int k){
#ifdef DEBUG
    printf("find(%d): %d\n",k,find(1,1,n,k));
#endif
    return find(1,1,n,k);
  }
  int find(int u, int l, int r, int k){
    if(l == r) return l;
    int m = (l+r)/2;
    if(v[u<<1|1] >= k) return find(u<<1|1, m+1, r, k);
    else return find(u<<1, l, m, k - v[u<<1|1]);
  }
}sg;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]), b[i] = 1;
  sg.build(b,n);

  ROR(i,n,1){
    b[i] = sg.find(a[i]+1);
    sg.add(b[i],-1);
  }
  FORR(i,1,n) printf("%d ",b[i]); putchar('\n');

  return 0;
}
