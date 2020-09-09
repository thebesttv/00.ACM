// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n,cnt[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(cnt,0);
    scanf("%d",&n); int x;
    while(n--) scanf("%d",&x), ++cnt[x];
    int ans = 0;
    FORR(i,2,100){
      int sum = 0;
      FOR(j,1,i) sum += min(cnt[j], cnt[i-j]);
      ans = max(ans, sum/2);
    }
    printf("%d\n",ans);
  }

  return 0;
}