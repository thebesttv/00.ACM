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

const int MAX=1020;
int n,s,k, maxDep;
VR<int> edge[MAX];
VR<int> dep[MAX];
struct Node{
  int fa,dep,dis;
  bool done,hasSon;
}node[MAX];
bool flag[MAX];

void bfs(int root){
  MST(flag,0); queue<int> q;
  q.push(root); flag[root]=1;
  node[root].fa=node[root].dep=0;
  node[root].done=node[root].hasSon=0;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(int v : edge[u]) if(!flag[v]){
      node[v].fa=u; node[u].hasSon=1;
      node[v].dep=node[u].dep+1;
      node[v].done=node[v].hasSon=0;
      flag[v]=1; q.push(v);

      maxDep=max(maxDep,node[v].dep);
      dep[node[v].dep].push_back(v);
    }
  }
}
void bfs2(int root, int lim){
  MST(flag,0); queue<int> q;
  q.push(root); flag[root]=1;
  node[root].dis=0;
  while(!q.empty()){
    int u=q.front(); q.pop();
    for(int v : edge[u]) if(!flag[v]){
      node[v].dis=node[u].dis+1;
      if(node[v].dis<=lim){
        if(!node[v].hasSon) node[v].done=1;
        q.push(v);
      }
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&n,&s,&k);
    FORR(i,1,n) edge[i].clear();
    FORR(i,0,maxDep) dep[i].clear();
    maxDep=0;

    FOR(i,1,n){
      int u,v; scanf("%d%d",&u,&v);
      edge[u].push_back(v);
      edge[v].push_back(u);
    }

    bfs(s);

    int cnt=0;
    RORR(i,maxDep,k) for(int j : dep[i])
      if(!node[j].hasSon && node[j].done==0){
        int p=j; FOR(d,0,k) p=node[p].fa;
        cnt++; bfs2(p,k);
      }
    printf("%d\n",cnt);
  }

  return 0;
}
