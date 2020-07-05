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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

int n,x,cnt;

int main(void){
  while(scanf("%d",&n)==1 && n){
    while(scanf("%d",&x)==1 && x){
      stack<int> st; queue<int> q;
      q.push(x);
      FOR(i,1,n) scanf("%d",&x), q.push(x);

      cnt=1;
      while(cnt<=n){
        if(st.empty() || (st.top()!=q.front()))
          st.push(cnt++);
        while(!st.empty() && st.top()==q.front())
          st.pop(), q.pop();
      }
      printf("%s\n", q.empty() ? "Yes" : "No");
    }
    putchar('\n');
  }

  return 0;
}
