// Tag: DP
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

const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f;
int n,a[MAX],f[MAX][2];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]), f[i][0] = f[i][1] = INF;

    f[0][1] = 0; f[0][0] = INF;
    FORR(i,1,n){
      if(i>1){
        f[i][0] = min(f[i-2][1] + a[i-1] + a[i], f[i-1][1] + a[i]);
        f[i][1] = min(f[i-2][0], f[i-1][0]);
      }else{
        f[i][0] = f[0][1] + a[i];
      }
#ifdef DEBUG
      FOR(j,0,2) if(f[i][j] < INF) printf("f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
    }
    printf("%d\n",min(f[n][0],f[n][1]));
  }

  return 0;
}
