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
int n,m,a[MAX];
VR<int> Q[MAX], no[MAX];
int ans[MAX];
deque<pii> q;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    q.clear();
    scanf("%d%d",&n,&m);
    FORR(i,1,n) scanf("%d",&a[i]), Q[i].clear(), no[i].clear();
    int x,y;
    FOR(i,0,m){
      scanf("%d%d",&x,&y);
      Q[x].push_back(y);
      no[x].push_back(i);
    }
    ROR(i,n,1){
      while(!q.empty() && q.front().FI <= a[i])
        q.pop_front();
      q.push_front({a[i],i});
      FOR(j,0,Q[i].size()){
        if(Q[i][j] > q.size()){
          ans[no[i][j]] = -1;
        }else{
          ans[no[i][j]] = q[Q[i][j]-1].SE;
        }
      }
    }
    FOR(i,0,m) printf("%d\n",ans[i]);
  }

  return 0;
}
