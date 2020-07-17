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
const int RNG = 1e9;
const int CAP = 10;
int n; char s[20];

/*
struct Node{
  int next;     // if not leaf, then next points to its four children
                // else next points to data
  bool divided; // if not divided, then leaf
};

struct Point{
  int x,y,next;
};
*/


struct QuadTree{
  int n, x, y, x1, y1, x2, y2;
  struct Node{
    int sum, next[4];
    bool divided;
    VR<pii> v;
    // 1 | 3
    // 0 | 2
  }node[MAX<<2];

  inline bool within(int x, int y, int l1, int r1, int l2, int r2){
    return l1 <= x && x <= r1 && l2 <= y && y <= r2;
  }

  void divide(Node &u, int l1, int r1, int l2, int r2){
    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
#ifdef DEBUG
    printf("  divide\n");
#endif
    FOR(i,0,4) u.next[i] = ++n;
    for(auto p : u.v){
      if(within(p.FI, p.SE, l1, m1, l2, m2))
        node[u.next[0]].v.push_back(p);
      else if(within(p.FI, p.SE, l1, m1, m2+1, r2))
        node[u.next[1]].v.push_back(p);
      else if(within(p.FI, p.SE, m1+1, r1, l2, m2))
        node[u.next[2]].v.push_back(p);
      else
        node[u.next[3]].v.push_back(p);
    }
    FOR(i,0,4) node[u.next[i]].sum = node[u.next[i]].v.size();
    u.v.clear(); u.divided = true;
  }

  void add(int x, int y){
    this->x = x, this->y = y;
#ifdef DEBUG
    printf("add(%d, %d)\n",x,y);
#endif
    add(node[0], -RNG, RNG, -RNG, RNG);
  }
  void add(Node &u, int l1, int r1, int l2, int r2){
    ++u.sum;

    if(!u.divided){
      u.v.push_back({x,y});
      if(u.v.size() > CAP) divide(u, l1, r1, l2, r2);
      return;
    }

    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
    if(within(x, y, l1, m1, l2, m2))
      add(node[u.next[0]], l1, m1, l2, m2);
    else if(within(x, y, l1, m1, m2+1, r2))
      add(node[u.next[1]], l1, m1, m2+1, r2);
    else if(within(x, y, m1+1, r1, l2, m2))
      add(node[u.next[2]], m1+1, r1, l2, m2);
    else
      add(node[u.next[3]], m1+1, r1, m2+1, r2);
  }


  void remove(int x, int y){
    this->x = x, this->y = y;
#ifdef DEBUG
    printf("remove(%d, %d)\n",x,y);
#endif
    remove(node[0], -RNG, RNG, -RNG, RNG);
  }
  void remove(Node &u, int l1, int r1, int l2, int r2){
    --u.sum;
    if(!u.divided){
      for(auto it = u.v.begin(); it != u.v.end(); ++it)
        if(*it == pii{x,y}){
#ifdef DEBUG
          printf("  removed (%d, %d)\n",it->FI,it->SE);
#endif
          u.v.erase(it); break;
        }
      return;
    }

    int m1 = (l1+r1)/2, m2 = (l2+r2)/2;
    if(within(x, y, l1, m1, l2, m2))
      remove(node[u.next[0]], l1, m1, l2, m2);
    else if(within(x, y, l1, m1, m2+1, r2))
      remove(node[u.next[1]], l1, m1, m2+1, r2);
    else if(within(x, y, m1+1, r1, l2, m2))
      remove(node[u.next[2]], m1+1, r1, l2, m2);
    else
      remove(node[u.next[3]], m1+1, r1, m2+1, r2);
  }

  bool intersect(int l1, int r1, int l2, int r2){
    return l1 <= x2 && r1 >= x1 && l2 <= y2 && r2 >= y1;
  }
  bool within(int l1, int r1, int l2, int r2){
    return x1 <= l1 && r1 <= x2 && y1 <= l2 && r2 <= y2;
  }

  int query(int x1, int y1, int x2, int y2){
    this->x1 = x1, this->y1 = y1;
    this->x2 = x2, this->y2 = y2;
#ifdef DEBUG
    printf("query(%d, %d, %d, %d)\n",x1,y1,x2,y2);
#endif
    return query(node[0], -RNG, RNG, -RNG, RNG);
  }

  int query(Node &u, int l1, int r1, int l2, int r2){
    if(within(l1, r1, l2, r2)) return u.sum;
    if(!u.divided){
      int sum = 0;
      for(auto p : u.v)
        if(within(p.FI, p.SE, x1, x2, y1, y2))
          ++sum;
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

int main(void){
  qt.n = 0; scanf("%d",&n);
  while(n--){
    scanf("%s",s);
    if(s[0] == 'q'){
      int x1, y1, x2, y2;
      scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
      printf("%d\n",qt.query(x1,y1,x2,y2));
    }else{
      int x, y; scanf("%d%d",&x,&y);
      if(s[0] == 'a') qt.add(x,y);
      else qt.remove(x,y);
    }
  }

  return 0;
}
