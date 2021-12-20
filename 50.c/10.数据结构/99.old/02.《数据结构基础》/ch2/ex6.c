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
typedef long long LL;
typedef long long unsigned LLU;

int **make2dArray(int r, int c){
  int **x = (int**) malloc(r * SIZ(*x));
  FOR(i,0,r) x[i] = (int*) malloc(c * SIZ(**x));
  return x;
}

void transpose(int **a, int **b, int r, int c){
  FOR(i,0,r) FOR(j,0,c) b[j][i]=a[i][j];
}

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  int **a = make2dArray(n,m);
  int **b = make2dArray(m,n);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
  transpose(a,b,n,m);

  FOR(i,0,m){
    FOR(j,0,n) printf("%4d",b[i][j]);
    putchar('\n');
  }

  return 0;
}
