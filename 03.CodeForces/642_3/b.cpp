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

int n,k; deque<int> a,b;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    a.resize(n), b.resize(n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&b[i]);
    sort(ALL(a)), sort(ALL(b),greater<int>());
    while(k-- && !b.empty()){
      if(a.front() < b.front()){
        a.pop_front();
        a.push_back(b.front());
        b.pop_front();
      }else break;
    }
    int ans = 0;
    for(int x : a) ans += x;
    printf("%d\n",ans);
  }

  return 0;
}
