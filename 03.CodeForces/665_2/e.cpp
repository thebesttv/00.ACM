// Tag: quadtree 线段树 TODO
// 不会线段树的做法……
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
const int RNG = 1e6;  // coordinate range
const int CAP = 10;   // capacity of each node

int read(){
  int s = 0, ch;
  do ch = getchar(); while(!isdigit(ch));
  while(isdigit(ch)) s=s*10 + ch-'0', ch = getchar();
  return s;
}

struct QuadTree{
  // n: # of node, x,y: for add & remove, x1,y1,x2,y2: for query
  int n, x, y, x1, y1, x2, y2;
  struct Node{
    int sum, next[4];
    bool divided;
    VR<pair<pii,int>> v;
    // ^
    // | 1 | 3
    // | 0 | 2
    // +------->
  }node[MAX<<2];  // root: node[0]

  inline bool within(int x, int y, int l1, int r1, int l2, int r2){
    return l1 <= x && x <= r1 && l2 <= y && y <= r2;
  }

  void divide(Node &u, int l1, int r1, int l2, int r2){
    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
#ifdef DEBUG
    printf("  divide\n");
#endif
    FOR(i,0,4) u.next[i] = ++n; // add 4 child nodes
    for(auto p : u.v){  // place all points in child nodes
      if(within(p.FI.FI, p.FI.SE, l1, m1, l2, m2))
        node[u.next[0]].v.push_back(p),
        node[u.next[0]].sum += p.SE;
      else if(within(p.FI.FI, p.FI.SE, l1, m1, m2+1, r2))
        node[u.next[1]].v.push_back(p),
        node[u.next[1]].sum += p.SE;
      else if(within(p.FI.FI, p.FI.SE, m1+1, r1, l2, m2))
        node[u.next[2]].v.push_back(p),
        node[u.next[2]].sum += p.SE;
      else
        node[u.next[3]].v.push_back(p),
        node[u.next[3]].sum += p.SE;
    }
    u.v.clear(); u.divided = true;
  }

  void add(int x, int y, int v){
    this->x = x, this->y = y;
#ifdef DEBUG
    printf("add(%d, %d)\n",x,y);
#endif
    add(node[0], 0, RNG, 0, RNG, v);
  }
  void add(Node &u, int l1, int r1, int l2, int r2, int v){
    u.sum += v;

    if(!u.divided){ // leaf
      u.v.push_back({{x,y},v});
      if(u.v.size() > CAP) divide(u, l1, r1, l2, r2); // too many points
      return;
    }

    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
    if(within(x, y, l1, m1, l2, m2))
      add(node[u.next[0]], l1, m1, l2, m2, v);
    else if(within(x, y, l1, m1, m2+1, r2))
      add(node[u.next[1]], l1, m1, m2+1, r2, v);
    else if(within(x, y, m1+1, r1, l2, m2))
      add(node[u.next[2]], m1+1, r1, l2, m2, v);
    else
      add(node[u.next[3]], m1+1, r1, m2+1, r2, v);
  }

  // for rectangles (x1,y1)-(x2,y2)
  bool intersect(int l1, int r1, int l2, int r2){
    return l1 <= x2 && r1 >= x1 && l2 <= y2 && r2 >= y1;
  }
  bool within(int l1, int r1, int l2, int r2){  // current rectangle within target rectangle
    return x1 <= l1 && r1 <= x2 && y1 <= l2 && r2 <= y2;
  }

  int query(int x1, int y1, int x2, int y2){
#ifdef DEBUG
    printf("query(%d, %d, %d, %d)\n",x1,y1,x2,y2);
#endif
    this->x1 = x1, this->y1 = y1;
    this->x2 = x2, this->y2 = y2;
    return query(node[0], 0, RNG, 0, RNG);
  }

  int query(Node &u, int l1, int r1, int l2, int r2){
    if(within(l1, r1, l2, r2)) return u.sum;
    if(!u.divided){
      int sum = 0;
      for(auto p : u.v)
        if(within(p.FI.FI, p.FI.SE, x1, x2, y1, y2))
          sum += p.SE;
      return sum;
    }

    int m1 = (l1+r1)/2, m2 = (l2+r2)/2, sum = 0;
    if(intersect(l1, m1, l2, m2))
      sum += query(node[u.next[0]], l1, m1, l2, m2);
    if(intersect(l1, m1, m2+1, r2))
      sum += query(node[u.next[1]], l1, m1, m2+1, r2);
    if(intersect(m1+1, r1, l2, m2))
      sum += query(node[u.next[2]], m1+1, r1, l2, m2);
    if(intersect(m1+1, r1, m2+1, r2))
      sum += query(node[u.next[3]], m1+1, r1, m2+1, r2);
    return sum;
  }
}qt;

int n,m;

int main(void){
  n = read(), m = read();
  LL ans = 1;
  while(n--){
    int y = read(),xl = read(),xr = read();
    if(xl == 0 && xr == RNG) ++ans;
    qt.add(xl, y, 1);
    if(xr < RNG) qt.add(xr+1, y, -1);
  }
  while(m--){
    int x = read(),yl = read(),yr = read();
    if(yl == 0 && yr == RNG) ++ans;
    ans += qt.query(0,yl,x,yr);
  }
  printf("%lld\n",ans);

  return 0;
}
