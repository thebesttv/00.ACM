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

const int MAX = 200000 + 20;
int n; char s[MAX];
map<LL,int> cnt;

int len(LL x){
  int s = 0;
  while(x) s += x&1, x>>=1;
  return s;
}

int main(void){
  scanf("%d%s",&n,s);
  LL st = 0, ans=0;
  cnt[0] = 1;
  FOR(i,0,n){
    if(islower(s[i])) s[i] -= 'a';
    else s[i] = s[i]-'A'+26;

    st ^= 1ll<<s[i];
    // for(auto p : cnt) if(len(p.FI ^ st)<=1)
    //   ans += p.SE;
    if(st==0){
      ans += cnt[0];
      FOR(j,0,52) if(cnt.count(1ll<<j)){
        ans += cnt[1ll<<j];
      }
    }else if(len(st)==1){
      ans += cnt[st];
      FOR(j,0,52) if(cnt.count(st ^ (1ll<<j)))
        ans += cnt[st^(1ll<<j)];
      // ans += cnt[0] + cnt[st];
      // FOR(j,0,52) if((st&(1ll<<j))==0 && cnt.count(st|(1ll<<j))){
      //   ans += cnt[st | (1ll<<j)];
      // }
    }else{
      ans += cnt[st];
      FOR(j,0,52) if(cnt.count(st ^ (1ll<<j)))
        ans += cnt[st^(1ll<<j)];
      // ans += cnt[st];
      // FOR(j,0,52){
      //   if(st&(1ll<<j) && cnt.count(st^(1ll<<j))){
      //     ans += cnt[st ^ (1ll<<j)];
      //   }else if((st&(1ll<<j))==0 && cnt.count(st|(1ll<<j))){
      //     ans += cnt[st | (1ll<<j)];
      //   }
      // }
    }
#ifdef DEBUG
    printf("  ans: %lld\n",ans);
    // FOR(i,0,52) printf("%d",(st>>i)&1ll); putchar('\n');
    // printf("  %d mp.size(): %d\n",i,cnt.size());
#endif
    ++cnt[st];
  }
  printf("%lld\n",ans);

  return 0;
}
