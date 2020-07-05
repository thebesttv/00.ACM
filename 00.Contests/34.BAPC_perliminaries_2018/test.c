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

const int MAX = 5e5 + 20;
int n,m,p[MAX],l[MAX],v[MAX<<2];

bool ok(int len){
#ifdef DEBUG
  printf("  trying len: %d\n",len);
#endif
  LL sum = 0;
  FOR(i,0,n){
    int idx = lower_bound(p+i,p+n,p[i]+len) - p;
    if(idx >= n) idx = n-1;
    while(p[idx] > p[i] + len) --idx;
    sum += idx - i;
#ifdef DEBUG
    printf("    (%d, %d), sum: %d\n",i,idx,sum);
#endif
    if(sum >= m) return true;
  }
  return false;
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%d",&p[i]);
  FOR(i,0,m) scanf("%d",&l[i]);
  sort(l,l+m);
  if(1ll*n*(n-1)/2 < m){
    printf("no\n"); return 0;
  }

  int ql = 0, qr = p[n-1]-p[0];
  while(ql < qr){
    int mid = (ql+qr)/2;
    if(ok(mid)) qr = mid;
    else ql = mid+1;
  }
#ifdef DEBUG
  printf("  len: %d\n",ql);
#endif

  int tail = 0;
  FOR(i,0,n) FOR(j,i+1,n){
    if(p[j]-p[i] > ql) break;
    v[tail++] = p[j]-p[i];
  }
  sort(v,v+tail);
  FOR(i,0,m) if(v[i] > l[i]){
    printf("no\n"); return 0;
  }
  printf("yes\n");
  return 0;
}

/*
const int MAX = 5e5 + 20;
int n,m,p[MAX],l[MAX],v[MAX];

int main(void){
  scanf("%d%d",&n,&m);
  if(1ll*n*(n-1)/2 < m){
    printf("no\n"); return 0;
  }
  FOR(i,0,n) scanf("%d",&p[i]);
  FOR(i,0,m) scanf("%d",&l[i]);
  sort(l,l+m);

  int pos = 0;
  FOR(len,1,n){
    int head = 0, tail = 0;
    for(int i=0;i+len<n;++i)
      v[tail++] = p[i+len] - p[i];
    sort(v,v+tail);

    while(pos < m){
      while(head < tail && v[head] < l[pos]) ++head;
      if(head >= tail) break;
      ++head, ++pos;
    }
    if(pos >= m) break;
  }
  printf("%s\n", pos >= m ? "yes" : "no");

  return 0;
}
*/
