// Tag: notag
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
int n,k,a[MAX];

bool ok(LL x){
  int cnt = 0; LL sum = 0;
  FORR(i,1,n){
    if(sum + a[i] > x) sum = 0, ++cnt;
    sum += a[i];
  }
  if(sum) ++cnt;
#ifdef DEBUG
  printf("ok(%lld): %lld\n",x,cnt);
#endif
  return cnt <= k;
}

int main(void){
  n = read(), k = read();
  LL l = 0, r = 0;
  FORR(i,1,n){
    a[i] = read();
    l = max(l, (LL)a[i]);
    r += a[i];
  }

  while(l < r){
    LL m = (l+r)/2;
    if(ok(m)) r = m;
    else l = m+1;
  }
  printf("%lld\n",l);

  return 0;
}

