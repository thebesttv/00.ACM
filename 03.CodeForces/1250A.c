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
int n,m,v[MAX],pos[MAX];
int pMin[MAX],pMax[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n)
    v[i]=pos[i]=pMin[i]=pMax[i]=i;

  int x,y;
  while(m--){
    scanf("%d",&x);
    if(pos[x]==1) continue;
    y = v[pos[x]-1];
    swap(v[pos[x]], v[pos[x]-1]);
    --pos[x], ++pos[y];
    pMin[x] = min(pMin[x], pos[x]);
    pMax[y] = max(pMax[y], pos[y]);
  }
  FORR(i,1,n) printf("%d %d\n",pMin[i],pMax[i]);

  return 0;
}
