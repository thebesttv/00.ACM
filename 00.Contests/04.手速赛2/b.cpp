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
int n,m,k; bool ok[MAX];
struct Node{
  int v, pos;
  bool operator < (const Node &b) const {
    return v > b.v;
  }
}node[MAX];

int main(void){
  scanf("%d%d%d",&n,&m,&k);
  FORR(i,1,n){
    scanf("%d",&node[i].v);
    node[i].pos = i;
  }
  sort(node+1, node+1+n);

  int r = m*k; LL ans = 0;
  FORR(i,1,r){
    ok[node[i].pos] = 1;
    ans += node[i].v;
  }

  VR<int> ansv;
  int cnt = 0;
  FORR(i,1,n){
    if(ok[i]) ++cnt;
    if(cnt == m){
      ansv.push_back(i);
      cnt = 0;
    }
  }
  printf("%lld\n",ans);
  int sz = ansv.size() - 1;
  FOR(i,0,sz) printf("%d ",ansv[i]);
  putchar('\n');

  return 0;
}
