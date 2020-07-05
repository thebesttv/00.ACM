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

const int MAX = 100020;
int n; LL MOD;

struct ST{
  LL v[MAX<<2];
  void init(){
    FOR(i,1,MAX<<2) v[i]=1;
  }
  void set(int u, int l, int r, int p, LL x){
    if(l==r){
      v[u] = x; return;
    }
    int m = (l+r)>>1;
    if(p<=m) set(u<<1,l,m,p,x);
    else set(u<<1|1,m+1,r,p,x);
    v[u] = v[u<<1] * v[u<<1|1] % MOD;
  }

  LL mul() { return v[1]; }
}sg;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    sg.init();
    scanf("%d%lld",&n,&MOD);
    int op; LL x;
    FORR(i,1,n){
      scanf("%d%lld",&op,&x);
      if(op==1){
        sg.set(1,1,n,i,x%MOD);
      }else{
        sg.set(1,1,n,x,1);
      }
      printf("%lld\n",sg.mul());
    }
  }

  return 0;
}
