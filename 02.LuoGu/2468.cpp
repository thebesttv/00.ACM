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

const int MAXH = 5e5 + 4, MAXN = 1000 + 4;
int n,m,q; VR<int> col[MAXN];
int f[202][202][1004];

inline int idx(int x, int y){
  return (x-1) * m + y;
}

struct ST{
  int n;
  struct Node{
    int sum;
    Node *l, *r;
    Node() { sum = 0, l = r = nullptr; }
  }*head[MAXH], *cur[MAXN<<2], *zero;

  void init(int r){
    zero = new Node;
    zero->l = zero->r = zero;
    FORR(i,0,r) head[i] = zero;
    FORR(i,0,4000) cur[i] = zero;
  }
  void clear() { FORR(i,0,4000) cur[i] = zero; }

  void insert(int x, int y, VR<int>::iterator beg, VR<int>::iterator end){
    head[idx(x,y)] = insert(1, 1, n, beg, end);
  }
  Node *insert(int u, int l, int r, VR<int>::iterator beg, VR<int>::iterator end){
    Node *p = new Node;
    if(l == r){
      p->sum = cur[u]->sum;
      for(auto it = beg; it != end; ++it){
        p->sum += l;
      }
      return cur[u] = p;
    }

    int m = (l + r)/2;
    auto it = upper_bound(beg, end, m);

    if(it != beg) p->l = insert(u<<1, l, m, beg, it);
    else p->l = cur[u<<1];

    if(it != end) p->r = insert(u<<1|1, m+1, r, it, end);
    else p->r = cur[u<<1|1];

    p->sum = p->l->sum + p->r->sum;
    return cur[u] = p;
  }

  int query(int x1, int y1, int x2, int y2, int h){
    Node *u1 = (x1==1 || y1==1) ? zero : head[idx(x1-1, y1-1)];
    Node *u2 = x1==1 ? zero : head[idx(x1-1, y2)];
    Node *u3 = y1==1 ? zero : head[idx(x2, y1-1)];
    Node *u4 = head[idx(x2,y2)];

    int sum = u4->sum - u3->sum - u2->sum + u1->sum;
    if(sum < h) return -1;
    return query(u1, u2, u3, u4, 1, n, h);
  }

  int query(Node *u1, Node *u2, Node *u3, Node *u4, int l, int r, int h){
    if(l == r){
      return h%l==0 ? h/l : h/l+1;
    }

    int m = (l+r)/2, ans = 0;
    int rsum = u4->r->sum - u3->r->sum - u2->r->sum + u1->r->sum;
    if(rsum) ans = query(u1->r, u2->r, u3->r, u4->r, m+1, r, min(h, rsum));
    if(h > rsum) ans += query(u1->l, u2->l, u3->l, u4->l, l, m, h-rsum);
    return ans;
  }
}sg;

int main(void){
  scanf("%d%d%d",&n,&m,&q);
  if(n <= 200 && m <= 200){
    int x;
    FORR(i,1,n) FORR(j,1,m){
      scanf("%d",&x);
      FORR(k,1,1000) f[i][j][k] = f[i-1][j][k] + f[i][j-1][k] - f[i-1][j-1][k];
      f[i][j][x] ++;
    }

    int x1, y1, x2, y2, h;
    while(q--){
      scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
      int ans = 0;
      ROR(i,1000,1){
        int cnt = f[x2][y2][i] - f[x1-1][y2][i] - f[x2][y1-1][i] + f[x1-1][y1-1][i];
        int d = min(h, cnt * i);
        if(d >= h){
          ans += h%i==0 ? h/i : h/i+1;
          h = 0;
          break;
        }else{
          h -= d; ans += cnt;
        }
      }
      if(h) printf("Poor QLW\n");
      else printf("%d\n",ans);
    }
    return 0;
  }

  sg.n = 1000; int x;
  sg.init(n*m);
  FORR(i,1,n){
    FORR(j,1,m){
      scanf("%d",&x); col[j].push_back(x);
      sort(ALL(col[j]));
      sg.insert(i, j, ALL(col[j]));
    }
    sg.clear();
  }

  int x1, y1, x2, y2, h;
  while(q--){
    scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&h);
    int ans = sg.query(x1, y1, x2, y2, h);
    if(ans==-1) printf("Poor QLW\n");
    else printf("%d\n",ans);
  }

  return 0;
}
