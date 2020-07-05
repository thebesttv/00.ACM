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

const int MAX=1e5+20;
int n,q[MAX],a[MAX];
bool vis[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) vis[i] = a[i] = 0;
    FORR(i,1,n){
      scanf("%d",&q[i]);
      if(q[i] > q[i-1]){
        vis[q[i]] = 1; a[i] = q[i];
      }
    }
#ifdef DEBUG
    FORR(i,1,n) if(vis[i]) printf(" %d used\n",i);
#endif
    int j = 1;
    bool impossible = 0;
    FORR(i,1,n) if(!a[i]){
      while(j <= q[i] && vis[j]) j++;
      if(j>q[i]){
        impossible = 1; break;
      }
      vis[j] = 1; a[i] = j; j++;
    }
    if(impossible) printf("-1\n");
    else{
      printf("%d",a[1]);
      FORR(i,2,n) printf(" %d",a[i]);
      putchar('\n');
    }
  }

  return 0;
}
