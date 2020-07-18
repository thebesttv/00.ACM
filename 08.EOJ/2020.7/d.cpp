// Tag: 哈希 字符串 iiiii why
// Link: [NOIp 1998 提高组 拼数 - Luogu 1012]
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

const int MAX = 1e5 + 20;
const LL MOD = 998244353;
int n,v[MAX]; char s[MAX];
LL p[MAX],f[MAX];

LL h(int l, int r){
  return (f[r] - f[l-1] * p[r-l+1] % MOD + MOD)%MOD;
}

bool cmp(int a, int b){
  if(a == b) return 0;
  int l1, r1, l2, r2; bool swapped = 0;
  if(a > b) swap(a, b), swapped = 1;
  l1 = 1, r1 = b-a, l2 = a+1, r2 = b;
  if(h(l1,r1) == h(l2,r2)){
    l1 = b-a+1, r1 = b, l2 = 1, r2 = a;
    if(h(l1,r1) == h(l2,r2)) return 0;
  }
  int l = 0, r = r1-l1;
  while(l < r){
    int m = (l+r)/2;
    if(h(l1,l1+m) == h(l2, l2+m)) l = m+1;
    else r = m;
  }
  return swapped ? s[l1+l] < s[l2+l] : s[l1+l] > s[l2+l];
}

int main(void){
  scanf("%s",s+1); n = strlen(s+1);
  p[0] = 1;
  FORR(i,1,n){
    p[i] = p[i-1] * 10 % MOD;
    f[i] = (f[i-1]*10 + s[i]-'0') % MOD;
    v[i] = i;
  }

  sort(v+1,v+1+n,cmp);
#ifdef DEBUG
  FORR(i,1,n) printf("%d ",v[i]); putchar('\n');
#endif

  LL ans = 0, t = 1;
  FORR(i,1,n){
    ans = (ans*p[v[i]]%MOD + f[v[i]])%MOD;
  }
  printf("%lld\n",ans);

  return 0;
}
