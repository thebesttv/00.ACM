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

const int MAX = 204;
const int MOD = 1e9 + 7;
int n,K,a[MAX];
int f[MAX][MAX][1004];
VR<int> v[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&K);
  FORR(i,1,n) scanf("%d",&a[i]);
  sort(a+1,a+1+n);

  f[0][0][0] = 1;
  v[0][0].push_back(0);
  FOR(i,0,n) FORR(j,0,i) for(int k : v[i][j]){
    int ori = f[i][j][k];
    FORR(r,i+1,n){
      if(k+a[r]-a[i+1] > K) break;
      int &t = f[r][j+1][k + a[r]-a[i+1]];
      if(!t) v[r][j+1].push_back(k+a[r]-a[i+1]);
      t = (t + ori)%MOD;
    }
  }
  int ans = 0;
  FORR(i,1,n) for(int k : v[n][i]){
    ans = (ans + f[n][i][k])%MOD;
  }
#ifdef DEBUG
  FORR(i,0,n) FORR(j,0,i) for(int k : v[i][j]){
    printf("  f[%d][%d][%d]: %d\n",i,j,k,f[i][j][k]);
  }
#endif
  printf("%d\n",ans);

  return 0;
}
