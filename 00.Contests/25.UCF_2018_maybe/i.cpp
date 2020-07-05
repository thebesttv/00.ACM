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

const int MAXN = 200020, MAXM = 1000020;
int n,m,cnt[MAXN],col[MAXN],odd[MAXN],colorCnt[MAXN];
VR<int> G[MAXN];

int color=0;
void dfs(int u){
  col[u] = color;
  for(int v : G[u]) if(!col[v])
    dfs(v);
}

int main(void){
  scanf("%d%d",&n,&m);
  int u,v;
  FOR(i,0,m){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
    ++cnt[u], ++cnt[v];
  }

  FORR(i,1,n){
    if(!col[i]){
      ++color;
      dfs(i);
    }
    if(cnt[i]&1)
      ++odd[col[i]];
    ++colorCnt[col[i]];
  }

  int ans = 0;
  FORR(i,1,color) if(colorCnt[i]>1){
    ans += max(1,odd[i]/2);
  }

  if(ans<=1) printf("YES\n");
  else printf("NO\n%d\n",ans);

  return 0;
}
