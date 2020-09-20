// Tag: notag
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

const int MAX = 200020;
int n,m; LL MOD;
struct Matrix{
  LL a,b,c,d;
  Matrix() : a(1), b(0), c(0), d(1) { }
  Matrix(LL a, LL b, LL c, LL d)
    : a(a%MOD), b(b%MOD), c(c%MOD), d(d%MOD) { }
  void read(){
    scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
    a %= MOD, b %= MOD, c %= MOD, d %= MOD;
  }
  void print(){
    printf("%lld %lld\n%lld %lld\n\n",a,b,c,d);
  }
}v[MAX];

Matrix mul(const Matrix &x, const Matrix &y){
  return Matrix(x.a * y.a + x.b * y.c, x.a * y.b + x.b * y.d,
      x.c * y.a + x.d * y.c, x.c * y.b + x.d * y.d);
}

struct ST{
  Matrix v[MAX<<2];
  void build(Matrix *a, int n){
    build(1,1,n,a);
  }
  void build(int u, int l, int r, Matrix *a){
    if(l == r) { v[u] = a[l]; return; }
    int m = (l+r)/2;
    build(u<<1, l, m, a);
    build(u<<1|1, m+1, r, a);
    v[u] = mul(v[u<<1], v[u<<1|1]);
  }
  Matrix prod(int l, int r){
    return prod(1,1,n,l,r);
  }
  Matrix prod(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr) return v[u];
    int m = (cl+cr)/2; Matrix s;
    if(ql <= m) s = mul(s, prod(u<<1, cl, m, ql, qr));
    if(m+1 <= qr) s = mul(s, prod(u<<1|1, m+1, cr, ql, qr));
    return s;
  }
}sg;

int main(void){
  scanf("%lld%d%d",&MOD,&n,&m);
  FORR(i,1,n) v[i].read();
  sg.build(v,n);
  while(m--){
    int l,r; scanf("%d%d",&l,&r);
    sg.prod(l,r).print();
  }

  return 0;
}
