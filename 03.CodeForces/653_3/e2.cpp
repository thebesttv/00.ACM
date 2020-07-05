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

const int MAXN = 2e5 + 20, MAXM = 1e4 + 20;
int n,m,k;
struct Node{
  int t,a,b;
}node[MAXN];
deque<int> a,b,c,d,e,sa,sb,sc,se,ans;

struct ST{
  int n,cnt[MAXM<<2],v[MAXM<<2];
  void add(int x){
#ifdef DEBUG
    printf("  add %d\n",x);
#endif
    add(1,1,n,x);
  }
  void add(int u, int l, int r, int x){
    ++cnt[u], v[u] += x;
    if(l == r) return;
    int m = (l+r)/2;
    if(x<=m) add(u<<1,l,m,x);
    else add(u<<1|1,m+1,r,x);
  }
  int qMin(int k){
#ifdef DEBUG
    printf("  qMin(%d): %d\n",k,qMin(1,1,n,k));
#endif
    return qMin(1,1,n,k);
  }
  int qMin(int u, int l, int r, int k){
    if(k >= cnt[u]) return v[u];
    if(l == r) return k * l;
    int m = (l+r)/2, sum = 0;
    sum = qMin(u<<1,l,m,min(k,cnt[u<<1]));
    if(k > cnt[u<<1]) sum += qMin(u<<1|1,m+1,r,k-cnt[u<<1]);
    return sum;
  }
}sg;

void cal(int rec){
  if(rec >= k){
    VR<pii> c, e;
    c.push_back({0,0});
    e.push_back({0,0});
    FORR(i,1,n){
      Node &t = node[i];
      if(t.a && t.b) c.push_back({t.t, i});
      else e.push_back({t.t, i});
    }
    sort(ALL(c)), sort(ALL(e));
    FORR(i,1,rec) ans.push_back(c[i].SE);
    FORR(i,1,m-rec) ans.push_back(e[i].SE);
  } else {
    VR<pii> c, a, b, left;
    a.push_back({0,0}); b.push_back({0,0}); c.push_back({0,0}); left.push_back({0,0});
    FORR(i,1,n){
      Node &t = node[i];
      if(t.a && t.b) c.push_back({t.t, i});
      else if(t.a) a.push_back({t.t, i});
      else if(t.b) b.push_back({t.t, i});
      else left.push_back({t.t, i});
    }
    sort(ALL(a)), sort(ALL(b)), sort(ALL(c));
    FORR(i,1,rec) ans.push_back(c[i].SE);
    FORR(i,1,k-rec) ans.push_back(a[i].SE);
    FORR(i,1,k-rec) ans.push_back(b[i].SE);

    FOR(i,k-rec+1,a.size()) left.push_back(a[i]);
    FOR(i,k-rec+1,b.size()) left.push_back(b[i]);
    sort(ALL(left)); int r = m - 2*k + rec;
    FORR(i,1,r) ans.push_back(left[i].SE);
  }
}

int main(void){
  scanf("%d%d%d",&n,&m,&k); sg.n = 1e4;
  FORR(i,1,n){
    Node &t = node[i];
    scanf("%d%d%d",&t.t,&t.a,&t.b);
    if(t.a && t.b) c.push_back(t.t);
    else{
      if(t.a) a.push_back(t.t);
      else if(t.b) b.push_back(t.t);
      else d.push_back(t.t);
      e.push_back(t.t);
    }
  }
  sort(ALL(a)); sort(ALL(b)); sort(ALL(c)); sort(ALL(d)); sort(ALL(e));
  int na = a.size(), nb = b.size(), nc = c.size(), nd = d.size(), ne = e.size();
  a.push_front(0); b.push_front(0); c.push_front(0); d.push_front(0); e.push_front(0);
  sa = a, sb = b, sc = c, se = e;
  FORR(i,1,na) sa[i] += sa[i-1];
  FORR(i,1,nb) sb[i] += sb[i-1];
  FORR(i,1,nc) sc[i] += sc[i-1];
  FORR(i,1,ne) se[i] += se[i-1];
#ifdef DEBUG
  printf("a:"); FORR(i,1,na) printf(" %d",a[i]); putchar('\n');
  printf("b:"); FORR(i,1,nb) printf(" %d",b[i]); putchar('\n');
  printf("c:"); FORR(i,1,nc) printf(" %d",c[i]); putchar('\n');
  printf("d:"); FORR(i,1,nd) printf(" %d",d[i]); putchar('\n');
  printf("e:"); FORR(i,1,ne) printf(" %d",e[i]); putchar('\n');
#endif

  int ansMin = INT_MAX, rec = -1;
  if(nc >= k) FORR(i,k,min(nc, m)){
    int sum = sc[i];
    if(ne < m-i) sum = INT_MAX;
    else sum += se[m-i];

    if(sum < ansMin){
#ifdef DEBUG
      printf("c: %d, sum: %d\n",i,sum);
#endif
      ansMin = sum, rec = i;
    }
  }

  FORR(i,1,nd) sg.add(d[i]);
  bool first = true;
  FORR(i, max(max(0, 2*k-m), max(k-na,k-nb)), min(nc, k-1)){
    if(first){
      FORR(j,k-i+1,na) sg.add(a[j]);
      FORR(j,k-i+1,nb) sg.add(b[j]);
      first = false;
    }

    int sum = sc[i] + sa[k-i] + sb[k-i];
    if(m-2*k+i > sg.cnt[1]) sum = INT_MAX;
    else sum += sg.qMin(m-2*k+i);
    if(sum < ansMin){
#ifdef DEBUG
      printf("c: %d, sum: %d\n",i,sum);
#endif
      ansMin = sum, rec = i;
    }
    sg.add(a[k-i]); sg.add(b[k-i]);
  }

  if(ansMin == INT_MAX) { printf("-1\n"); return 0; }
  cal(rec);
  printf("%d\n",ansMin);
  for(int x : ans) printf("%d ",x); putchar('\n');

  return 0;
}
