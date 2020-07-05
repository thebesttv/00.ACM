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

const int MAX = 10000000, MAX_ = MAX+20;
int n,a[int(1e6)+20],cnt[MAX_];

inline int read(){
  int ch, sum=0;
  do ch = getchar(); while(!isdigit(ch));
  do sum = sum*10 + ch-'0', ch = getchar(); while(isdigit(ch));
  return sum;
}

int main(void){
  int T=read();
  FORR(kase,1,T){
    n = read();
    FOR(i,0,n) a[i]=read(), ++cnt[a[i]];

    LL ans = 1ll * cnt[0] * (n-cnt[0]);

    FORR(i,1,100) if(cnt[i]){
      int t = i*2;
      while(t<=MAX){
        ans += 1ll*cnt[t]*cnt[i];
        t += i;
      }
    }

    FOR(i,0,n) if(a[i]>100){
      int t = a[i]*2;
      while(t<=MAX){
        ans += cnt[t];
        t += a[i];
      }
    }

    printf("Test case #%d: %lld\n\n",kase,ans);
    FOR(i,0,n) cnt[a[i]] = 0;
  }

  return 0;
}

/*
int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]), ++cnt[a[i]];
    LL ans = cnt[0] * (n-cnt[0]);
    FOR(i,0,n) if(a[i]){
      int t = a[i]*2;
      while(t<=MAX){
        ans += cnt[t];
        t += a[i];
      }
    }
    printf("Test case #%d: %lld\n\n",kase,ans);
    FOR(i,0,n) cnt[a[i]] = 0;
  }

  return 0;
}
*/
