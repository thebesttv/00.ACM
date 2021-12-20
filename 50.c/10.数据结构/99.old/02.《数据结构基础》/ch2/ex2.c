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

const int MAX=100;

int **make2dArray(int r, int c[]){
  int **x = (int**) malloc(r * SIZ(*x));
  FOR(i,0,r) x[i] = (int*) malloc(c[i] * SIZ(**x));
  return x;
}

int main(void){
  int length[MAX];
  int n; scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&length[i]);

  int **a = make2dArray(n,length);

  int cnt=0;
  FOR(i,0,n) FOR(j,0,length[i])
    a[i][j] = ++cnt;

  FOR(i,0,n){
    FOR(j,0,length[i]) printf("%4d",a[i][j]);
    printf("\n");
  }

  return 0;
}
