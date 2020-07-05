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

const int MAX = 2020;
int n,m,cnt[26],cMax; char s[MAX];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

bool ok(int len){
  int rlen = gcd(len, m);
  int rn = len / rlen;

  int s = 0;
  FOR(i,0,26) s += cnt[i]/rn;
  return s >= rlen;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    cMax = 0; MST(cnt,0);
    scanf("%d%d%s",&n,&m,s);
    FOR(i,0,n) ++cnt[s[i]-'a'];
    FOR(i,0,26) cMax = max(cMax,cnt[i]);

    int ans = 0;
    FORR(i,1,n) if(ok(i)) ans = i;
    printf("%d\n",ans);
  }

  return 0;
}
