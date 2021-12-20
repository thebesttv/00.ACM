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
  int **x;
  x = (int**) malloc( r * SIZ(*x) );
  FOR(i,0,r)
    x[i] = (int*) malloc( c * SIZ(**x) );
  return x;
}

int main(void){
  int r=4, c = 6;
  int **a = make2dArray(r,c);

  FOR(i,0,r) FOR(j,0,c) a[i][j] = i*c + j + 1;

  FOR(i,0,r){
    FOR(j,0,c) printf("%4d",a[i][j]);
    putchar('\n');
  }

  return 0;
}
