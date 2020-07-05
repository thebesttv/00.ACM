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

const int MAX =1e5 + 20;
const int MOD = 1e9+7;
int n;
LL x[MAX], ans;
VR<map<LL,int> *> vmp[MAX];
VR<int> G[MAX];
map< map<LL,int>*, LL> s;

bool vis[MAX];

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}

void dfs(int u){
  vis[u] = 1;
  auto &vmpu = ::vmp[u];

  if(x[u]){
    vmpu.push_back(new map<LL,int>);
    for(int v : G[u]) if(!vis[v]){
      dfs(v);

      for(auto pmp : vmp[v]){
        for(auto p : *pmp)
          (*vmpu[0])[ gcd(p.FI, x[u]) ] += p.SE;
        delete pmp;
      }
    }
    ++(*vmpu[0])[x[u]];

    LL sum = 0;
    for(auto p : *vmpu[0]){
      sum = (sum + 1ll*p.FI%MOD*p.SE)%MOD;
    }
    s[vmpu[0]] = sum;
#ifdef DEBUG
    printf("  node %d, x %lld, ans += %lld\n",u,x[u],sum);
#endif
    ans = (ans + sum) % MOD;
  }else{
    LL sum = 0;
    vmpu.push_back(new map<LL,int>);
    for(int v : G[u]) if(!vis[v]){
      dfs(v);
      for(auto pmp : vmp[v]){
        vmpu.push_back(pmp);
        sum = (sum + s[pmp]) % MOD;
      }
    }
    s[vmpu[0]] = 0;

    if(vmpu.size() > 6){
      int tMax = 0, r = -1;
      FOR(i,0,vmpu.size()) if(vmpu[i]->size() > tMax){
        tMax = vmpu[i]->size();
        r = i;
      }
      swap(vmpu[0], vmpu[r]);

      FOR(i,1,vmpu.size()){
        for(auto p : *vmpu[i]){
          (*vmpu[0])[p.FI] += p.SE;
        }
        s[vmpu[i]] = 0;
        delete vmpu[i];
      }
      vmpu = VR<map<LL,int>*>{vmpu[0]};
      s[vmpu[0]] = sum;
    }

    ans = (ans + sum) % MOD;
#ifdef DEBUG
    printf("  node %d, x %lld, ans = %lld\n",u,x[u],ans);
#endif
    ++(*vmpu[0])[x[u]];
    // s[vmpu[0]] = 0;
  }

}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%lld",&x[i]);
  int u, v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    G[u].push_back(v);
    G[v].push_back(u);
  }

  dfs(1);
  printf("%lld\n",ans);

  return 0;
}
