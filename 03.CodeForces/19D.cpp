// Tag: 线段树 树套树 iii
// （好吧其实也不算树套树
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
int n; char s[20];
struct Query{
  int op,x,y; // add: 0, remove: 1, find: 2
}Q[MAX];

VR<int> v;
int ID(int x){
  return lower_bound(ALL(v),x) - v.begin() + 1;
}

struct ST{
  int n,v[MAX<<2]; set<int> st[MAX];
  void add(int x, int y){
#ifdef DEBUG
    printf("  add(%d, %d)\n",x,y);
#endif
    add(1,1,n,x,y);
  }
  void add(int u, int l, int r, int x, int y){
    if(l == r){
      st[x].insert(y); v[u] = *st[x].rbegin();
      return;
    }
    int m = (l+r)/2;
    if(x <= m) add(u<<1,l,m,x,y);
    else add(u<<1|1,m+1,r,x,y);
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
  void remove(int x, int y) {
#ifdef DEBUG
    printf("  remove(%d, %d)\n",x,y);
#endif
    remove(1,1,n,x,y);
  }
  void remove(int u, int l, int r, int x, int y){
    if(l == r){
      st[x].erase(y);
      if(st[x].empty()) v[u] = 0;
      else v[u] = *st[x].rbegin();
      return;
    }
    int m = (l+r)/2;
    if(x <= m) remove(u<<1,l,m,x,y);
    else remove(u<<1|1,m+1,r,x,y);
    v[u] = max(v[u<<1], v[u<<1|1]);
  }
  pii query(int x, int y) {
#ifdef DEBUG
    printf("  query(%d, %d)\n",x,y);
#endif
    return query(1,1,n,x,y);
  }
  pii query(int u, int l, int r, int x, int y){
#ifdef DEBUG
    printf("    query(%d, %d, %d, %d, %d)\n",u,l,r,x,y);
#endif
    if(r <= x || v[u] <= y) return {-1,-1};

    if(l == r){
      auto it = st[l].upper_bound(y);
      if(it == st[l].end()) return {-1,-1};
      return {l,*it};
    }

    int m = (l+r)/2;
    if(m <= x) return query(u<<1|1,m+1,r,x,y);
    pii p = query(u<<1,l,m,x,y);
    if(p.FI != -1) return p;
    return query(u<<1|1,m+1,r,x,y);
  }
}sg;

int main(void){
  scanf("%d",&n); int x,y;
  FOR(i,0,n){
    scanf("%s%d%d",s,&x,&y);
    Q[i] = { s[0]=='a' ? 0 : (s[0]=='r' ? 1 : 2), x, y};
    v.push_back(x);
  }
  sort(ALL(v)), v.erase(unique(ALL(v)), v.end());
  sg.n = v.size();

  FOR(i,0,n){
    Query &q=Q[i]; q.x = ID(q.x);
    if(q.op == 0){
      sg.add(q.x,q.y);
    }else if(q.op == 1){
      sg.remove(q.x,q.y);
    }else{
      auto p = sg.query(q.x,q.y);
      if(p.FI == -1) printf("-1\n");
      else printf("%d %d\n",v[p.FI-1],p.SE);
    }
  }

  return 0;
}
