// Tag: DFS序 树 iii why
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
int n,bfs[MAX],dfs[MAX],pos[MAX],d[MAX],dep[MAX];
VR<int> G[MAX];

int main(void){
  while(scanf("%d",&n)==1){
    FORR(i,1,n) G[i].clear();
    FOR(i,0,n) scanf("%d",&bfs[i]);
    FOR(i,0,n) scanf("%d",&dfs[i]), pos[dfs[i]]=i;
    d[0] = 1, d[1] = 2;
    FOR(i,2,n){
      if(pos[bfs[i]] > pos[bfs[i-1]])
        d[i] = d[i-1];
      else
        d[i] = d[i-1] + 1;
    }
#ifdef DEBUG
    FOR(i,0,n) printf("%3d ",bfs[i]); putchar('\n');
    FOR(i,0,n) printf("%3d ",d[i]); putchar('\n');
#endif
    FOR(i,0,n) dep[bfs[i]] = d[i];

    stack<int> st;
    st.push(bfs[0]);
    FOR(i,1,n){
      while(dep[dfs[i]] != dep[st.top()]+1)
        st.pop();
      G[st.top()].push_back(dfs[i]);
      st.push(dfs[i]);
    }

    FORR(i,1,n){
      printf("%d:",i);
      sort(ALL(G[i]));
      for(int x : G[i]) printf(" %d",x);
      putchar('\n');
    }
  }

  return 0;
}
