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

int a,b;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&a,&b);
    printf("%d\n",min((a+b)/3,min(a,b)));
  }

  return 0;
}

/*
int a,b;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&a,&b);
    if(a < b) swap(a,b);
    int ans=0;
    if(a >= b*2){
      ans = b;
    }else{
      ans = min(a - b, min(a/2,b));
      a -= 2 * ans, b -= ans;
      int d = min(a,b)/3;
      a -= d*3, b -= d*3;
      ans += d*2 + ( (a>=2 && b>=1) || (a>=1 && b>=2) );
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
