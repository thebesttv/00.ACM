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
int n,k; char s[MAX];
set<int> st;

bool ok(int x){
  auto it = st.lower_bound(max(1,x-k));
  if(it == st.end() || (*it) > x+k)
    return true;
  else
    return false;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    st.clear();
    scanf("%d%d%s",&n,&k,s);
    FOR(i,0,n) if(s[i]=='1')
      st.insert(i+1);
    int ans = 0;
    FORR(i,1,n) if(ok(i))
      ++ans, st.insert(i);
    printf("%d\n",ans);
  }

  return 0;
}
