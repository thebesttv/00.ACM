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

const int MAX = 1020;
int n; deque<int> q;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    q.clear(); int x;
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&x), q.push_back(x);
    int a = q.front(), b = 0, turn = 1, last = a;
    q.pop_front();
    while(!q.empty()){
      int t = 0;
      if(turn & 1){  // b
        while(!q.empty() && t <= last)
          t += q.back(), q.pop_back();
        last = t; b += t;
      }else{  // a
        while(!q.empty() && t <= last)
          t += q.front(), q.pop_front();
        last = t; a += t;
      }
      ++turn;
    }
    printf("%d %d %d\n",turn,a,b);
  }

  return 0;
}
