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

const int MAX = 400020;
int n,m,p[MAX],p2[MAX],c[MAX],c2[MAX],lcp[MAX];
char s[MAX]; pii v[MAX];

int cnt[MAX], pos[MAX];
void count_sort(){
  MST(cnt,0); FOR(i,0,n) ++cnt[c[i]];
  pos[0] = 0;
  FOR(i,1,n) pos[i] = pos[i-1] + cnt[i-1];
  FOR(i,0,n) p2[pos[c[p[i]]]++] = p[i];
  memcpy(p,p2,sizeof(p));
}

void build(){
  FOR(i,0,n) v[i] = {s[i], i};
  sort(v,v+n);
  p[0] = v[0].SE; c[p[0]] = 0;
  FOR(i,1,n){
    p[i] = v[i].SE;
    if(v[i].FI == v[i-1].FI)
      c[p[i]] = c[p[i-1]];
    else
      c[p[i]] = c[p[i-1]] + 1;
  }

  for(int k = 0; (1<<k) < n; ++k){
    FOR(i,0,n) p[i] = (p[i] - (1<<k) + n)%n;
    count_sort();

    c2[p[0]] = 0;
    FOR(i,1,n){
      pii cur = {c[p[i]], c[(p[i] + (1<<k))%n]};
      pii prev = {c[p[i-1]], c[(p[i-1] + (1<<k))%n]};
      if(cur == prev)
        c2[p[i]] = c2[p[i-1]];
      else
        c2[p[i]] = c2[p[i-1]] + 1;
    }
    memcpy(c,c2,sizeof(c));
  }
}

struct ST{
  int f[MAX][20];
  void build(int *v, int n){
    FORR(i,1,n) f[i][0] = v[i];
    ROR(i,n,1) for(int j = 1; i + (1<<j) - 1 <= n; ++j)
      f[i][j] = min(f[i][j-1], f[i + (1<<(j-1))][j-1]);
  }
  int qMin(int l, int r){
    int k = log(r-l+1) / log(2);
    return min(f[l][k], f[r - (1<<k) + 1][k]);
  }
}sg;

int cal(int i, int j){
  i = c[i], j = c[j];
  if(i == j) return n - p[i];
  if(i > j) swap(i,j);
  return sg.qMin(i+1,j);
}

struct Node{
  int l, r, len;
  bool operator < (const Node &b) const {
    int x = cal(l, b.l);
#ifdef DEBUG
    printf("lcp(%d,%d): %d\n",l,b.l,x);
#endif
    if(len <= x || b.len <= x){
      if(len == b.len) return l != b.l ? l < b.l : r < b.r;
      else return len < b.len;
    }else{
      return c[l] < c[b.l];
    }
  }
}node[MAX];

int main(void){
  scanf("%s", s); n = strlen(s);
  s[n++] = char(32); s[n] = 0;
  build();

  int k = 0;
  FOR(i,0,n-1){
    int pi = c[i], j = p[pi - 1];
    while(s[i+k] == s[j+k]) ++k;
    lcp[pi] = k; if(k) --k;
  }

  sg.build(lcp, n-1);

  scanf("%d",&m);
  FOR(i,0,m){
    Node &t = node[i];
    scanf("%d%d",&t.l,&t.r);
    --t.l, --t.r; t.len = t.r - t.l + 1;
  }
  sort(node,node+m);
  FOR(i,0,m) printf("%d %d\n",node[i].l+1,node[i].r+1);

  return 0;
}