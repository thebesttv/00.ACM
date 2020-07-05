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

const int MAX = 1020;
const int MOD = 10000;
int n,m,f[MAX][MAX],s1[MAX],s2[MAX];

int main(void){
  scanf("%d%d",&m,&n);
  FORR(i,1,n) f[1][i] = 1, s1[i] = s1[i-1] + f[1][i];
  ROR(i,n,1) s2[i] = s2[i+1] + f[1][i];

  FORR(i,2,m){
    if(i&1) FORR(j,2,n) f[i][j] = s1[j-1];
    else FOR(j,1,n) f[i][j] = s2[j+1];

    FORR(j,1,n) s1[j] = (s1[j-1] + f[i][j])%MOD;
    ROR(j,n,1) s2[j] = (s2[j+1] + f[i][j])%MOD;
  }

  int ans = 0;
  FORR(i,1,n) ans = (ans + f[m][i])%MOD;
  printf("%d\n",ans);

  return 0;
}
