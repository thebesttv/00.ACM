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

const int MAX = 120;
int n,m,r[MAX],c[MAX],G[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&r[i]);
  FORR(j,1,m) scanf("%d",&c[j]);
  FORR(i,1,n) FORR(j,1,m){
    G[i][j] = min(r[i], c[j]);
  }
  bool ok = 1;
  FORR(i,1,n){
    int tMax = 0;
    FORR(j,1,m) tMax = max(tMax, G[i][j]);
    if(tMax != r[i])
      ok = 0;
  }
  FORR(j,1,m){
    int tMax = 0;
    FORR(i,1,n) tMax = max(tMax, G[i][j]);
    if(tMax != c[j])
      ok = 0;
  }
  printf("%s\n",ok ? "possible" : "impossible");

  return 0;
}
