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
#include<numeric>
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

vector<vector<int>> rec[20];

void dfs(int cur, int tot, LL p, int s) {
  static int r[20];
  if (cur == tot) {
    if (p % s) return;
    vector<int> v(tot);
    FOR(i,0,tot) v[i] = r[i];
    rec[tot].push_back(v);
    return;
  }

  FORR(i,cur == 0 ? 1 : r[cur-1],9) {
    r[cur] = i;
    dfs(cur+1, tot, p*i, s+i);
  }
}

int nLen(LL n) {
  int len = 0;
  while (n) ++len, n/=10;
  return len;
}

LL pow(LL a, LL n) {
  // a ^ n
  LL ans = 1;
  while (n--) {
    ans *= a;
  }
  return ans;
}

LL Frac[1000];
LL frac(int n) {
  LL &p = Frac[n];
  if (p != -1) return p;
  p = 1;
  FORR(i,2,n) p *= i;
  return p;
}

LL G[20];
LL g(int len) {
  LL &ans = G[len];
  if (ans != -1) return ans;

  LL s1 = 0, p = frac(len);
  for (const auto &v : rec[len]) {
    map<int, int> mp;
    for (const int x : v) mp[x]++;
    LL div = 1;
    for (const auto &p : mp) div *= frac(p.second);
    s1 += p / div;
  }

  LL s2 = pow(10, len) - pow(10, len-1) - pow(9, len);
#ifdef DEBUG
  printf("  g(%d): s1: %lld, s2: %lld -> %lld\n", len, s1, s2, s1 + s2);
#endif
  return ans = s1 + s2;
}

LL permu(const multiset<int> &st) {
  map<int, int> mp;
  LL p = frac(st.size());
  for (const int x : st) mp[x]++;
  LL div = 1;
  for (const auto &p : mp) div *= frac(p.second);
#ifdef DEBUG
  printf("permute(");
  for (int x : st) printf("%d ",x);
  printf(") -> %lld / %lld\n", p, div);
#endif
  return p / div;
}

LL dfs2(int cur, int len, int *n, const multiset<int> &st) {
  if (cur >= len) return 1;

  LL sum = 0; int last = -1;
  for (auto it = st.begin(); it != st.end(); ++it) {
    if (*it == last) continue;

    if (*it < n[cur]) {
      multiset<int> st2 = st;
      st2.erase(st2.find(*it));
      sum += permu(st2);
    } else if (*it == n[cur]) {
      multiset<int> st2 = st;
      st2.erase(st2.find(*it));
      sum += dfs2(cur+1, len, n, st2);
    } else break;

    last = *it;
  }
#ifdef DEBUG
  printf("  dfs2(%d, %d, {", cur, len);
  for (int x : st) printf("%d ",x);
  printf("}) -> %lld\n", sum);
#endif
  return sum;
}

LL dfs3(int cur, int len, int *n, int cnt) {
#ifdef DEBUG
  printf("dfs3(%d, %d, , %d)\n", cur, len, cnt);
#endif
  if (cur >= len) return cnt > 0;

  LL sum = 0;
  int left = len - cur - 1;
  if (cnt > 0) {
    if (n[cur] > 0) {
      sum += n[cur] * pow(10, left);
    }
  } else {
    if (cur > 0 && n[cur] > 0) {
      sum += pow(10, left);
    }
    if (n[cur] - 1 > 0) {
      sum += (n[cur] - 1) * (pow(10, left) - pow(9, left));
#ifdef DEBUG
      printf("  sum += %d * %lld\n", (n[cur] - 1), (pow(10, left) - pow(9, left)));
#endif
    }
  }
  sum += dfs3(cur+1, len, n, cnt + (n[cur]==0));
  return sum;
}

LL h(int len, LL n, const vector<int> &v) {
  int vec[20];

#ifdef DEBUG
  printf("h(%d, %lld, {", len, n);
  for (int x : v) printf("%d ", x);
  printf("})\n");
#endif
  for (int i = 0; i < len; ++i) {
    vec[len-i-1] = n%10;
    n /= 10;
  }
// #ifdef DEBUG
//   for (int i = 0; i < len; ++i)
//     printf("%d, ", vec[i]);
//   putchar('\n');
// #endif

  multiset<int> st(ALL(v));
  LL ans = dfs2(0, len, vec, st);
#ifdef DEBUG
  printf("-> ans: %lld\n", ans);
#endif
  return ans;
}

LL h2(int len, LL n) {
  int vec[20];

  for (int i = 0; i < len; ++i) {
    vec[len-i-1] = n%10;
    n /= 10;
  }

  LL ans = dfs3(0, len, vec, 0);
#ifdef DEBUG
  printf("dfs3 -> %lld\n", ans);
#endif
  return ans;
}

LL f(LL n) {
  if (n <= 0) return 0;
  int len = nLen(n);
  LL sum = 0;
  FOR(i,1,len) sum += g(i);

  for (const auto &v : rec[len]) {
    sum += h(len, n, v);
  }

  sum += h2(len, n);

  return sum;
}

int main(void){
  MST(G, -1);
  MST(Frac, -1);

  FORR(i,1,13) {
    dfs(0, i, 1, 0);
#ifdef DEBUG
    // printf("rec[%d]: %d\n", i, rec[i].size());
    // if (i <= 2) {
    //   for (auto v : rec[i]) {
    //     for (auto x : v) printf("%d ", x);
    //     putchar('\n');
    //   }
    // }
#endif
  }

  while (1) {
    LL n; cin >> n;
    printf("%lld\n", f(n));
  }

  int T; scanf("%d",&T);
  FORR(kase,1,T) {
    LL a, b; scanf("%lld%lld", &a, &b);
    printf("Case #%d: %lld\n", kase, f(b) - f(a-1));
  }

  return 0;
}
