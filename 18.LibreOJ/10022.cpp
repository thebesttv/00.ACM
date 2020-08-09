// Tag: 迭代加深搜索
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 1e5 + 20;
LL a,b,v[MAX],r[MAX]; int dMax;

LL gcd(LL a, LL b){
  return !b ? a : gcd(b,a%b);
}
void simplify(LL &x, LL &y){
  LL g = gcd(x,y); x /= g, y /= g;
}

int cmp(LL xa, LL xb, LL ya, LL yb){ // compares xa / xb & ya / yb
  LL d = xa * yb - ya * xb;
  return d > 0 ? 1 : (d < 0 ? -1 : 0);
}

int cal(int a, int b){  // first 1/x <= a/b
  FORR(i,1,b) if(cmp(1,i,a,b) <= 0)
    return i;
  return -1;
}

bool ok(LL x, LL y, int i, int n){  // make sure x/y + n/i >= a/b
  LL tx = x*i + y*n, ty = y*i; simplify(tx,ty);
  return cmp(tx, ty, a, b) >= 0;
}

void dfs(int cur, int last, LL x, LL y){  // current x / y
  if(cur == dMax){
    LL ta = a*y - b*x, tb = b*y; simplify(ta, tb);
    if(ta != 1 || tb <= last || (r[cur] && tb >= r[cur])) return;
    FOR(i,1,cur) r[i] = v[i];
    r[cur] = tb;
#ifdef DEBUG
    printf("get:"); FORR(i,1,cur) printf(" %lld",r[i]); putchar('\n');
#endif
    return;
  }

  for(int i = last+1; ok(x, y, i, dMax - cur+1) ;++i){
    LL tx = x*i + y, ty = y*i; simplify(tx,ty);
    if(cmp(tx,ty,a,b) > 0) continue;
    v[cur] = i; dfs(cur+1, i, tx, ty);
  }
}

int main(void){
  scanf("%lld%lld",&a,&b); int st = cal(a,b);
#ifdef DEBUG
  printf("  st: %d\n",st);
#endif
  for(dMax = 1;r[1]==0;++dMax){
    dfs(1, st-1, 0, 1);
  }

  for(int i=1;r[i];++i) printf("%lld ",r[i]);
  putchar('\n');

  return 0;
}
