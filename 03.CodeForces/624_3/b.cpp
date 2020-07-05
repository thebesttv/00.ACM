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

const int MAX = 120;
int n,m,a[MAX],p[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FORR(i,1,n) scanf("%d",&a[i]);
    FORR(i,1,m) scanf("%d",&p[i]);
    sort(p+1,p+1+m);
    m = unique(p+1,p+1+m) - p-1;
    int i=1,j;
    while(i<=m){
      j = i;
      while(j+1<=m && p[j]+1==p[j+1]) ++j;
#ifdef DEBUG
      printf("  i: %d, j: %d",i,j);
      FORR(k,i,j) printf(" %d",p[k]);
      putchar('\n');
#endif
      int l=p[i],r=p[j]+1;
      sort(a+l,a+r+1);
      i = j+1;
    }
    bool ok = 1;
    FOR(i,1,n) if(a[i]>a[i+1]){
      ok = 0; break;
    }
    printf("%s\n", ok ? "YES" : "NO");
  }

  return 0;
}
