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

const int MAX = 5e5 + 4;
int n,m,a[MAX],v[MAX], ID[int(1e6+20)];

LL fsum(int l, int r){
  int len = r - l + 1;
  return 1ll * (l+r) * len / 2;
}

struct ST{
  int n;
  struct Node{
    int cnt; LL sum;
    Node *l, *r;
  }*head[MAX], *cur[MAX<<2];

  void init(){
    int n4 = n*4;
    Node *p = new Node;
    p->cnt = 0, p->sum = 0; p->l = p->r = p;
    FORR(i,1,n4) cur[i] = p;
    head[0] = p;
  }
  void insert(int i, int x, int ox){
    head[i] = update(1, 1, n, x, ox);
  }
  Node* update(int u, int l, int r, int x, int ox){
    Node *p = new Node;
    if(l == r){
      p->sum = cur[u]->sum + ox;
      p->cnt = cur[u]->cnt + 1;
      p->l = p->r = nullptr;
      return cur[u] = p;
    }

    int m = (l+r)>>1;
    if(x<=m){
      p->l = cur[u<<1] = update(u<<1, l, m, x, ox);
      p->r = cur[u<<1|1];
    }else{
      p->l = cur[u<<1];
      p->r = cur[u<<1|1] = update(u<<1|1, m+1, r, x, ox);
    }
    p->cnt = p->l->cnt + p->r->cnt;
    p->sum = p->l->sum + p->r->sum;
    return cur[u] = p;
  }

  /*
  int getK(int l, int r, int b){
    return getK(head[l-1], head[r], 1, n, b, 0);
  }
  int getK(Node *u, Node *v, int l, int r, int b, int f){
    if(l==r) return f + 1;
    int m = (l+r)>>1, ls = v->l->cnt - u->l->cnt;
    if(::v[m-1] <= b + f + ls - 1){
      return getK(u->r, v->r, m+1, r, b, f+ls);
    }else{
      return getK(u->l, v->l, l, m, b, f);
    }
  }
  */

  LL ans(int l, int r, int b){
    return ans(head[l-1], head[r], 1, n, b, 0);
  }
  LL ans(Node *u, Node *v, int l, int r, int b, int f){
    if(v->cnt - u->cnt == 0) return 0;
    if(l==r) return abs(::v[l-1] - b - f);

    int m = (l+r)>>1, ls = v->l->cnt - u->l->cnt;
    if(::v[m-1] <= b + f + ls - 1){
      return fsum(b+f, b+f+ls-1) - (v->l->sum - u->l->sum)
             + ans(u->r, v->r, m+1, r, b, f+ls);
    }else{
      return ans(u->l, v->l, l, m, b, f)
             + (v->r->sum - u->r->sum) - fsum(b+f+ls, b+f+ls + v->r->cnt - u->r->cnt - 1);
    }
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), v[i-1] = a[i];
  sort(v,v+n); sg.n = n; sg.init();
  FOR(i,0,n) ID[v[i]] = i+1;
  FORR(i,1,n) sg.insert(i, ID[a[i]], a[i]);

  int l,r,b,len; LL ans;
  while(m--){
    scanf("%d%d%d",&l,&r,&b);
    ans = sg.ans(l, r, b);
    printf("%lld\n",ans);
  }

  return 0;
}
