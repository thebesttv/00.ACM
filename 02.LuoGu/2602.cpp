// Tag: 数位DP
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

LL l,r,cnt1[10],cnt2[10];
LL v[20],f[20][20];

LL dfs(int cur, int cnt, int target, bool limited, bool lead){
  if(!cur) return cnt;
  LL &a = f[cur][cnt];
  if(!limited && !lead && a != -1) return a;
  int r = limited ? v[cur] : 9; LL sum = 0;
  FORR(i,0,r){
    // sum += dfs(cur-1, cnt + (i==target && (i!=0 || (i==0 && !lead))),
    //     target, limited && i == v[cur], lead && !i);
    sum += dfs(cur-1, cnt + (i==target && (i!=0 || !lead)),
        target, limited && i == v[cur], lead && !i);
  }
  if(!limited && !lead) a = sum;
  return sum;
}

void solve(LL x, LL *cnt){
  int len = 0;
  while(x) v[++len] = x%10, x/=10;
  FORR(i,0,9){
    MST(f,-1);
    cnt[i] = dfs(len, 0, i, true, true);
  }
}

int main(void){
  scanf("%lld%lld",&l,&r);
  solve(r,cnt1); solve(l-1,cnt2);
#ifdef DEBUG
  printf("cnt1:"); FORR(i,0,9) printf(" %lld",cnt1[i]); putchar('\n');
  printf("cnt2:"); FORR(i,0,9) printf(" %lld",cnt2[i]); putchar('\n');
#endif
  FORR(i,0,9) printf("%lld ",cnt1[i] - cnt2[i]);
  putchar('\n');

  return 0;
}
