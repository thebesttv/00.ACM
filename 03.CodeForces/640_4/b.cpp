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

int n,k;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    int x = n; VR<int> v;
    FOR(i,1,k) v.push_back(1), x-=1;
    if(x>0 && x&1){
      printf("YES\n");
      FOR(i,1,k) printf("1 ");
      printf("%d\n",x);
      continue;
    }
    v.clear();

    x = n;
    FOR(i,1,k) v.push_back(2), x-=2;
    if(x>0 && (x&1)==0){
      printf("YES\n");
      FOR(i,1,k) printf("2 ");
      printf("%d\n",x);
      continue;
    }
    printf("NO\n");
  }

  return 0;
}
