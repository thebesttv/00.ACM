// Tag: 线段树 iii
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

const int MAX = 2000020;
const int INF = 0x3f3f3f3f;
int n,m;

struct ST{
  int vmin[MAX<<2],vmax[MAX<<2];

  void mini(int u, int h){
    vmin[u] = min(vmin[u], h);
    vmax[u] = min(vmax[u], h);
  }
  void maxi(int u, int h){
    vmin[u] = max(vmin[u], h);
    vmax[u] = max(vmax[u], h);
  }

  void pushdown(int u){
    mini(u<<1, vmin[u]);
    mini(u<<1|1, vmin[u]);
    maxi(u<<1, vmax[u]);
    maxi(u<<1|1, vmax[u]);
    vmin[u] = INF, vmax[u] = 0;
  }

  void build(){
    build(1,1,n);
  }
  void build(int u, int l, int r){
    vmin[u] = INF, vmax[u] = 0;
    if(l == r) return;
    int m = (l+r)/2;
    build(u<<1,l,m);
    build(u<<1|1,m+1,r);
  }

  void mini(int l, int r, int val){
    mini(1,1,n,l,r,val);
  }
  void mini(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      mini(u, val); return;
    }
    int m = (cl+cr)/2; pushdown(u);
    if(ql <= m) mini(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) mini(u<<1|1, m+1, cr, ql, qr, val);
  }

  void maxi(int l, int r, int val){
    maxi(1,1,n,l,r,val);
  }
  void maxi(int u, int cl, int cr, int ql, int qr, int val){
    if(ql <= cl && cr <= qr){
      maxi(u, val); return;
    }
    int m = (cl+cr)/2; pushdown(u);
    if(ql <= m) maxi(u<<1, cl, m, ql, qr, val);
    if(m+1 <= qr) maxi(u<<1|1, m+1, cr, ql, qr, val);
  }

  void dprint(){
    dprint(1,1,n); putchar('\n');
  }
  void dprint(int u, int l, int r){
    if(l == r) { printf("%d ",vmax[u]); return; }
    int m = (l+r)/2; pushdown(u);
    dprint(u<<1, l, m);
    dprint(u<<1|1, m+1, r);
  }
  void print(){
    print(1,1,n);
  }
  void print(int u, int l, int r){
    if(l == r) { printf("%d\n",vmax[u]); return; }
    int m = (l+r)/2; pushdown(u);
    print(u<<1, l, m);
    print(u<<1|1, m+1, r);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m); sg.build();
  while(m--){
    int op,l,r,h; scanf("%d%d%d%d",&op,&l,&r,&h);
    if(op == 1) sg.maxi(l+1,r+1,h);
    else sg.mini(l+1,r+1,h);
#ifdef DEBUG
    sg.dprint();
#endif
  }
  sg.print();

  return 0;
}
