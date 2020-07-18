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

const int MAX = 2e5 + 20;
int n; deque<int> a;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); a.resize(n);
    FOR(i,0,n) scanf("%d",&a[i]);
    int last = 0;
    while(!a.empty() && a.back() >= last)
      last = a.back(), a.pop_back();
    while(!a.empty() && a.back() <= last)
      last = a.back(), a.pop_back();
    printf("%d\n", (int)a.size());
  }

  return 0;
}
