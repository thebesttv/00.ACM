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

int n;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    if(n <= 3){
      printf("-1\n");
    }else if(n==4){
      printf("3 1 4 2\n");
    }else if(n==5){
      printf("3 1 5 2 4\n");
    }else if(n==6){
      printf("1 3 5 2 4 6\n");
    }else{
      int i = 1; printf("%d ",i);
      while(i+2 <= n){
        i += 2;
        printf("%d ",i);
      }
      i -= 3; printf("%d ",i);
      if(n&1){
        i += 2; printf("%d ",i);
        i -= 4; printf("%d ",i);
        while(i-2 > 0){
          i -= 2; printf("%d ",i);
        }
      }else{
        i += 4; printf("%d ",i);
        i -= 2; printf("%d ",i);
        i -= 4; printf("%d ",i);
        while(i-2 > 0){
          i -= 2; printf("%d ",i);
        }
      }
      putchar('\n');
    }
  }

  return 0;
}
