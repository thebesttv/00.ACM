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

int v[20][20];

int main(void){
  int n; scanf("%d",&n);
  if(n==1){
    printf("%4d\n",1); return 0;
  }

  v[0][0]=1; v[1][0] = v[1][1]=1;
  FOR(i,1,n) putchar(' '); printf("%4d\n",1);
  FOR(i,2,n) putchar(' '); printf("%4d%4d\n",1,1);

  FOR(i,2,n){
    FOR(j,i+1,n) putchar(' ');
    printf("%4d",1); v[i][0]=1;
    FOR(j,1,i){
      v[i][j] = v[i-1][j-1] + v[i-1][j];
      printf("%4d",v[i][j]);
    }
    v[i][i]=1; printf("%4d\n",1);
  }

  return 0;
}
