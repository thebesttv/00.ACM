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

const int MAX=100*20 + 20;
int n,m,f[120],p[MAX],w[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(f,0);
    scanf("%d%d",&n,&m);
    int a,b,c, tail=0;
    FOR(i,0,m){
      scanf("%d%d%d",&a,&b,&c);
      while(c){
        p[tail]=a, w[tail++]=b;
        --c;
      }
    }
    FOR(i,0,tail) ROR(j,n,p[i])
      f[j] = max(f[j], f[j-p[i]] + w[i]);
#ifdef DEBUG
    FORR(i,0,n) printf("f[%d]: %d\n",i,f[i]);
#endif
    printf("%d\n",f[n]);
  }

  return 0;
}
