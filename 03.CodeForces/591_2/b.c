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

const int MAX=100020;
int n,r,x[MAX];

bool ok(LL m){
  return m * r >= x[n-m];
}
int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&r);
    FORR(i,1,n) scanf("%d",&x[i]);
    sort(x+1,x+1+n);
    n = (unique(x+1,x+1+n)-x)-1;
#ifdef DEBUG
    FORR(i,1,n) printf("%d ",x[i]); putchar('\n');
#endif
    int l=1,r=n;
    while(l<r){
      int m=(l+r)/2;
      if(ok(m)) r=m;
      else l=m+1;
    }
    printf("%d\n",l);
  }

  return 0;
}

/*
const int MAX=100020;
int n,r,x[MAX];

bool ok(int k){
  int h=lower_bound(x,x+n,k*r+1)-x;
  int t=n-k;
  return h>=t;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&r);
    FOR(i,0,n) scanf("%d",&x[i]);
    sort(x,x+n); n=unique(x,x+n)-x;
    int l=1, r=n+1;
    while(l<r){
      int m=(l+r)>>1;
#ifdef DEBUG
      printf(" (%d,%d) %d\n",l,r,m);
#endif
      if(ok(m)) r=m;
      else l=m+1;
    }

    printf("%d\n",l);
  }

  return 0;
}
*/
