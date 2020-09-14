// Tag: ii 正难则反 DP
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2320;
int n,m,v[MAX],f[MAX],g[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&v[i]);

  f[0] = 1;
  FORR(i,1,n) ROR(j,m,v[i])
    f[j] = (f[j] + f[j-v[i]])%10;
#ifdef DEBUG
  FORR(i,1,m) printf("f[%d]: %d\n",i,f[i]);
#endif

  FORR(i,1,n){
    FOR(j,0,v[i]) g[j] = f[j];
    FORR(j,v[i],m) g[j] = (f[j] - g[j-v[i]] + 10)%10;
    FORR(j,1,m) putchar('0'+g[j]); putchar('\n');
  }

  return 0;
}
