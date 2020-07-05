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

const int MOD = 11092019;
int n,cnt[26]; char s[100020];
int ans;

void dfs(int cur, int s){
  if(cur == 26){
    ans = (ans + s) % MOD;
    return;
  }
  if(cnt[cur]) dfs(cur+1, 1ll*s*cnt[cur]%MOD);
  dfs(cur+1, s);
}

int main(void){
  scanf("%s",s); n = strlen(s);
  FOR(i,0,n) ++cnt[s[i]-'a'];
  dfs(0, 1);
  printf("%d\n",ans);

  return 0;
}
