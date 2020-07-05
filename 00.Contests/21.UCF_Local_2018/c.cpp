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
int n,a[MAX],f[MAX];

int main(void){
  scanf("%d",&n);
  int tMax = 1;
  FORR(i,1,n){
    scanf("%d",&a[i]);
    f[a[i]] = f[a[i]-1] + 1;
    tMax = max(tMax, f[a[i]]);
  }

  printf("%d\n",n-tMax);

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n,a[MAX];

struct ST{
  int v[MAX<<2];
  void set(int u, int cl, int cr, int p, int x){
    if(cl==cr){
      v[u] = x; return;
    }
    int m = (cl+cr)>>1;
    if(p<=m) set(u<<1,cl,m,p,x);
    else set(u<<1|1,m+1,cr,p,x);
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
  int qMax(int u, int cl, int cr, int ql, int qr){
    if(ql<=cl && cr<=qr)
      return v[u];
    int m = (cl+cr)>>1, ansMax=0;
    if(ql<=m) ansMax = qMax(u<<1,cl,m,ql,qr);
    if(qr>=m+1) ansMax = max(ansMax, qMax(u<<1|1,m+1,cr,ql,qr));
    return ansMax;
  }
}st;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  st.set(1,1,n,a[1],1);
  FORR(i,2,n){
    int t = a[i]==1 ? 0 : st.qMax(1,1,n,1,a[i]-1);
    st.set(1,1,n,a[i],t+1);
  }
  int ans = n - st.qMax(1,1,n,1,n);
  printf("%d\n",ans);

  return 0;
}
*/
