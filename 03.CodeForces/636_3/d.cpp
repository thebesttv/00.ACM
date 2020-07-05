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

const int MAX = 4e5 + 20;
int n,k,a[MAX],cnt[MAX],s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    FORR(i,0,2*k) cnt[i]=s[i]=0;
    FORR(i,1,n) scanf("%d",&a[i]);
    FORR(i,1,n/2){
      int x = a[i], y = a[n-i+1];
      int l = min(x,y)+1, r = max(x,y)+k;
      s[l]++; s[r+1]--;
      cnt[x+y]++;
#ifdef DEBUG
      printf("[%d, %d] %d\n",l,r,x+y);
#endif
    }

    int ansMin = n, d = 0;
    FORR(i,2,2*k){
      d += s[i];
      ansMin = min(ansMin, d - cnt[i] + 2 * (n/2-d));
    }
    printf("%d\n",ansMin);
  }

  return 0;
}
