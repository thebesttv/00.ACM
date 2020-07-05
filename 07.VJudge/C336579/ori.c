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
const int INF=0x3f3f3f3f;
int n,k,a[MAX],s[MAX];

int main(void){
  while(scanf("%d%d",&n,&k)==2 && n){
    FORR(i,1,n){
      scanf("%d",&a[i]);
      s[i]=a[i]+s[i-1];
    }
    FOR(i,0,k){
      int q; scanf("%d",&q);
      int delta=INF,l,r,ans;
      FORR(i,1,n) FORR(j,i,n){
        int t = abs(abs(s[j]-s[i-1]) - q);
        if(delta>t){
          delta=t; l=i, r=j;
          ans = abs(s[j]-s[i-1]);
        }
      }
      //printf("%d %d %d\n",ans,l,r);
      printf("%d\n",delta);
    }
  }
  return 0;
}
