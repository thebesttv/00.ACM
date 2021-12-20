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
typedef long long LL;
typedef long long unsigned LLU;

int dcmp(double x){
  if(fabs(x)<0.05) return 0;
  else return x < 0 ? -1 : 1;
}

int main(void){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double r1 = x1 + x2;
  double r2 = y1 + y2;
  printf("(%.1lf, %.1lf)\n",(!dcmp(r1)) ? 0 : r1,(!dcmp(r2)) ? 0 : r2);

  return 0;
}
