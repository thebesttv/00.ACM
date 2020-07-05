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

int n, s,p;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    map<int, pair<int,int>> mp;
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&s,&p);
      if(!mp.count(s)) mp[s] = {0,0};
      if(p==0) mp[s].first++;
      else mp[s].second++;
    }
    printf("%d\n",mp.size());
    for(auto p : mp){
      printf("%d %d %d\n",p.first,p.second.FI,p.SE.SE);
    }
  }

  return 0;
}
