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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int a,b,c,d;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(b >= a){
      printf("%d\n",b);
      continue;
    }

    if(c <= d){
      printf("-1\n");
    }else{
      LL delta = a - b;
      LL ans = b;
      if(delta % (c-d)==0)
        ans += delta / (c-d) * c;
      else
        ans += (delta/(c-d)+1)*c;
      printf("%lld\n",ans);
    }
  }

  return 0;
}
