// Tag: 二分 范围 ii
// 使用 l <= r, l = m+1, r = m-1, 记录 ans 版更好
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return s;
}

int nread(){
  int s = 0, ch, neg = 0;
  do ch = getchar(), neg |= (ch == '-'); while(!isdigit(ch));
  while(isdigit(ch)) s = s*10 + ch-'0', ch = getchar();
  return neg ? -s : s;
}

const int MAX = 1e5 + 20;
int n,a[MAX]; LL k;

LL count(LL x){
  LL cnt = 0, sum = 0;
  FORR(i,1,n){
    sum = max(0ll, sum + a[i]);
    if(sum >= x) ++cnt, sum = 0;
  }
#ifdef DEBUG
  if(x <= 100) printf("count(%lld): %lld\n",x,cnt);
#endif
  return cnt;
}

// l <= r, l = m+1, r = m-1, 记录 ans 版
LL getMax(){
  LL l = 1, r = 1e14, ans = -1;
  while(l <= r){
    LL m = (l+r)/2, c = count(m);
    if(c == k) ans = m, l = m+1;
    else if(c > k) l = m+1;
    else r = m-1;
  }
  return ans;
}

LL getMin(){
  LL l = 1, r = 1e14, ans = -1;
  while(l <= r){
    LL m = (l+r)/2, c = count(m);
    if(c == k) ans = m, r = m-1;
    else if(c > k) l = m+1;
    else r = m-1;
  }
  return ans;
}

/*
// l < r 版
LL getMax(){
  LL l = 1, r = 1e14;
  while(l < r){
    LL m = (l+r+1)/2;
    if(count(m) >= k) l = m;
    else r = m-1;
  }
  if(count(l) != k) return -1;
  return l;
}

LL getMin(){
  LL l = 1, r = 1e14;
  while(l < r){
    LL m = (l+r)/2;
    if(count(m) <= k) r = m;
    else l = m+1;
  }
  if(count(l) != k) return -1;
  return l;
}
*/

int main(void){
  scanf("%d%lld",&n,&k);
  FORR(i,1,n) scanf("%d",&a[i]);
  LL aMax = getMax(), aMin = getMin();
  if(aMax == -1 || aMin == -1)
    printf("-1\n");
  else
    printf("%lld %lld\n",aMin, aMax);

  return 0;
}

