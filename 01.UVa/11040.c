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

int v[10][10];

int get(int i, int j){
  int a = v[i][j], b = v[i+2][j], c = v[i+2][j+2];
  // a = b + x + c + x
  return (a - b - c)/2;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    for(int i=1;i<=9;i+=2){
      for(int j=1;j<=i;j+=2){
        scanf("%d",&v[i][j]);
      }
    }
    for(int i=1;i<=7;i+=2)
      for(int j=1;j<=i;j+=2)
        v[i+2][j+1] = get(i,j);

    for(int i=2;i<=8;i+=2) FORR(j,1,i)
      v[i][j] = v[i+1][j] + v[i+1][j+1];

    FORR(i,1,9){
      printf("%d",v[i][1]);
      FORR(j,2,i) printf(" %d",v[i][j]);
      printf("\n");
    }
  }

  return 0;
}
