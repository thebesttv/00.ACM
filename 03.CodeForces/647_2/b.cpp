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

const int MAX = 1040;
int n, a[MAX], cnt[MAX];

bool ok(int k){
  MST(cnt,0); FOR(i,0,n) cnt[a[i]] = 1;
  FOR(i,0,n)
    if((a[i]^k) >= 1024) return false;
    else cnt[a[i]^k]--;
  FOR(i,0,1024) if(cnt[i]!=0)
    return false;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    bool done = 0;
    FOR(k,1,1024) if(ok(k)){
      printf("%d\n",k);
      done=1; break;
    }
    if(!done) printf("-1\n");
  }

  return 0;
}
