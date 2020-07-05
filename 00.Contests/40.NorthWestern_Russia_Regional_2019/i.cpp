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

const int INF = 0x3f3f3f3f;
const int MAX = 1020;
int n,x[MAX],y[MAX],z[MAX];
int X1, X2, Y1, Y2;

int main(void){
  scanf("%d",&n);
  X1 = INF, X2 = -INF;
  Y1 = INF, Y2 = -INF;
  FOR(i,0,n){
    scanf("%d%d%d",&x[i],&y[i],&z[i]);
    X1 = min(X1, x[i]-z[i]);
    X2 = max(X2, x[i]+z[i]);
    Y1 = min(Y1, y[i]-z[i]);
    Y2 = max(Y2, y[i]+z[i]);
  }

  int ax, ay, az;

  if((X2 - X1)&1){
    ax = (X1+X2+1)/2;
  } else {
    ax = (X1+X2)/2;
  }


  if((Y2 - Y1)&1){
    ay = (Y1+Y2+1)/2;
  } else {
    ay = (Y1+Y2)/2;
  }

  az = max((X2-X1+1)/2, (Y2-Y1+1)/2);

  printf("%d %d %d\n", ax, ay, az);

  return 0;
}
