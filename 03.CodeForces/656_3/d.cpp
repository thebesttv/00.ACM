// Tag: DFS
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

const int MAX = 140000;
const int INF = 0x3f3f3f3f;
int n,s[26][MAX], ansMin; char str[MAX];

void dfs(int l, int r, int ch, int cnt){
#ifdef DEBUG
  printf("  (%d, %d, %c, %d)\n",l,r,(char)(ch+'a'),cnt);
#endif
  if(cnt >= ansMin) return;
  if(l == r){
    if(str[l] != ch+'a') ++cnt;
    ansMin = min(cnt, ansMin);
    return;
  }

  int m = (l+r)/2;
  // left c
  dfs(m+1, r, ch+1, cnt + (m-l+1 - (s[ch][m] - s[ch][l-1])));
  // right c
  dfs(l, m, ch+1, cnt + (r-m - (s[ch][r] - s[ch][m])));
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%s",&n,str+1); ansMin = INF;
    FORR(i,1,n) FOR(ch,0,26){
      s[ch][i] = s[ch][i-1] + (str[i]==ch+'a');
    }
    dfs(1,n,0,0);
    printf("%d\n",ansMin);
  }

  return 0;
}
