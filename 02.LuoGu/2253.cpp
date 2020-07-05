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

const int MAX = 20020;
int n,m,a[MAX];

int get(int l, int r){
  if(l==r) return 1;
  int m=(l+r)>>1;
  int ans=max(get(l,m),get(m+1,r));
  if(a[m]==a[m+1]) return ans;
  int i=m,j=m+1;
  while(i-1>=l && a[i-1]^a[i]==1) --i;
  while(j+1<=r && a[j+1]^a[j]==1) ++j;
  return max(ans, j-i+1);
}

int main(void){
  scanf("%d%d",&n,&m);
  int x,ansMax=0,rl=0,rr=0;
  while(m--){
    scanf("%d",&x);
    a[x]^=1;
    printf("%d\n",get(1,n));
  }

  return 0;
}
