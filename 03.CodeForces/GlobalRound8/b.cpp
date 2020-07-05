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

const char *str = "codeforces";
LL cnt[20], k;

int main(void){
  cin >> k;
  FOR(i,0,10) cnt[i] = 1;
  LL s = 1; int idx = 0;
  while(s < k){
    ++cnt[idx];
    s = 1; FOR(i,0,10) s *= cnt[i];
    idx = (idx + 1)%10;
  }
  FOR(i,0,10) FOR(j,0,cnt[i])
    putchar(str[i]);
  putchar('\n');

  return 0;
}
