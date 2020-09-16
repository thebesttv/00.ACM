// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<pair<int,int>,pair<int,int>> pii;

int G[10][10],vis[10][10],mp[10][10];

void init(){
  int tail = 0;
  FORR(i,0,6) FORR(j,0,6) if(!mp[i][j])
    mp[i][j] = mp[j][i] = ++tail;
}

struct Node{
  int v; VR<pii> p;
  bool operator < (const Node &b) const {
    return p.size() < b.p.size();
  }
  void clear(int v){
    this->v = v; p.clear();
  }
}node[30];

void print(int a[][10]){
  putchar('\n');
  FORR(i,1,7){
    FORR(j,1,8) printf("%4d",a[i][j]);
    putchar('\n');
  }
}

int ans = 0, kase;
void dfs(int cur){
  if(cur == 29){
    ++ans; putchar('\n');
    print(vis); return;
  }
  Node &u = node[cur];
  for(auto p : u.p) if(!vis[p.FI.FI][p.FI.SE] && !vis[p.SE.FI][p.SE.SE]){
    vis[p.FI.FI][p.FI.SE] = vis[p.SE.FI][p.SE.SE] = u.v;
    dfs(cur + 1);
    vis[p.FI.FI][p.FI.SE] = vis[p.SE.FI][p.SE.SE] = 0;
  }
}

int main(void){
  init();
  while(scanf("%d",&G[1][1]) == 1){
    ++kase; ans = 0; FORR(i,1,28) node[i].clear(i);

    FORR(i,1,7) FORR(j,i==1 ? 2 : 1,8)
      scanf("%d",&G[i][j]);
    FORR(i,1,7) FORR(j,1,8){
      if(j < 8) node[mp[G[i][j]][G[i][j+1]]].p.pb({{i,j},{i,j+1}});
      if(i < 7) node[mp[G[i][j]][G[i+1][j]]].p.pb({{i,j},{i+1,j}});
    }
    sort(node+1,node+1+28);

    if(kase > 1) printf("\n\n\n");
    printf("Layout #%d:\n\n",kase);
    print(G);
    printf("\nMaps resulting from layout #%d are:\n",kase);

    dfs(1);

    printf("\n\nThere are %d solution(s) for layout #%d.\n",ans,kase);
  }

  return 0;
}
