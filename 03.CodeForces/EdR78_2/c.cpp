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

const int MAX = 1e5 * 2 + 20;
int n, v1[MAX], v2[MAX], d1[MAX], d2[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);

    int cnt1 = 0, cnt2 = 0;
    ROR(i,n,1){
      scanf("%d",&v1[i]);
      if(v1[i]==1) ++cnt1;
      else ++cnt2;
    }
    FORR(i,1,n){
      scanf("%d",&v2[i]);
      if(v2[i]==1) ++cnt1;
      else ++cnt2;
    }

    map<int, int> mp;
    mp[0] = 0;
    FORR(i,1,n){
      d1[i] = d1[i-1] + (v1[i]==1 ? -1 : 1);
      d2[i] = d2[i-1] + (v2[i]==1 ? -1 : 1);
      if(!mp.count(d2[i]))
        mp[d2[i]] = i;
    }
#ifdef DEBUG
    printf(" d: %d\n",cnt1-cnt2);
    printf("d1: "); FORR(i,1,n) printf(" %d",d1[i]); putchar('\n');
    printf("d2: "); FORR(i,1,n) printf(" %d",d2[i]); putchar('\n');
#endif

    int d = cnt1 - cnt2;
    int ansMin = n*2;
    FORR(i,0,n){
      int x = - d - d1[i];
      if(mp.count(x))
        ansMin = min(ansMin, i + mp[x]);
    }
    printf("%d\n",ansMin);
  }

  return 0;
}
