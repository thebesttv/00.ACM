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

const int MAX = 1020;
int n,a[MAX],c0,c1,s0,s1;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    c0 = c1 = 0; s0 = (n+1)/2, s1 = n/2;
    int bad = 0;
    FOR(i,0,n){
      scanf("%d",&a[i]);
      if(a[i]&1) ++c1;
      else ++c0;
      if((a[i]&1) != (i&1)) ++bad;
    }

    if(c0 != s0 || c1 != s1){
      printf("-1\n");
    }else{
      printf("%d\n",bad/2);
    }
  }

  return 0;
}
