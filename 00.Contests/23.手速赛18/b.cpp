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
VR<int> odd, even;

int main(void){
  int x; scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d",&x);
    if(x&1) odd.push_back(x);
    else even.push_back(x);
  }

  LL ans = 0;
  for(int x : even) if(x>0)
    ans += x;

  sort(ALL(odd),greater<int>());
  ans += odd[0];
  for(int i=1;i+1<odd.size();i+=2){
    int t = odd[i]+odd[i+1];
    if(t>0) ans += t;
    else break;
  }
  printf("%lld\n",ans);

  return 0;
}
