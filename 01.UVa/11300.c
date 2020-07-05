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

const int MAX=1000001;
int n; LLU sum;
LL ave,c[MAX];

int main(void){
  while(scanf("%d",&n)==1){
    sum = 0;
    FOR(i,0,n) scanf("%lld",&c[i]), sum+=c[i];
    ave = sum/n; c[0]=0;
    FOR(i,1,n) c[i]=c[i-1]-(c[i]-ave);

    //sort(c,c+n);
    nth_element(c,c+n/2,c+n);
    LL x=c[n/2], ans=0;
    FOR(i,0,n) ans += ((x>c[i]) ? x-c[i] : c[i]-x);
    printf("%lld\n",ans);
  }

  return 0;
}

/*
const int MAX=1000001;
int n; LLU sum;
LL ave,a[MAX],b[MAX],c[MAX];

int main(void){
  while(scanf("%d",&n)==1){
    sum = 0;
    FOR(i,0,n) scanf("%lld",&a[i]), sum+=a[i];
    ave = sum/n;
    FOR(i,0,n) b[i]=a[i]-ave;
    c[0]=0;
    FOR(i,1,n) c[i]=c[i-1]-b[i];

    sort(c,c+n);
    LL x=c[n/2], ans=0;
    FOR(i,0,n) ans += ((x>c[i]) ? x-c[i] : c[i]-x);
    printf("%lld\n",ans);
  }

  return 0;
}
*/
