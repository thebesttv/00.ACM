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

const int MAX = 1000 * 100 + 20;
int n,m; char s[40];
struct Node{
  int idx;
  VR<pii> v;
  Node(): idx(0) { }
};
map<string,Node> mp;

pii get(char *s){
  if(!mp.count(s))
    return {-1,-1};
  Node &t = mp[s];
  pii p = t.v[t.idx];
  t.idx = (t.idx+1)%t.v.size();
  return p;
}

int main(void){
  scanf("%d",&m);
  FORR(i,1,m){
    int t; scanf("%d",&t);
    FORR(j,1,t){
      scanf("%s",s); mp[s].v.push_back({i,j});
    }
  }
  scanf("%d",&n);
  VR<pii> ans;
  bool ok = 1;
  while(n--){
    scanf("%s",s);
    pii p = get(s);
    if(p.FI==-1){
      ok = 0; break;
    }
    ans.push_back(p);
  }
  if(!ok) printf("NOT POSSIBLE\n");
  else for(auto p : ans) printf("%d %d\n",p.FI,p.SE);

  return 0;
}
