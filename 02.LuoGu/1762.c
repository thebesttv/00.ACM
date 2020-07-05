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

int v[1000][1000];
int main(void){
  int n = 150;
  v[0][0] = 1;
  FOR(i,1,n){
    v[i][0] = 1;
    FOR(j,1,i){
      v[i][j] = v[i-1][j] ^ v[i-1][j-1];
    }
    v[i][i] = 1;
  }

  int ans = 0;
  FOR(i,0,n){
    int sum = 0;
    FORR(j,0,i) if(v[i][j]) sum++;
    printf("%2d - %3d, %5d\n",i+1,sum,ans+=sum);
    /*
    FORR(j,0,i){
      if(!v[i][j]) printf("0");
      else putchar(' ');
    }
    */
  }

  return 0;
}
