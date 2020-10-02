// Tag: 二分
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
int n; LL k, a[MAX], b[MAX];

LL count(LL x){
  LL sum = 0;
#ifdef DEBUG
  printf("count(%lld):\n",x);
#endif
  FORR(i,1,n){
    if(a[i] + b[1] > x) break;
    int j = upper_bound(b+1,b+1+n,x-a[i]) - b;
    while(j > n || a[i] + b[j] > x) --j;
    sum += j;
#ifdef DEBUG
    printf("  a[%d]: %lld, j: %d\n",i,a[i],j);
#endif
  }
  return sum;
}

int main(void){
  scanf("%d%lld",&n,&k);
  FORR(i,1,n) a[i] = read();
  FORR(i,1,n) b[i] = read();
  sort(a+1,a+1+n), sort(b+1,b+1+n);
  LL l = 1, r = 2e9;
  while(l < r){
    LL m = (l+r)/2;
    if(count(m) >= k) r = m;
    else l = m+1;
  }
  printf("%lld\n",l);

  return 0;
}

