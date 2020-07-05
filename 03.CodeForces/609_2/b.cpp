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

const int MAX = 2020;
int n; LL m;

struct Node{
  LL n; int cnt;
};
VR<Node> a, b;
map<int,int> mpa,mpb;

bool ok(int s, LL x){
  FOR(i,0,n){
    Node &na = a[i],
         &nb = b[(i+s)%n];
    if(na.cnt != nb.cnt) return false;
    if((na.n + x)%m != nb.n) return false;
  }
  return true;
}

int main(void){
  scanf("%d%lld",&n,&m);
  int x;
  FOR(i,0,n){
    scanf("%d",&x); ++mpa[x];
  }
  FOR(i,0,n){
    scanf("%d",&x); ++mpb[x];
  }

  for(const auto &p : mpa)
    a.push_back({p.FI, p.SE});
  for(const auto &p : mpb)
    b.push_back({p.FI, p.SE});

  n = a.size();

  LL ans = -1;
  Node na = a[0];
  FOR(i,0,n) if(na.cnt == b[i].cnt){
    Node nb = b[i];
    LL x = (nb.n - na.n + m) % m;
    if(ok(i,x)){
      if(ans==-1) ans = x;
      else ans = min(ans, x);
    }
  }
  printf("%lld\n",ans);

  return 0;
}
