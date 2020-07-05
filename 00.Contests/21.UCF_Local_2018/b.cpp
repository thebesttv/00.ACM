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

int n; char s[40];
map<string,int> mp[26];

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%s",s);
    ++mp[s[0]-'A'][string(s)];
  }
  LL ans = 0;
  FOR(i,0,26){
    VR<int> v;
    LL s = 0;
    for(auto p : mp[i]){
      v.push_back(p.SE);
      s += p.SE;
    }
    for(int x : v)
      ans += x * (s-x);
  }
  printf("%lld\n",ans);

  return 0;
}
