#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;

const int maxn = 100010;
const int K = 10; //最大次幂
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T>
inline void read(T &x){
  x=0; T f=1; char ch;
  do {ch=getchar(); if(ch=='-') f=-1;} while(ch<'0' || ch>'9');
  do {x=x*10+ch-'0'; ch=getchar()} while(ch<='9' && ch>='0');
  x*=f;
}

template<typename A,typename B> inline void read(A & x, B & y) {read(x); read(y);}
template<typename A,typename B,typename C> inline void read(A & x, B & y, C & z) {read(x); read(y); read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A & x, B & y, C & z, D & w) {read(x); read(y); read(z); read(w);}

//快速幂
template<typename A,typename B>
inline A fexp(A x,B p){
  A ans=1;
  for(;p;p>>=1,x=1LL*x*x%mod) if(p&1)
    ans=1LL*ans*x%mod;
  return ans;
}
template<typename A,typename B>
inline A fexp(A x,B p,A mo){
  A ans=1;
  for(;p;p>>=1,x=1LL*x*x%mo) if(p&1)
    ans=1LL*ans*x%mo;
  return ans;
}

int n,m;
int A[maxn];
int Cnk[K+1][K+1];  //组合数C(n,k)

struct Node{
  int sm[K+1];  //sm[k]:k次幂和
  int st,ad;
  int l,r;
}T[maxn<<2];  //线段树开四倍

void build(int i,int l,int r);
void add(int i,int l,int r,int v);
void upd(int i,int l,int r,int v);
int query(int i,int l,int r,int v);
inline void pushup(int i);
inline void pushdown(int i);
inline void aadd(int i,int v);
inline void seet(int i,int v);

int main(){
  read(n,m);
  for(int i=1;i<=n;i++) read(A[i]);
  build(1,1,n);
  Cnk[0][0]=1;  //初始化组合数，为二项式定理服务
  for(int i=1;i<=K;i++){
    Cnk[i][0]=1;
    for(int j=1;j<=i;j++) Cnk[i][j] = (Cnk[i-1][j-1] + Cnk[i-1][j])%mod;
  }

  while(m--){
    int opt,l,r,x;
    read(opt,l,r,x);
    if(opt==1) add(1,l,r,x);
    if(opt==2) upd(1,l,r,x);
    if(opt==3) printf("%d\n",query(1,l,r,x));
  }

  return 0;
}

void build(int i,int l,int r){
  T[i].l=l; T[i].r=r; T[i].st=-1; T[i].ad=0;
  if(l==r){
    T[i].sm[0]=1;
    for(int j=1;j<=K;j++) T[i].sm[j] = 1LL*T[i].sm[j-1]*A[l]%mod; //计算k次方
    return;
  }
  int M=l+r>>1;
  build(i<<1,l,M);
  build(i<<1|1,M+1,r);  //i<<1|1 <==> (i<<1)|1 <- i*2+1
  pushup(i);  //更新当前节点sm
}
void add(int i,int l,int r,int v){
  if(l<=T[i].l && T[i].r<=r){
    aadd(i,v);
    return;
  }
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(l<=M) add(i<<1,l,r,v);
  if(r>M) add(i<<1|1,l,r,v);
  pushup(i);
}
void upd(int i,int l,int r,int v){
  if(l<=T[i].l && T[i].r<=r){
    seet(i,v);
    return;
  }
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(l<=M) upd(i<<1,l,r,v);
  if(r>M) upd(i<<1|1,l,r,v);
  pushup(i);
}
int query(int i,int l,int r,int v){ //询问[l,r]的v次幂和
  if(l<=T[i].l && T[i].r<=r) return T[i].sm[v];
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(r<=M) return query(i<<1,l,r,v);
  else if(l>M) return query(i<<1|1,l,r,v);
  else return (query(i<<1,l,r,v)+query(i<<1|1,l,r,v))%mod;
}
inline void pushup(int i){
  for(int j=0;j<=K;j++)
    T[i].sm[j] = ( T[i<<1].sm[j] + T[i<<1|1].sm[j] )%mod;
}
inline void pushdown(int i){
  if(T[i].st!=-1){
    seet(i<<1,T[i].st);
    seet(i<<1|1,T[i].st);
    T[i].st=-1; //<b></b>
  }
  if(T[i].ad){
    aadd(i<<1,T[i].ad);
    aadd(i<<1|1,T[i].ad);
    T[i].ad=0;
  }
}
inline void aadd(int i,int v){  //计算i号节点表示的区间都加上v后的0:10次幂和
  for(int j=K;j>=0;j--){  //<b>倒序递推</b>，保证对每个j，sm[j:0]都是加v之前的
    int t=0,now=1;
    for(int x=j;x>=0;x--){  //二项式定理，倒序：方便计算v^(j-x)
      t = (1LL * T[i].sm[x] * Cnk[j][x] % mod * now + t)%mod;
      now = 1LL * now * v % mod;
      //本质：t+=T[i].sum[x]*Cnk[j][x]*now
      //      now*=v
    }
    T[i].sm[j]=t;
  }
  T[i].ad=(T[i].ad+v)%mod;
}
inline void seet(int i,int v){
  int now=1;
  for(int j = (0);j<=(K);j++){
    T[i].sm[j] = 1LL * now * (T[i].r-T[i].l+1) % mod;
    now = 1LL * now * v % mod;
  }
  T[i].ad=0;  //<b></b>
  T[i].st=v;  //<b></b>
}

/*
#include"bits/stdc++.h"
using namespace std;

#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(int x = (l);x<=(u);x++)
#define RREP(x,l,u) for(int x = (l);x>=(u);x--)
#define mst(x,a) memset(x,a,sizeof(x))
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define se second
#define fi first
#define dbg(x) cout<<#x<<" = "<<(x)<<endl;
#define sz(x) ((int)x.size())

typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;

const int maxn = 100010;
const int K = 10;
const int mod = 1e9+7;
const double eps = 1e-6;
const double PI = acos(-1);

template<typename T> inline void read(T &x){
  x=0;T f=1;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do x=x*10+ch-'0',ch=getchar();while(ch<='9'&&ch>='0');x*=f;
}

template<typename A,typename B> inline void read(A&x,B&y){read(x);read(y);}
template<typename A,typename B,typename C> inline void read(A&x,B&y,C&z){read(x);read(y);read(z);}
template<typename A,typename B,typename C,typename D> inline void read(A&x,B&y,C&z,D&w){read(x);read(y);read(z);read(w);}
template<typename A,typename B> inline A fexp(A x,B p){A ans=1;for(;p;p>>=1,x=1LL*x*x%mod)if(p&1)ans=1LL*ans*x%mod;return ans;}
template<typename A,typename B> inline A fexp(A x,B p,A mo){A ans=1;for(;p;p>>=1,x=1LL*x*x%mo)if(p&1)ans=1LL*ans*x%mo;return ans;}

int n,m;

int A[maxn];

int Cnk[K+1][K+1];

struct Node{
  int l,r;
  int sm[K+1];
  int st,ad;
}T[maxn<<2];

inline void pushup(int i){
  REP(j,0,K)T[i].sm[j]=(T[i<<1].sm[j]+T[i<<1|1].sm[j])%mod;
}
inline void aadd(int i,int v){
  RREP(j,K,0){
    int t=0,now=1;
    RREP(x,j,0){
      t=(1LL*T[i].sm[x]*Cnk[j][x]%mod*now+t)%mod;
      now=1LL*now*v%mod;
    }
    T[i].sm[j]=t;
  }
  T[i].ad=(T[i].ad+v)%mod;
}
inline void seet(int i,int v){
  int now=1;
  REP(j,0,K){
    T[i].sm[j]=1LL*now*(T[i].r-T[i].l+1)%mod;
    now=1LL*now*v%mod;
  }
  T[i].ad=0;T[i].st=v;
}
inline void pushdown(int i){
  if(T[i].st!=-1){
    seet(i<<1,T[i].st);
    seet(i<<1|1,T[i].st);
    T[i].st=-1;
  }
  if(T[i].ad){
    aadd(i<<1,T[i].ad);
    aadd(i<<1|1,T[i].ad);
    T[i].ad=0;
  }
}
void build(int i,int l,int r){
  T[i].l=l; T[i].r=r; T[i].st=-1; T[i].ad=0;
  if(l==r){
    T[i].sm[0]=1;
    REP(j,1,K) T[i].sm[j]=1LL*T[i].sm[j-1]*A[l]%mod;
    return;
  }
  int M=l+r>>1;
  build(i<<1,l,M);build(i<<1|1,M+1,r);
  pushup(i);
}
void add(int i,int l,int r,int v){
  if(l<=T[i].l&&T[i].r<=r){
    aadd(i,v);
    return;
  }
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(l<=M)add(i<<1,l,r,v);if(r>M)add(i<<1|1,l,r,v);
  pushup(i);
}
void upd(int i,int l,int r,int v){
  if(l<=T[i].l&&T[i].r<=r){
    seet(i,v);
    return;
  }
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(l<=M)upd(i<<1,l,r,v);if(r>M)upd(i<<1|1,l,r,v);
  pushup(i);
}
int query(int i,int l,int r,int v){
  if(l<=T[i].l&&T[i].r<=r)return T[i].sm[v];
  pushdown(i);
  int M=T[i].l+T[i].r>>1;
  if(r<=M)return query(i<<1,l,r,v);
  else if(l>M)return query(i<<1|1,l,r,v);
  else return (query(i<<1,l,r,v)+query(i<<1|1,l,r,v))%mod;
}
void Work(){
  while(m--){
    int opt,l,r,x;
    read(opt,l,r,x);
    if(opt==1)
      add(1,l,r,x);
    if(opt==2)
      upd(1,l,r,x);
    if(opt==3)
      iout(query(1,l,r,x));
  }
}
void Init(){
  read(n,m);
  REP(i,1,n) read(A[i]);
  build(1,1,n);
  Cnk[0][0]=1;
  REP(i,1,K){
    Cnk[i][0]=1;
    REP(j,1,i)Cnk[i][j]=(Cnk[i-1][j-1]+Cnk[i-1][j])%mod;
  }
}

int main(){
  //fr("c.in");
  //fw("c.out");
  Init();
  Work();
  //cerr<<(double)clock()/CLOCKS_PER_SEC<<endl;
  return 0;
}
*/
