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

const int MAX = 1e5 + 20;
int n; char a[MAX], b[MAX];
int cnt0, cnt1, inp0, inp1;

int main(void){
  scanf("%d%s%s",&n,a,b);
  FOR(i,0,n){
    if(a[i]=='0'){
      ++cnt0;
      if(b[i]=='0') ++inp0;
    }else{
      ++cnt1;
      if(b[i]=='0') ++inp1;
    }
  }
  LL ans = 0;
  FOR(i,0,n) if(b[i]=='0'){
    if(a[i]=='0') ans += cnt1;
    else ans += cnt0;
  }
  ans -= 1ll*inp0*inp1;
  printf("%lld\n",ans);

  return 0;
}
