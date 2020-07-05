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

const int MAX = 2e5 + 20;
int n, a[MAX], in[MAX];
int vis[MAX];
VR<int> G[MAX];

struct Node{
  int v, n;
  bool operator < (const Node &b) const {
    return n > b.n;
  }
};
PQ<Node> q;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n-1){
    scanf("%d",&a[i]), ++vis[a[i]];
  }

  FORR(i,1,n) if(!vis[i]){
    q.push({i,i});
  }

  VR<pair<int,int>> v;
  bool bad = 0;
  ROR(i,n-2,0){
    if(q.empty()){
      bad = 1; break;
    }
    Node t = q.top(); q.pop();

    --vis[a[i]];
    v.push_back({a[i],t.v});
    ++in[t.v];
    if(!vis[a[i]])
      q.push( {a[i], max(a[i], t.n) });
  }
  if(bad){
    printf("-1\n"); return 0;
  }

  int root = 0;
  FORR(i,1,n) if(!in[i]){
    root = i; break;
  }

  printf("%d\n",root);
  for(auto t : v)
    printf("%d %d\n",t.FI,t.SE);

  return 0;
}
