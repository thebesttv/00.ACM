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

const int MAX=10020;
int n,s,c[MAX],y[MAX];

int main(void){
  scanf("%d%d",&n,&s);
  FOR(i,0,n) scanf("%d%d",&c[i],&y[i]);
  FOR(i,0,n) FOR(j,1,n)
    if(i+j<n) c[i+j]=min(c[i+j],c[i]+s*j);
    else break;
  LL ans=0;
  FOR(i,0,n) ans+=c[i]*y[i];
  printf("%lld\n",ans);

  return 0;
}
