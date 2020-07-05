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

const int MAX = 3e5 + 20;
int n,k,h[MAX],r[MAX];
VR<int> ans;

bool ok(){
  r[n] = h[n];
  ROR(i,n-1,1) r[i] = max(h[i],r[i+1]);
  set<int> st;
  st.insert(h[1]);
  FOR(i,2,n) if(h[i] < r[i+1]){
    auto it = st.upper_bound(h[i]);
    if(it!=st.end() && *it < r[i+1]){
#ifdef DEBUG
      printf("  get %d\n",*it);
#endif
      return true;
    }
    st.insert(h[i]);
  }
  return false;
}

int main(void){
  scanf("%d",&k);
  FORR(j,1,k){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&h[i]);
    if(ok()) ans.push_back(j);
  }
  printf("%d\n",(int)ans.size());
  for(int x : ans) printf("%d\n",x);

  return 0;
}
