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

const int MAXM = 10020, MAXN = 520;
const int INF=0x3f3f3f3f;
int n,m; pair<int,int> c[MAXN];
int f[MAXM];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int l, r; scanf("%d%d%d",&l,&r,&n);
    m = r - l;
    FOR(i,0,n) scanf("%d%d",&c[i].second, &c[i].first);
    sort(c,c+n);

    MST(f,0x3f); f[0] = 0;
    FORR(i,1,m){
      int &a = f[i];
      for(int j=0;j<n && c[j].first<=i;++j){
        a = min(a, f[i-c[j].first] + c[j].second);
      }
    }

    if(f[m]==INF){
      printf("This is impossible.\n");
    }else{
      printf("The minimum amount of money in the piggy-bank is %d.\n", f[m]);
    }
  }
  return 0;
}
