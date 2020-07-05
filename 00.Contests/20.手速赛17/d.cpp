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

const int MAX = 5020;
const LL MOD = 1e9 + 7;
int n,m; char s[MAX],t[MAX];
LL cnt[MAX];
VR<int> pos[128];

int main(void){
  scanf("%s%s",s,t);
  n=strlen(s), m=strlen(t);
  FOR(i,0,n) pos[s[i]].push_back(i);

  FORR(ch,'a','z') reverse(ALL(pos[ch]));

  FOR(i,0,m) for(int p : pos[t[i]]){
    if(p==0){
      cnt[p] = (cnt[p] + 1) % MOD;
    }else{
      cnt[p] = (cnt[p] + 1 + cnt[p-1]) % MOD;
    }
  }

  LL ans = 0;
  FOR(i,0,n) ans = (ans + cnt[i]) % MOD;
  printf("%lld\n",ans);

  return 0;
}
