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

const int MAX = 1e6 + 20;
int n, a[MAX];
LL s1[MAX], s2[MAX];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    s1[i] = s1[i-1] + a[i]*a[i];
  }
  ROR(i,n,1){
    s2[i] = s2[i+1] + a[i];
  }
  LL ansMax = 0;
  FOR(i,1,n) ansMax = max(ansMax, s1[i]*s2[i+1]);
  printf("%lld\n",ansMax);

  return 0;
}
