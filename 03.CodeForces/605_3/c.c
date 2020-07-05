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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 2e5 + 20;
int n, k; bool ok[256];
char s[MAX];

int main(void){
  scanf("%d%d",&n,&k);
  scanf("%s",s);
  int ch;
  FOR(i,0,k){
    do ch=getchar(); while(!isalpha(ch));
    ok[ch] = 1;
  }
  LL ans = 0, cnt = 0;
  int l = 0;
  while(l<n){
    while(l<n && !ok[s[l]]) ++l;
    if(l>=n) break;
    int r = l + 1;
    while(r<n && ok[s[r]]) ++r;
    cnt = r - l;
    ans += cnt*(cnt+1ll)/2ll;
    l = r+1;
  }
  printf("%lld\n",ans);
}
