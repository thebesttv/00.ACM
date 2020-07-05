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

bool ok(const string &s) {
  int c = 0;
  for(char ch : s)
    if(ch == '('){
      ++c;
    } else {
      --c;
      if(c<0) return false;
    }
  return c==0;
}

int main(void) {
  string s;
  int n; scanf("%d",&n);
  while(n--) s += "()";
  sort(ALL(s));
  int ans = 0;
  do if (ok(s)) ++ans; while(next_permutation(ALL(s)));
  cout << ans << endl;
  return 0;
}
