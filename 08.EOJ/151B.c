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

int n;
deque<LL> q;

int main(void){
  LL x; int ans=0;
  scanf("%d",&n);
  while(n--){
    scanf("%lld",&x); q.push_back(x);
  }
  while(q.size()>1){
    if(q.front()==q.back()){
      q.pop_front(); q.pop_back();
      continue;
    }
    if(q.front() < q.back()){
      x = q.front(); q.pop_front();
      x += q.front(); q.pop_front();
      q.push_front(x);
    }else{
      x = q.back(); q.pop_back();
      x += q.back(); q.pop_back();
      q.push_back(x);
    }
    ans++;
  }
  printf("%d\n",ans);

  return 0;
}
