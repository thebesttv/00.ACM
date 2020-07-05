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

const int MAX = 1e5 + 20;
int n,m; LL bal[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  int u,v; LL w;
  while(m--){
    scanf("%d%d%lld",&u,&v,&w);
    bal[u]+=w, bal[v]-=w;
  }

  VR<int> out; queue<int> in;
  FORR(i,1,n)
    if(bal[i]>0) out.push_back(i);
    else if(bal[i]<0) in.push(i);

  int sum=0; string ans; char buf[100];
  for(int u : out){
    while(!in.empty() && bal[u]){
      int v = in.front();
      LL t = min(bal[u], abs(bal[v]));
      bal[u]-=t, bal[v]+=t;
      if(!bal[v]) in.pop();

      sprintf(buf, "%d %d %lld\n", u,v,t);
      ans += buf; ++sum;
    }
  }

  printf("%d\n",sum);
  cout << ans;

  return 0;
}
