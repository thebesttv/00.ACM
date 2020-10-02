// Tag: 
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
typedef pair<LL,LL> pii;

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

int n,k; LL l[60],r[60];

LL count(LL x){
  LL s = 0;
  FORR(i,1,n){
    if(l[i] <= x && x <= r[i]){
      s += x - l[i];
    }else if(x > r[i]){
      s += r[i] - l[i] + 1;
    }
  }
  ++s;
#ifdef DEBUG
  printf("count(%lld): %lld\n",x,s);
#endif
  return s;
}

int main(void){
  scanf("%d%d",&n,&k); ++k;
  FORR(i,1,n) scanf("%lld%lld",&l[i],&r[i]);
  LL l = -2e9, r = 2e9;
  while(l < r){
    LL m = (l+r+1)/2;
#ifdef DEBUG
    printf("[%lld, %lld]\n",l,r);
#endif
    if(count(m) <= k) l = m;
    else r = m-1;
  }
  printf("%lld\n",l);

  return 0;
}

