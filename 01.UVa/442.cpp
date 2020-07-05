// Tag: 栈 表达式求值
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
int n; char s[MAX];
pii v[128];

int main(void){
  scanf("%d",&n);
  while(n--){
    int ch; do ch = getchar(); while(!isalpha(ch));
    scanf("%d%d",&v[ch].FI,&v[ch].SE);
#ifdef DEBUG
    printf("%c: %d %d\n",ch,v[ch].FI,v[ch].SE);
#endif
  }

  while(FGETS(s)){
    n = strlen(s); s[--n] = 0;
    if(!n) continue;
    stack<pii> st; LL ans = 0;
    bool bad = 0;
    FOR(i,0,n){
      if(isalpha(s[i])){
        st.push(v[s[i]]);
      }else if(s[i] == ')'){
        pii y = st.top(); st.pop();
        pii x = st.top(); st.pop();
        if(x.SE != y.FI) { bad = 1; break; }
        ans += 1ll * x.FI * x.SE * y.SE;
        st.push({x.FI, y.SE});
      }
    }
    if(bad) printf("error\n");
    else printf("%lld\n",ans);
  }

  return 0;
}
