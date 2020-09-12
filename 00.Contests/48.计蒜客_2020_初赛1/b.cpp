// Tag: notag
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 3e5 + 20;
int n,m; LL b[MAX],w[MAX],s[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%lld",&b[i]);
  FORR(i,1,n) scanf("%lld",&w[i]);
  FORR(i,1,n){
    s[i] = s[i-1] + max(w[i],b[i]);
    b[i] += b[i-1], w[i] += w[i-1];
  }

  LL ans = s[n];
  while(m--){
    int t,l,r,c;
    scanf("%d%d%d%d",&t,&l,&r,&c);
    if(t == 1){ // black
      ans = max(ans, ans - (s[r] - s[l-1]) + c + b[r] - b[l-1]);
    }else{  // white
      ans = max(ans, ans - (s[r] - s[l-1]) + c + w[r] - w[l-1]);
    }
  }
  printf("%lld\n",ans);

  return 0;
}
