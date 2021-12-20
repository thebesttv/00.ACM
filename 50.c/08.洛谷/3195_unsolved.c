#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int n; LL L;
LL f[MAX],s[MAX];
struct Node{
  int s,k;
}st[MAX];
int top;

inline LL w(int i, int j){
  LL sq = j-i + s[j]-s[i-1] - L;
  return sq*sq;
}
inline int comp(int i, int k1, int k2){ //比较 f[i]<-k1 和 f[i]<-k2 的大小
  LL f1=f[k1]+w(k1+1,i);
  LL f2=f[k2]+w(k2+1,i);
  return f1<f2 ? -1 : (f1==f2 ? 0 : 1) ;
}
int bin(int l, int r, int k1, int k2){  //在 [l,r] 内找最小的 x ，使得 f[x]<-f2 不比 f[x]<-f1 差
  int m;
  while(l<r){
    m=(l+r)>>1;
    if(comp(m,k1,k2)>=0) r=m;
    else l=m+1;
  }
  return l;
}
LL solve(){
  int v=1,l,r,t,x;
  st[++top]=(Node){1,0};
  FORR(i,1,n){
    while(v<top && st[v+1].s<=i) v++;
    t=st[v].k;
    f[i]=f[t]+w(t+1,i);

    while(top && comp(st[top].s,st[top].k,i)>=0) top--;

    l=max(st[top].s,i)+1,r=st[top+1].s ? st[top+1].s+1 : n+1;
    x=bin(l,r,st[top].k,i);
    if(x<=n) st[++top]=(Node){x,i};
  }
  return f[n];
}

int main(void){
  scanf("%d%lld",&n,&L);
  FORR(i,1,n){
    scanf("%lld",&s[i]);
    s[i]+=s[i-1];
  }
  printf("%lld\n",solve());

  return 0;
}
