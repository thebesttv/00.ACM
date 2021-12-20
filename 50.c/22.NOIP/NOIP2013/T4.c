#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAX=100020;
const int INF=0x7fffffff;
int cnt=0;
int h[MAX];
struct SegTree{
  int h,n;  //h,n: 区间[l,r]内最低建筑的高及其编号
  int l,r;
}st[MAX<<2];

void dfs(int l, int r, int cur);  //在区间[l,r]内建造，cur为当前高度
void build(int root, int l, int r); //初始化线段树
int f(int root, int ql, int qr, int & n); //返回区间[l,r]内的最低建筑高度及其编号n

int main(void){
  int n; scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%d",&h[i]);
  build(1,1,n);

  dfs(1,n,0);
  printf("%d\n",cnt);

  return 0;
}

void dfs(int l, int r, int cur){
  if(l>r) return;
  if(l==r) {cnt+=h[l]-cur; return;}
  int h,n; h=f(1,l,r,n);
#ifdef DEBUG
  printf("  min in [%d,%d] is h[%d]: %d\n",l,r,n,h);
#endif
  cnt+=h-cur;
  dfs(l,n-1,h); dfs(n+1,r,h);
}
void build(int root, int l, int r){
  st[root].l=l; st[root].r=r;
  if(l==r) {st[root].h=h[l]; st[root].n=l; return;}
  int m=(l+r)>>1;
  build(root<<1,l,m); build(root<<1|1,m+1,r);
  if(st[root<<1].h<st[root<<1|1].h){
    st[root].h=st[root<<1].h; st[root].n=st[root<<1].n;
  }else{
    st[root].h=st[root<<1|1].h; st[root].n=st[root<<1|1].n;
  }
}
int f(int root, int ql, int qr, int & n){
  if(ql>st[root].r || qr<st[root].l) return INF;
  if(ql<=st[root].l && qr>=st[root].r) {n=st[root].n; return st[root].h;}
  int hl,hr,nl,nr;
  hl=f(root<<1,ql,qr,nl);
  hr=f(root<<1|1,ql,qr,nr);
  if(hl<hr) {n=nl; return hl;}
  else {n=nr; return hr;}
}
