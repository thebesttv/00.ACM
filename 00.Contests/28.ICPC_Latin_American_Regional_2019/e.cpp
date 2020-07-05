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

const int MAX = 2e5 + 20;
int n,m; char s[MAX];
VR<int> pos;

int main(void){
  scanf("%s%d",s,&m); n = strlen(s);
  FOR(i,0,n) s[i+n]=s[i];
  FOR(i,0,n*2) if(s[i]=='E') pos.push_back(i);

  LL ans = 0; int i=0;
  for(int v : pos){
    while(i<n && i<=v){
      if(v-i+1 <= m)
        ans += m - (v-i+1) + 1;
      ++i;
    }
    if(i>=n) break;
  }
  printf("%lld\n",ans);

  return 0;
}
