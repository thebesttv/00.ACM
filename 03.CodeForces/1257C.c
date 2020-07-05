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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2e5+20;
int n, a[MAX], pos[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(pos,0);
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]);
    int ansMin = n + 1;
    FORR(i,1,n){
      int &p = pos[a[i]];
      if(p) ansMin = min(ansMin, i-p+1);
      p = i;
    }
    printf("%d\n",ansMin==n+1 ? -1 : ansMin);
  }

  return 0;
}
