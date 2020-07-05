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
int n,m,a[MAX],v[MAX*2],tail;
struct Query{
  char type;
  int l,r,k;
}Q[MAX];

int idx(int x){
  return lower_bound(v,v+tail,x)-v+1;
}

struct ST{
  int n;
  struct Node{
    int s;
    Node *l, *r;
    Node() { s = 0; l = r = nullptr; }
    Node(Node *p) { s = 0; l = r = p; }
  }*head[MAX*2],*zero,
   **av[500], *sv1[500], *sv2[500];
  void init(){
    zero = new Node;
    zero->l = zero->r = zero;
    FORR(i,0,n) head[i] = zero;
  }

  void update(Node **v[], int len, int l, int r, int p, int val){
    FOR(i,0,len) if((*v[i])==zero)
      (*v[i]) = new Node(zero);
    if(l==r){
      FOR(i,0,len) (*v[i])->s += val;
      return;
    }

    int m = (l+r)/2;
    Node ***tv = new Node ** [len];
    if(p <= m){
      FOR(i,0,len) tv[i] = v[i], v[i] = &((*v[i])->l);
      update(v, len, l, m, p, val);
    }else{
      FOR(i,0,len) tv[i] = v[i], v[i] = &((*v[i])->r);
      update(v, len, m+1, r, p, val);
    }
    FOR(i,0,len) (*tv[i])->s = (*tv[i])->l->s + (*tv[i])->r->s;
    delete [] tv;
  }

  int query(Node *vl[], Node *vr[], int len1, int len2, int l, int r, int k){
    if(l==r) return l;

    int m = (l+r)/2, ls = 0;
    FOR(i,0,len2) ls += vr[i]->l->s;
    FOR(i,0,len1) ls -= vl[i]->l->s;

    if(k <= ls){
      FOR(i,0,len1) vl[i] = vl[i]->l;
      FOR(i,0,len2) vr[i] = vr[i]->l;
      return query(vl, vr, len1, len2, l, m, k);
    }else{
      FOR(i,0,len1) vl[i] = vl[i]->r;
      FOR(i,0,len2) vr[i] = vr[i]->r;
      return query(vl, vr, len1, len2, m+1, r, k-ls);
    }
  }

  void add(int x, int v){
#ifdef DEBUG
    printf("add(%d, %d)\n",x,v);
#endif
    int tail = 0, p = a[x];
    while(x<=n){
      av[tail++] = &head[x];
      x += x&-x;
    }
    update(av, tail, 1, n, idx(p), v);
  }
  int sum(int l, int r, int k){
#ifdef DEBUG
    printf("sum(%d, %d, %d)\n",l,r,k);
#endif
    int t1 = 0, t2 = 0;
    --l;
    while(l) sv1[t1++] = head[l], l -= l&-l;
    while(r) sv2[t2++] = head[r], r -= r&-r;
    return query(sv1, sv2, t1, t2, 1, n, k);
  }
}sg;

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,n) scanf("%d",&a[i]), v[tail++]=a[i];
  FORR(i,1,m){
    do Q[i].type = getchar(); while(!isupper(Q[i].type));
    scanf("%d%d",&Q[i].l,&Q[i].r);
    if(Q[i].type == 'C')
      v[tail++] = Q[i].r;
    else
      scanf("%d",&Q[i].k);
  }
  sort(v,v+tail); tail = unique(v,v+tail)-v;
#ifdef DEBUG
  FOR(i,0,tail) printf("%d ",v[i]); putchar('\n');
#endif
  sg.n = tail; sg.init();

  FORR(i,1,n) sg.add(i, 1);

  FORR(i,1,m)
    if(Q[i].type == 'C'){
      sg.add(Q[i].l, -1);
      a[Q[i].l] = Q[i].r;
      sg.add(Q[i].l, 1);
    }else{
      printf("%d\n",v[sg.sum(Q[i].l,Q[i].r,Q[i].k)-1]);
    }

  return 0;
}
