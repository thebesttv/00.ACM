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

int n,k;
deque<int> a,b,c;

int main(void){
  scanf("%d%d",&n,&k);
  while(n--){
    int t,ta,tb;
    scanf("%d%d%d",&t,&ta,&tb);
    if(ta && tb) c.push_back(t);
    else if(ta) a.push_back(t);
    else if(tb) b.push_back(t);
  }
  sort(ALL(a)); sort(ALL(b)); sort(ALL(c));

  if(a.size() + c.size() < k || b.size() + c.size() < k)
    printf("-1\n");
  else{
    LL ans = 0;
    while(k--){
      if(c.empty() || (!a.empty() && !b.empty() && a.front() + b.front() < c.front())){
        ans += a.front() + b.front();
        a.pop_front(); b.pop_front();
      }else{
        ans += c.front();
        c.pop_front();
      }
    }
    printf("%lld\n",ans);
  }

  return 0;
}
