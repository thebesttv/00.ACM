// Tag: 栈
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

int n;

int main(void){
  while(scanf("%d",&n)==1 && n){
    bool end = 0;
    while(true){
      int cur = 1, x; bool ok = 1;
      stack<int> st;
      FORR(i,1,n){
        scanf("%d",&x);
        if(!x) { end = 1; break; }
        while(cur <= x) st.push(cur++);
        if(st.empty() || st.top() != x) ok = 0;
        else st.pop();
      }
      if(end) break;
      printf("%s\n", ok ? "Yes": "No");
    }
    putchar('\n');
  }

  return 0;
}
