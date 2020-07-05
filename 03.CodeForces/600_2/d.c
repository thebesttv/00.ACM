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

const int MAX=200020;
int n,m,color;
VR<int> G[MAX],in[MAX], out[MAX];
int vis[MAX], cMax[MAX], cMin[MAX];

void bfs(int u, int c){
  queue<int> q;
  q.push(u); vis[u]=c;
  cMax[c] = max(cMax[c], u);
  cMin[c] = min(cMin[c], u);
  while(!q.empty()){
    u = q.front(); q.pop();
    for(int v : G[u]) if(!vis[v]){
      vis[v]=c; q.push(v);
      cMax[c] = max(cMax[c], v);
      cMin[c] = min(cMin[c], v);
    }
  }
}

struct Node{
  int l, r;
  bool operator < (const Node &b) const {
    return l < b.l;
  }
};
VR<Node> v;

int main(void){
  scanf("%d%d",&n,&m);
  while(m--){
    int u, v; scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  MST(cMin,0x3f);
  FORR(i,1,n) if(!vis[i]){
    bfs(i,++color);
  }
#ifdef DEBUG
  FORR(i,1,n) printf("c[%d]: %d\n",i,vis[i]);
#endif
  FORR(i,1,color){
    //v.push_back(Node{cMin[i],cMax[i]});
    in[cMin[i]].push_back(i);
    out[cMax[i]+1].push_back(i);
  }

  set<int> st;
  int cnt = 0, ans = 0;
  FORR(i,1,n+1){
#ifdef DEBUG
    printf("%d:",i);
    for(int v : st) printf(" %d",v);
    putchar('\n');
#endif
    for(int v : out[i])
      st.erase(v);
    if(st.empty()){
      ans += max(0,cnt-1);
      cnt = 0;
    }
    for(int v : in[i]){
      st.insert(v);
      cnt++;
    }
  }
  printf("%d\n",ans);

  return 0;
}

  /*
  int ans = 0;
  int i = 0, j;
  while(i < v.size()){
    int l = v[i].l, r = v[i].r;
    j = i + 1;
    while(j<v.size() && v[j].l <= r){
      r = max(r, v[j].r); j++;
    }
    ans += j-i-1;
    i = j+1;
  }
  printf("%d\n",ans);
  */
