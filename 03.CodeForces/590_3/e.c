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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=200020;
int n,m,x[MAX],cnt[MAX];
LL res[MAX];
VR<int> adj[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d",&x[i]);
  FOR(i,1,m){
    int l=x[i], r=x[i+1];
    if(l==r) continue;
    adj[l].push_back(r);
    adj[r].push_back(l);

    if(l>r) swap(l,r);
    res[1] += r-l;
    if(r-l>=2) cnt[l+1]++, cnt[r]--;
  }
  FORR(i,2,n) cnt[i]+=cnt[i-1];

  printf("%lld",res[1]);
  FORR(i,2,n){
    res[i] = res[1]-cnt[i];
    for(int j : adj[i]){
      res[i] -= abs(i-j);
      res[i] += j - (j>i);
    }
    printf(" %lld",res[i]);
  }
  putchar('\n');

  return 0;
}
