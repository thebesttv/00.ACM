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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 10020;
int n;

struct Node{
  int f, q, s;
}node[MAX];
bool vis[MAX];

int find(int x){
  int qMin = 0x3f3f3f3f, r = -1;
  FOR(i,0,n) if(!vis[i] && node[i].s >= x){
    int t = max(x - node[i].f, 0);
    if(t < qMin){
      qMin = t, r = i;
    }
  }
  return r;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(vis, 0);

    scanf("%d",&n);
    int tMax = 0;
    FOR(i,0,n){
      scanf("%d%d",&node[i].f, &node[i].q);
      node[i].s = node[i].f+node[i].q;
      tMax = max(node[i].s, tMax);
    }

    int ans = 0;
    ROR(i,tMax, 1){
      int idx = find(i);
#ifdef DEBUG
      printf("  >=%d: %d\n",i,idx);
#endif
      if(idx==-1) continue;
      vis[idx] = 1;
      int t = max(i - node[idx].f, 0);
      ans += t;
    }
    printf("%d\n",ans);
  }

  return 0;
}
