// Tag: 找规律
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

int d,n;

int f(int cur, int n, int l, int r){
  if(cur == d) return l + (1 << (d-1));
  int m = (l+r)/2;
  if(n&1) return f(cur+1, (n+1)/2, l, m);
  else return f(cur+1, n/2, m, r);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&d,&n);
    printf("%d\n",f(1,n,0,1 << (d-1)));
  }

  return 0;
}
