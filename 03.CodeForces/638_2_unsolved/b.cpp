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

int n,k; bool vis[120];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis,0);
    scanf("%d%d",&n,&k);
    int x; FOR(i,0,n) scanf("%d",&x), vis[x] = 1;

    VR<int> v;
    FORR(i,1,n) if(vis[i])
      v.push_back(i);
    if(v.size() > k){
      printf("-1\n"); continue;
    }

    v.resize(k, v.back());
    printf("%d\n",n*k);
    FOR(i,0,n) for(int x : v) printf("%d ",x);
    putchar('\n');
  }

  return 0;
}
