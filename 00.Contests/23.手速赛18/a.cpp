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

int main(void){
  int n,k; scanf("%d%d",&n,&k);
  VR<int> v;
  FORR(i,2,n) if(n%i==0){
    while(v.size()!=k-1 && n%i==0)
      v.push_back(i), n/=i;
    if(v.size()==k-1) break;
  }
  if(n>1) v.push_back(n);

  if(v.size()!=k) printf("-1");
  else for(int x : v) printf("%d ",x);
  putchar('\n');

  return 0;
}
