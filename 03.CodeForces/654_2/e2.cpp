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
int n,p,a[MAX];

bool ok1(int x){
  int j = 0;
  FORR(i,1,n){
    while(j<n && a[j+1] <= x+i-1) ++j;
    int s = j + 1 - i;
    if(s <= 0) return false;
  }
  return true;
}

bool ok2(int x){
  int j = 0;
  FORR(i,1,n){
    while(j<n && a[j+1] <= x+i-1) ++j;
    int s = j + 1 - i;
    if(s <= 0 || s%p==0)
      return false;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&p);
  FORR(i,1,n) scanf("%d",&a[i]);
  sort(a+1,a+1+n);

  int l = max(a[1], a[n]-n), r = a[n];
  while(l < r){
    int m = (l+r)/2;
    if(ok1(m)) r = m;
    else l = m+1;
  }
#ifdef DEBUG
  printf("  l: %d\n",l);
#endif

  if(!ok2(l)) { printf("0\n\n"); return 0; }

  int al = l; r = a[n];
  while(l < r){
    int m = (l+r+1)/2;
    if(ok2(m)) l = m;
    else r = m-1;
  }
#ifdef DEBUG
  printf("  r: %d\n",r);
#endif
  printf("%d\n",r-al+1);
  FORR(i,al,r) printf("%d ",i); putchar('\n');

  return 0;
}
