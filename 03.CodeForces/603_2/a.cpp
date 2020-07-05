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

int v[3];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&v[0],&v[1],&v[2]);
    int ansMax = 0;
    FOR(i,0,3){
      int a = v[i], b = v[(i+1)%3], c = v[(i+2)%3];
      int t = max(0,(a+b-c+1)/2);
      if(t>a || t>b) continue;
      int x = t, y = b - x, z = a - x;
      if(x < 0 || y < 0 || z < 0) continue;
      ansMax = max(ansMax, x + y + z);
    }
    printf("%d\n",ansMax);
  }

  return 0;
}
