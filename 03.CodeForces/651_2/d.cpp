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

const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f;
int n,k,a[MAX];

bool ok(int t, int cur){
  int cnt = 0;
  FOR(i,0,n){
    if(!cur){
      if(a[i] <= t) ++cnt, cur^=1;
    }else{
      ++cnt, cur^=1;
    }
  }
  return cnt >= k;
}

int main(void){
  scanf("%d%d",&n,&k);
  FOR(i,0,n) scanf("%d",&a[i]);
  int l = 1, r = 1e9;
  while(l<r){
    int m = (l+r)/2;
    if(ok(m,0) || ok(m,1)) r = m;
    else l = m+1;
  }
  printf("%d\n",l);

  return 0;
}

/*
const int MAX = 2e5 + 20;
const int INF = 0x3f3f3f3f;
int n, k, a[MAX];

bool ok(int l, int r, int k, int t){
  int cnt = 0;
  FORR(i,l,r) if(a[i] <= t){
    ++cnt; ++i;
  }
  return cnt >= k;
}

int getMin(int ql, int qr, int k){
  int l = 1, r = 1e9;
  while(l < r){
    int m = (l+r)/2;
    if(ok(ql,qr,k,m)) r = m;
    else l = m+1;
  }
  return l;
}

int main(void){
  scanf("%d%d",&n,&k);
  FORR(i,1,n) scanf("%d",&a[i]);

  int ansMin = 0x3f3f3f3f;
  if(k == n){
    int oMax = 0, eMax = 0;
    FORR(i,1,n)
      if(i&1) oMax = max(oMax, a[i]);
      else eMax = max(eMax, a[i]);
    ansMin = min(oMax, eMax);
  }else if(k & 1){
    ansMin = min(getMin(1,n,(k+1)/2), getMin(2,n-1,k/2));
  }else{
    ansMin = min(getMin(1,n-1,k/2), getMin(2,n,k/2));
  }
  printf("%d\n",ansMin);

  return 0;
}
*/
