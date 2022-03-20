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

const int MAX = 5e4 + 20;
int T, n;
char s[MAX];
bool f[MAX][1<<6];

const int MASK = (1<<6)-1;

vector<int> bad5, bad6;

int bit(int x, int n) {
  return (x>>n)&1;
}

void init() {
  FOR(st,0,1<<5)
    if (bit(st, 0) == bit(st, 4)
        && bit(st, 1) == bit(st, 3))
      bad5.pb(st);

  FOR(st,0,1<<6)
    if (bit(st, 0) == bit(st, 5)
        && bit(st, 1) == bit(st, 4)
        && bit(st, 2) == bit(st, 3))
      bad6.pb(st);
#ifdef DEBUG
  printf("bad5 (%d)\n", bad5.size());
  printf("bad6 (%d)\n", bad6.size());
#endif
}

bool ok(int st, int len) {
  if (len >= 5) {
    for(int x : bad5)
      if (x == (st & 0x1F))
        return false;
  }

  if (len >= 6) {
    for(int x : bad6)
      if (x == (st & 0x3F))
        return false;
  }

  return true;
}

inline void try0(int i, int st) {
  int nst = (st << 1) & MASK;
  if (ok(nst, i+1))
    f[i+1][nst] = 1;
}

inline void try1(int i, int st) {
  int nst = ((st << 1)|1) & MASK;
  if (ok(nst, i+1))
    f[i+1][nst] = 1;
}

void printBin(int x) {
  for (int i = 5; i >= 0; --i)
    putchar(((x>>i)&1) ? '1' : '0');
}

int main(void){
  init();

  scanf("%d",&T);
  FORR(kase,1,T) {
    MST(f, 0);
    scanf("%d%s", &n, s+1);

    printf("Case #%d: ", kase);
    if (n <= 4) {
      printf("POSSIBLE\n");
      continue;
    }

    f[0][0] = 1;
    FORR(i,0,n-1) FOR(st,0,1<<6) if (f[i][st]) {
      if (s[i+1] == '0') {
        try0(i, st);
      } else if (s[i+1] == '1') {
        try1(i, st);
      } else {
        try0(i, st);
        try1(i, st);
      }
    }

#ifdef DEBUG
    FORR(i,0,n) FOR(st,0,1<<6) if (f[i][st]) {
      printf("f[%d][", i);
      printBin(st);
      printf("] (%d)\n", st);
    }
#endif

    bool ok = 0;
    FOR(st, 0, 1<<6) if (f[n][st]) {
      ok = 1; break;
    }
    printf("%s\n", ok ? "POSSIBLE" : "IMPOSSIBLE");
  }

  return 0;
}
