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
int n, q, cnt[MAX], v[MAX];

int sum(int x){
  int s = 0;
  while(x) s += v[x], x -= x&-x;
  return s;
}

void add(int x, int val){
  while(x<=n){
    v[x] += val, x += x&-x;
  }
}

int main(void){
  scanf("%d%d",&n,&q); int x;
  FOR(i,0,n) scanf("%d",&x), ++cnt[x];
  FORR(i,1,n) if(cnt[i])
    add(i, cnt[i]);

  while(q--){
    scanf("%d",&x);
    if(x > 0){  // add
      ++cnt[x]; add(x,1);
    }else{
      x = -x;
      int l = 1, r = n;
      while(l < r){
        int m = (l+r)/2;
        if(sum(m) >= x)
          r = m;
        else
          l = m+1;
      }
      --cnt[l]; add(l, -1);
#ifdef DEBUG
      printf("  remove %d\n",l);
#endif
    }
  }

  FORR(i,1,n) if(cnt[i]){
    printf("%d\n",i); return 0;
  }
  printf("0\n");

  return 0;
}
