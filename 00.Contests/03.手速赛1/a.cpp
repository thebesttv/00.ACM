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

const int MAX = 120;
int n; char s[MAX];
LL f[MAX][3];

int main(void){
  scanf("%s",s);
  n = strlen(s);
  LL sum = 0;
  FOR(i,0,n){
    if(s[i] == 'Q'){
      f[i][0] = 1;
      FOR(j,0,i) f[i][2] += f[j][1];
      sum += f[i][2];
    }else if(s[i] == 'A'){
      FOR(j,0,i) f[i][1] += f[j][0];
    }
  }
  printf("%lld\n",sum);

  return 0;
}
