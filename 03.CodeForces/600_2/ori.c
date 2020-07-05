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

const int MAX=200020;
int n,m; LL a[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%lld",&a[i]);
  sort(a,a+n);
  FORR(k,1,n){
    int cnt = m, day = 1;
    LL sum = 0;
    //ROR(i,k,1){
    ROR(i,k-1,0){
      if(cnt==0) cnt=m, day++;
      sum += a[i] * day; cnt--;
    }
    printf("%lld ",sum);
  }
  putchar('\n');

  return 0;
}
