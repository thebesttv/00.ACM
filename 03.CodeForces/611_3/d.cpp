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
int n,m,x[MAX];
// map<int,bool> vis[MAX];
set<int> vis;

struct Node{
  int pos, dis, n;
  bool operator < (const Node &b) const {
    return dis > b.dis;
  }
};
PQ<Node> q;

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n){
    scanf("%d",&x[i]); vis.insert(x[i]);
  }
  sort(x,x+n);
  FOR(i,0,n){
    if(!i || x[i]-1 != x[i-1])
      q.push({x[i]-1,1,i});
    if(i+1==n || x[i]+1 != x[i+1])
      q.push({x[i]+1,1,i});
  }

  LL ans = 0;
  VR<int> v;
  while(m){
    Node t = q.top(); q.pop();
    // if(vis[t.pos]) continue;
    if(vis.find(t.pos) != vis.end()) continue;
    --m;
    // vis[t.pos] = true;
    vis.insert(t.pos);
    v.push_back(t.pos);
    ans += t.dis;
    if(t.pos < x[t.n]){ // left
      q.push({t.pos-1, t.dis+1, t.n});
    }else{  // right
      q.push({t.pos+1, t.dis+1, t.n});
    }
  }

  printf("%lld\n",ans);
  for(int x : v) printf("%d ",x);
  putchar('\n');

  return 0;
}
