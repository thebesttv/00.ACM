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

const int MAX = 1e4 + 20;
int n,m,ans[MAX];
VR<pii> c;
VR<pair<pii,int>> v;

bool ok(){
  int i = 0;
  for(auto p : c){
    while(i<n && !(p.FI == v[i].FI.FI || p.FI == v[i].FI.SE)) ++i;
    if(i>=n) return false;
    ans[p.SE] = v[i].SE;
    ++i;
  }
  return true;
}

int main(void){
  scanf("%d%d",&n,&m);
  int l,r;
  FOR(i,0,n){
    scanf("%d%d",&l,&r);
    if(l>r) swap(l,r);  // l <= r
    v.push_back({{l,r},i});
  }
  sort(ALL(v));

  FOR(i,0,m){
    scanf("%d",&l);
    c.push_back({l,i});
  }
  sort(ALL(c));

  if(!ok()) printf("impossible\n");
  else{
    FOR(i,0,m) printf("%d\n",ans[i]+1);
  }

  return 0;
}
