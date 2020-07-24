// Tag: 
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
int n,m,f[MAX][MAX];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

int main(void){
  FORR(i,1,1000) FORR(j,1,1000)
    f[i][j] = max(f[i-1][j], f[i][j-1]) + (gcd(i,j)==1);

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    printf("%d\n",f[n][m]);
  }

  return 0;
}
