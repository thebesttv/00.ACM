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

LL n,v[100];

bool ok(int d){
  FORR(i,2,d) if(v[i] - v[i-1] > v[i-1])
    return false;
  LL sum = 0, s[100]; s[0] = 0;
  FORR(i,1,d) s[i] = s[i-1] + v[i], sum += v[i];
  return sum == n;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(v,0);
    scanf("%lld",&n);
    if(n==2){
      printf("1\n0\n"); continue;
    }else if(n==3){
      printf("2\n0 0\n"); continue;
    }else if(n==4){
      printf("2\n0 1\n"); continue;
    }

    --n;
    v[1] = 2;
    LL sum = 2; int i = 1;
    while(sum < n){
      ++i;
      if(sum + 2*v[i-1] < n){
        if(sum + 4*v[i-1] <= n){
          v[i] = 2 * v[i-1];
          sum += v[i];
        }else{
          LL d = (n-sum)/2 - v[i-1];
          v[i] = v[i-1] + d;
          sum += v[i];
        }
      }else{
        v[i] = n - sum; break;
      }
    }
#ifdef DEBUG
    //FORR(j,1,i) printf(" %lld",v[j]); putchar('\n');
#endif

    printf("%d\n",i);
    v[0] = 1;
    FORR(j,1,i) printf("%lld ",v[j] - v[j-1]); putchar('\n');
#ifdef DEBUG
    if(!ok(i)){
      printf("WRONG\n");
      exit(0);
    }
#endif
  }

  return 0;
}
