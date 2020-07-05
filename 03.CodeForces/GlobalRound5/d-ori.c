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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=100020;
int n,a[MAX],aMax=0,aMin=0x3f3f3f3f;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    aMax=max(aMax,a[i]);
    aMin=min(aMin,a[i]);
  }
  if(aMax/2.0 <= aMin){
    printf("-1");
    FORR(i,2,n) printf(" -1");
    printf("\n"); return 0;
  }

  bool first=1;
  FORR(i,1,n){
    int tMax=0,cnt=0,j=i;
    while(tMax <= a[j]*2){
      cnt++; tMax=max(tMax,a[j]);
      j = j==n ? 1 : j+1;
    }
    if(first) first=0;
    else putchar(' ');
    printf("%d",cnt);
  }
  putchar('\n');

  return 0;
}
