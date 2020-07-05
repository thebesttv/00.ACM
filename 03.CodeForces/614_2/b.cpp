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

const int MAX = 1e5 + 20;
int n; //long double f[MAX];

int main(void){
  scanf("%d",&n);
  long double ans = 1;
  FORR(i,2,n)
    ans += 1.0 / i;
  printf("%.12Lf\n",ans);
  //cout << ans << endl;

  return 0;
}

/*
int main(void){
  f[1] = 1;
  FORR(i,2,100){
    long double &a = f[i];
    int r = 0;
    FOR(j,1,i){
      //a = max(a, f[i-j] + 1.0*j/i);
      long double t = f[i-j] + 1.0*j/i;
      if(t > a){
        a = t, r = j;
      }
    }
    printf("f[%d]: %d, %Lf\n",i,r,f[i]);
  }

  return 0;
}
*/
