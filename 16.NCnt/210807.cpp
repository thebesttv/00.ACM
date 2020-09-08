// Tag: 区间DP
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

const int MAX = 520;
const int INF = 0x3f3f3f3f;
int n,a[MAX],b[MAX],f[MAX][MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);
  FORR(i,1,n) scanf("%d",&b[i]);
  FORR(j,1,n){
    f[j][j] = b[j-1] + a[j] + b[j+1];
    ROR(i,j-1,1){
      f[i][j] = INF;
      FORR(k,i,j)
        f[i][j] = min(f[i][j], f[i][k-1] + f[k+1][j] + b[i-1] + a[k] + b[j+1]);
    }
  }
  printf("%d\n",f[1][n]);

  return 0;
}
