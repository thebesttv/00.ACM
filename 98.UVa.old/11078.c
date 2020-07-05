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

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int n,a,tMax,ansMax=-0x3f3f3f3f;
    scanf("%d",&n);
    scanf("%d",&tMax);  // a[0]
    FOR(i,1,n){
      scanf("%d",&a);
      ansMax=max(ansMax,tMax-a);
      tMax=max(tMax,a);
    }
    printf("%d\n",ansMax);
  }
  return 0;
}

/*
const int MAX=100020;
int n,a[MAX],b[MAX];  // b[i]=min{a[i:n-1]}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]);
    b[n]=a[n];
    ROR(i,n-1,1)
      b[i]=min(b[i+1],a[i]);
    int ans=-0x3f3f3f3f;
    FOR(i,1,n)
      ans=max(ans,a[i]-b[i+1]);
    printf("%d\n",ans);
  }
  return 0;
}
*/
