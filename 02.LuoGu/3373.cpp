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

const int MAX = 1e5 + 20;
int n,m; LL p;
LL a[MAX], v[MAX<<2];
LL av[MAX<<2], mv[MAX<<2];

void pushDown(int u, int l, int r){
  if(mv[u]!=1){
    v[u<<1] = v[u<<1]*mv[u]%p;
    mv[u<<1] = mv[u<<1]*mv[u]%p;
    av[u<<1] = av[u<<1]*mv[u]%p;  // <b> </b>

    v[u<<1|1] = v[u<<1|1]*mv[u]%p;
    mv[u<<1|1] = mv[u<<1|1]*mv[u]%p;
    av[u<<1|1] = av[u<<1|1]*mv[u]%p;  // <b> </b>

    mv[u] = 1;
  }

  if(av[u]){
    int m = (l+r)>>1;
    v[u<<1] = (v[u<<1] + av[u]*(m-l+1))%p;
    av[u<<1] = (av[u<<1] + av[u])%p;

    v[u<<1|1] = (v[u<<1|1] + av[u]*(r-m))%p;
    av[u<<1|1] = (av[u<<1|1] + av[u])%p;

    av[u] = 0;
  }
}

void pushUp(int u){
  v[u] = (v[u<<1]+v[u<<1|1])%p;
}

void build(int u, int l, int r){
  mv[u] = 1; av[u] = 0;
  if(l==r){
    v[u] = a[l]; return;
  }
  int m=(l+r)>>1;
  build(u<<1,l,m);
  build(u<<1|1,m+1,r);
  pushUp(u);
}

void add(int u, int cl, int cr, int ql, int qr, LL addVal){
  if(ql<=cl && cr<=qr){
    v[u] = (v[u] + (cr-cl+1)*addVal)%p;
    av[u] = (av[u] + addVal)%p;
    return;
  }
  pushDown(u,cl,cr);
  int m = (cl+cr)>>1;
  if(ql<=m) add(u<<1, cl, m,ql,qr,addVal);
  if(qr>=m+1) add(u<<1|1,m+1,cr,ql,qr,addVal);
  pushUp(u);
}

void mul(int u, int cl, int cr, int ql, int qr, LL mulVal){
  if(ql<=cl && cr<=qr){
    v[u] = v[u]*mulVal%p;
    mv[u] = mv[u]*mulVal%p;
    av[u] = av[u]*mulVal%p; // <b> </b>
    return;
  }
  pushDown(u,cl,cr);
  int m = (cl+cr)>>1;
  if(ql<=m) mul(u<<1, cl, m,ql,qr,mulVal);
  if(qr>=m+1) mul(u<<1|1,m+1,cr,ql,qr,mulVal);
  pushUp(u);
}

int sum(int u, int cl, int cr, int ql, int qr){
  if(ql<=cl && cr<=qr){
    return v[u];
  }
  pushDown(u,cl,cr);
  int m = (cl+cr)>>1, s = 0;
  if(ql<=m) s += sum(u<<1,cl,m,ql,qr);
  if(qr>=m+1) s += sum(u<<1|1,m+1,cr,ql,qr);
  return s%p;
}

int main(void){
  scanf("%d%d%lld",&n,&m,&p);
  FORR(i,1,n) scanf("%lld",&a[i]);
  build(1,1,n);

  int op,x,y; LL k;
  while(m--){
    scanf("%d%d%d",&op,&x,&y);
    if(op==3) printf("%d\n",sum(1,1,n,x,y));
    else{
      scanf("%lld",&k); k%=p;
      if(op==1) mul(1,1,n,x,y,k);
      else add(1,1,n,x,y,k);
    }
  }

  return 0;
}
