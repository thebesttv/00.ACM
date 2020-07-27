// Tag: 约瑟夫环 二分 iii
// 模拟约瑟夫环，用树状数组二分，使得模拟复杂度降为 nlogn
// 约瑟夫环的转移可能会有多个环，对每个BFS，遍历连通分量
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
int n,m,*a,*a2,a_[MAX],a2_[MAX];
int G[MAX],pos[MAX],b[MAX];
int vis[MAX], color;

struct ST{
  int v[MAX],vold[MAX];
  void backup() { memcpy(vold,v,sizeof(int) * (n+1)); }
  void restore() { memcpy(v,vold,sizeof(int) * (n+1)); }

  void add(int x, int d){
    while(x <= n) v[x] += d, x += x&-x;
  }
  int sum(int x){
    int s = 0;
    while(x) s += v[x], x -= x & -x;
    return s;
  }
  int sum(int l, int r){
    return sum(r) - sum(l-1);
  }
  int next(int x, int k){
    int all = sum(n); k %= all;
    if(!k) k = all;

    int r = sum(x,n), l, st;
    if(k <= r) l = x, r = n + 1, st = x;
    else k -= r, l = 1, r = x, st = 1;

    while(l < r){
      int m = (l+r)/2;
      if(sum(st,m) < k) l = m+1;
      else r = m;
    }
    return l;
  }
}sg;

pii ccPos[MAX];
VR<int> cc[MAX];
void bfs(int u, int c){
  queue<int> q;
  q.push(u); vis[u] = color;
  int cnt = 0;
  while(!q.empty()){
    u = q.front(); q.pop();
    ccPos[u] = {c, cnt++};
    cc[c].push_back(u);
    if(vis[G[u]] != color){
      q.push(G[u]); vis[G[u]] = color;
    }
  }
}

int main(void){
  a = a_, a2 = a2_;

  scanf("%d%d",&n,&m);
  FORR(i,1,n) a[i] = i, sg.add(i,1);
  sg.backup();

  while(m--){
    int k,x; scanf("%d%d",&k,&x);
    if(k == 1) continue;
    sg.restore();

    int i = 1, j;
    FORR(c,1,n){
      j = sg.next(i,k); sg.add(j,-1);
      G[j] = c;
#ifdef DEBUG
      printf("  next(%d) -> %d\n",i,j);
      printf("G[%d]: %d\n",j,c);
#endif
      if(c != n) i = sg.next(j,1);
    }

    ++color; int tail = 0;
    FORR(i,1,n) if(vis[i] != color){
      cc[tail].clear();
      bfs(i,tail);
#ifdef DEBUG
      printf("cc[%d]:",tail); for(int x : cc[tail]) printf(" %d",x); putchar('\n');
#endif
      tail++;
    }

    FORR(i,1,n){
      auto p = ccPos[i];
      int idx = (p.SE + x)%cc[p.FI].size();
      a2[cc[p.FI][idx]] = a[i];
    }
#ifdef DEBUG
    FORR(i,1,n) printf("  a2[%d]: %d\n",i,a2[i]);
#endif
    swap(a,a2);
  }
  FORR(i,1,n) printf("%d ",a[i]); putchar('\n');

  return 0;
}
