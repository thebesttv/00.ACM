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

int n, s;

int main(void){
  scanf("%d%d",&n,&s);
  if(n==1){
    if(s==1) goto BAD;
    printf("YES\n%d\n%d\n",s,1);
    return 0;
  }
  if(s < n*2) goto BAD;

  printf("YES\n");
  FOR(i,1,n) printf("2 "), s-=2;
  printf("%d\n",s);
  printf("1\n");
  return 0;

BAD:
  printf("NO\n");
  return 0;
}
