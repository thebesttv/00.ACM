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

const int MAX = 200020;
const int INF = 0x3f3f3f3f;
int n,k,a[MAX]; bool bad[MAX];
VR<int> pos[MAX];
struct Node{
  int n,pos;
  bool operator < (const Node &b) const {
    return pos > b.pos;
  }
};
PQ<Node> q;

struct ST{
  int v[MAX<<2];
  void build(int *a, int u, int l, int r){
    if(l==r){
      v[u] = a[l];
      return;
    }
    int m = (l+r)>>1;
    build(a,u<<1,l,m);
    build(a,u<<1|1,m+1,r);
    v[u] = min(v[u<<1], v[u<<1|1]);
  }

  /*
  void fix(int u, int l, int r){
    if(v[u] == INF || !bad[v[u]]) return;
    if(l==r) { v[u] = INF; return; }

    int m = (l+r)>>1;
    fix(u<<1,l,m);
    fix(u<<1|1,m+1,r);
    v[u] = min(v[u<<1], v[u<<1|1]);
  }

  int qMin(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return v[u];
    }

    int m = (cl+cr)>>1, ans = INF;
    if(ql<=m) ans = min(ans, qMin(u<<1,cl,m,ql,qr));
    if(qr>=m+1) ans = min(ans, qMin(u<<1|1,m+1,cr,ql,qr));
    return ans;
  }
  */
  int qMin(int u, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr && !bad[v[u]]){
      return v[u];
    }
    if(cl == cr) return INF;

    int m = (cl+cr)>>1, ans = INF;
    if(ql<=m) ans = min(ans, qMin(u<<1,cl,m,ql,qr));
    if(qr>=m+1) ans = min(ans, qMin(u<<1|1,m+1,cr,ql,qr));
    return ans;
  }
}sg;

int main(void){
  scanf("%d%d",&n,&k);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    pos[a[i]].push_back(i);
  }
  FORR(i,1,k) q.push({i,pos[i].back()});
  sg.build(a,1,1,n);

  int l = 1, r;
  FORR(i,1,k){
    r = q.top().pos;
    int tMin = sg.qMin(1,1,n,l,r);
    int p = lower_bound(ALL(pos[tMin]), l) - pos[tMin].begin();
#ifdef DEBUG
    printf("  l: %d, r: %d, tMin: %d, p: %d\n",l,r,tMin,p);
#endif
    printf("%d ",tMin);
    l = pos[tMin][p] + 1; bad[tMin] = 1;
    while(!q.empty() && bad[q.top().n])
      q.pop();
#ifdef DEBUG
    printf("  size: %d\n",q.size());
#endif
    // sg.fix(1,1,n);
  }
  putchar('\n');

  return 0;
}

/*
const int MAX = 200020;
int n,k,x; deque<int> pos[MAX];
struct Node{
  int n; deque<int> *pos;
  bool operator < (const Node &b) const {
    return pos->front() > b.pos->front();
  }
}; PQ<Node> q;
struct Node2{
  int n, last;
  bool operator < (const Node &b) const {
    return last > b.last;
  }
}; PQ<Node2> lq;
bool bad[MAX];

int main(void){
  scanf("%d%d",&n,&k);

  FORR(i,1,n){
    scanf("%d",&x);
    pos[x].push_back(i);
  }

  FORR(i,1,k){
    q.push({i, pos+i});
    lq.push({i,pos[i].back()});
  }

  FORR(i,1,k){
    int tMin = k+1, r = -1;
    while(!q.empty()){
      auto p = q.top();
      if(p.pos->front() > lq.top())
        break;
      q.pop();
      if(tMin < p.pos
    }
  }

  return 0;
}
*/
