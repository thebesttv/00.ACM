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

const int MAX = 2e5 + 20;
int n,m; VR<int> G[MAX];

map<int, int> mp;
int fromID[MAX], IDcnt = 0;
int ID(int x){
  if(mp.count(x)) return mp[x];
  fromID[++IDcnt] = x;
  return mp[x] = IDcnt;
}

int fa[MAX];
int p(int x){
  return fa[x] < 0 ? x : fa[x] = p(fa[x]);
}

void merge(int x, int y){
  x = p(x), y = p(y);
  if(x == y) return;
  if(fa[x] < fa[y]){
    fa[x] += fa[y];
    fa[y] = x;
  }else{
    fa[y] += fa[x];
    fa[x] = y;
  }
}

int main(void){
  scanf("%d",&n); MST(fa,-1);
  FORR(i,1,n){
    scanf("%d",&m);
    int x; VR<int> v;
    while(m--){
      scanf("%d",&x); x = ID(x);
      v.push_back(x);
      G[x].push_back(i);
    }
    FOR(j,1,v.size()){
      merge(v[0],v[j]);
    }
  }

  FORR(i,2,IDcnt) if(p(1) != p(i)){
#ifdef DEBUG
    printf("  p(%d): %d != p(%d): %d\n",1,p(1),i,p(i));
#endif
    printf("impossible\n");
    return 0;
  }

  MST(fa,-1);
  FORR(i,1,IDcnt) if(G[i].size()>=2){
    int u = G[i][0];
    for(int v : G[i]) if(p(u) != p(v)){
      merge(u,v);
      printf("%d %d %d\n",u,v,fromID[i]);
    }
  }

  return 0;
}
