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

const int MAX = 10020;
int n,q,a[MAX];

/*
int *lower_bound(int *l, int *r, int v){
  int cnt=r-l;
  while(cnt){
    int step=cnt/2, *p=l+step;
    if(*p < v) l=p+1, cnt-=step+1;
    else cnt=step;
  }
  return l;
}
*/
int *lower_bound(int *l, int *r, int v){
  while(l!=r){
    int step = (r-l)/2, *m = l+step;
    if(*m<v) l=m+1;
    else r=m;
  }
  return l;
}

int main(void){
  int kase=0;
  while(scanf("%d%d",&n,&q) && n && q){
    printf("CASE# %d:\n",++kase);
    FOR(i,0,n) scanf("%d",&a[i]);
    sort(a, a+n);

    int x;
    while(q--){
      scanf("%d",&x);
      int *p = lower_bound(a,a+n,x);
      if(p!=a+n && *p == x)
        printf("%d found at %ld\n",x,(p-a)+1);
      else printf("%d not found\n",x);
    }
  }

  return 0;
}
