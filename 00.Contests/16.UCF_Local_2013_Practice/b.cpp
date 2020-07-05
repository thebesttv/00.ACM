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
int n,x[MAX],y[MAX];
double d[MAX][MAX];

double dis(int i, int j){
  return sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
}

int cmp(double x){
  if(fabs(x)<1e-6) return 0;
  else return x<0 ? -1 : 1;
}

bool ok(int i, int j, int k){
  /*
  double v[3] = {d[i][j],d[i][k],d[j][k]};
  FOR(a,0,3){
    if(cmp(v[a] + v[(a+1)%3]- v[(a+2)%3])<=0)
      return false;
  }
  return true;
  */
  int x1 = x[j]-x[i], y1 = y[j]-y[i], x2 = x[k]-x[i], y2 = y[k]-y[i];
  return x1*y2-x2*y1!=0;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&x[i],&y[i]);
    }
    int ans = 0;
    FOR(i,0,n) FOR(j,i+1,n) FOR(k,j+1,n){
      if(ok(i,j,k)){
        ++ans;
      }
    }
    printf("Test case #%d: %d triangle(s) can be formed.\n\n",kase,ans);
  }

  return 0;
}
