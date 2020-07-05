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

const int MAX = 1e6 + 20;
int n, k, s[MAX], f[MAX];
char str[MAX];

int sum(int l, int r) { return s[r] - s[l-1]; }

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%s",&n,&k,str+1);
    f[1] = (str[1] == '0');
    s[1] = (str[1] == '1');
    FORR(i,2,n){
      s[i] = s[i-1] + (str[i]=='1');
      f[i] = sum(1, i-1) + (s[i]=='0');
      if(i > k)
        f[i] = min(f[i], f[i-k] + sum(i-k+1 ,i-1)) + (str[i]=='0');
    }
    int ans = min(s[n], f[n]);
    FOR(i,1,n) ans = min(ans, f[i] + sum(i+1,n));
    printf("%d\n",ans);
  }

  return 0;
}

/*
const int MAX = 1e6 + 20;
int n, k, sum; char s[MAX];
VR<int> pos[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%s",&n,&k,s+1);
    sum = 0; FOR(i,0,k) pos[i].clear();
    FORR(i,1,n) if(s[i]=='1'){
      ++sum; pos[i%k].push_back(i);
    }

    int ans = MAX;
    FOR(i,0,k){
      int cnt = pos[i].size(), x = 0;
      if(cnt) x = (pos[i].back() - pos[i].front()) / k + 1;
#ifdef DEBUG
      printf("  i: %d, cnt: %d, x: %d\n",i,cnt,x);
#endif
      ans = min(ans, x - cnt + (sum - cnt));
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
