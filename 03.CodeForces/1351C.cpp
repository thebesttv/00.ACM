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
int to[128][2];
int n; char s[MAX];

int main(void){
  to['N'][0] = -1; to['N'][1] =  0;
  to['S'][0] =  1; to['S'][1] =  0;
  to['W'][0] =  0; to['W'][1] = -1;
  to['E'][0] =  0; to['E'][1] =  1;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s); n = strlen(s);
    set<pair<pii,pii>> st;
    int x = 0, y = 0, ans = 0;
    FOR(i,0,n){
      int tx = x + to[s[i]][0],
          ty = y + to[s[i]][1];
      if(st.count({{x,y},{tx,ty}}))
        ans += 1;
      else{
        ans += 5;
        st.insert({{x,y},{tx,ty}});
        st.insert({{tx,ty},{x,y}});
      }
      x = tx, y = ty;
    }
    printf("%d\n",ans);
  }

  return 0;
}
