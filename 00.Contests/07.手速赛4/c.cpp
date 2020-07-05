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

int a, b;
map<int, int> mp;
int v[]={1, 1, 5, 1, 21, 1, 85, 73, 341, 89, 1365, 1, 5461, 4681, 21845, 1, 87381, 1, 349525, 299593, 1398101, 178481, 5592405, 1082401, 22369621, };

int length(int a){
  ROR(i,30,0) if(a & (1<<i))
    return i + 1;
  return 0;
}

int gcd(int a, int b){
  return !b ? a : gcd(b, a%b);
}

int main(void){
  FORR(i,2,26){
    a = (1<<i)-1;
    mp[a] = v[i-2];
  }

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&a);
    if(mp.count(a)){
      printf("%d\n",mp[a]);
    }else{
      int len = length(a);
      b = (~a) & ( (1<<len)-1);
      printf("%d\n",(1<<len)-1);
    }
  }

  return 0;
}
