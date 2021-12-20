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
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

int n,m,k;

int main(void){
  scanf("%d%d%d",&m,&n,&k);
  while(k--){
    stack<int> st;
    int cur=0, x;
    bool ok=1;
    FOR(i,0,n){
      scanf("%d",&x);
      if(!ok) continue;
      if(!st.empty() && st.top()==x){
        st.pop();
      }else{
        while(st.size()<m){
          st.push(++cur);
          if(st.top()==x) break;
        }
        if(!st.empty() && st.top()==x) st.pop();
        else ok=0;
      }
    }
    printf("%s\n", ok ? "YES" : "NO");
  }

  return 0;
}
