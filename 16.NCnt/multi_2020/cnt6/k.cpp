// Tag: DP 哈希 iiii TODO
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
#include<unordered_set>
#include<unordered_map>
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

int read(){
  int sum = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) sum = sum * 10 + ch-'0', ch=getchar();
  return sum;
}

const int MOD = 104729;
const int MAX = 5e5 + 20;
int n,k,a[MAX]; bool f[MAX];
unordered_set<int> st;
VR<int> v[MOD];

const int SZ = 611953;
struct hash_map {  // 哈希表模板
  struct data {
    long long u; int v, nex;
  };                // 前向星结构
  data e[SZ << 1];  // SZ 是 const int 表示大小
  int h[SZ], cnt;
  int hash(long long u) { return u % SZ; }
  int& operator[](long long u) {
    int hu = hash(u);  // 获取头指针
    for (int i = h[hu]; i; i = e[i].nex)
      if (e[i].u == u) return e[i].v;
    return e[++cnt] = (data){u, 0, h[hu]}, h[hu] = cnt, e[cnt].v;
  }

  hash_map() { cnt = 0; memset(h, 0, sizeof(h)); }
  void clear() { cnt = 0; memset(h, 0, sizeof(h)); }
}mp;

int main(void){
  int T = read();
  while(T--){
    mp.clear();

    bool bad = false;
    n = read(), k = read();
    FORR(i,1,n) a[i] = read(), bad = bad || (a[i] > k);
    if(bad) { printf("NO\n"); continue; }

    int cnt = 0; f[0] = true;
    FORR(i,1,min(n,k)){
      int &x = mp[a[i]]; ++x;
      if(x == 1) ++cnt, f[i] = f[i-1];
      else{
        if(x == 2) --cnt;
        f[i] = 0;
      }
    }

    FORR(i,k+1,n){
      int &y = mp[a[i-k]]; --y;
      if(y == 1) ++cnt;
      else if(y == 0) --cnt;

      int &x = mp[a[i]]; ++x;
      if(x == 1) ++cnt;
      else if(x == 2) --cnt;

#ifdef DEBUG
      printf("  i: %d, cnt: %d\n",i,cnt);
#endif

      f[i] = f[i-k] && (cnt == k);

    }
#ifdef DEBUG
    FORR(i,1,n) printf("f[%d]: %d\n",i,f[i]);
#endif

    bool ok = 0; mp.clear();
    ROR(i,n,1){
      if(f[i]) { ok = 1; break; }
      if(++mp[a[i]] > 1) break;
    }
    printf("%s\n", ok ? "YES" : "NO");
  }

  return 0;
}
