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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2e5+20;
int n,m,a[MAX];
struct Node{
  int v, pos;
  bool operator < (const Node &b) const {
    return v!=b.v ? v > b.v : pos < b.pos;
  }
}node[MAX];

struct Que{
  int k, pos, num;
  bool operator < (const Que &b) const {
    return k!=b.k ? k < b.k : pos < b.pos;
  }
}Q[MAX];
int ans[MAX];

struct ST{
  int n;
  int s[MAX];

  void init(int nn){
    n = nn;
  }
  void insert(int x){
    while(x<=n){
      s[x]++;
      x += x&-x;
    }
  }
  int sum(int x){
    int ans = 0;
    while(x>0){
      ans += s[x];
      x -= x&-x;
    }
    return ans;
  }
  int get(int pos){
    int l=1, r = n;
    while(l<r){
      int m = (l+r)/2;
      int s = sum(m);
      if(s<pos) l = m+1;
      else r = m;
    }
    return l;
  }
}st;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d",&a[i]);
    node[i] = {a[i],i};
  }
  sort(node,node+n);

  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&Q[i].k,&Q[i].pos);
    Q[i].num = i;
  }
  sort(Q,Q+m);

  int i = 0, tailK = 0;
  st.init(n);
  while(i<m){
    int j = i + 1;
    while(j<m && Q[i].k == Q[j].k) j++;

    FOR(k,tailK,Q[i].k){
      st.insert(node[k].pos+1);
      //printf("  insert: %d\n",node[k].pos+1);
    }

    FOR(k,i,j){
      int p = st.get(Q[k].pos) - 1;
      //printf("  get(%d): %d\n",Q[k].pos,p);
      ans[Q[k].num] = a[p];
    }
    tailK = Q[i].k; i = j;
  }
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}

/*
const int MAX=2e5+20;
int n,m,a[MAX];
struct Node{
  int v, pos;
  bool operator < (const Node &b) const {
    return v!=b.v ? v > b.v : pos < b.pos;
  }
}node[MAX];

struct Que{
  int k, pos, num;
  bool operator < (const Que &b) const {
    return k!=b.k ? k < b.k : pos < b.pos;
  }
}Q[MAX];
int ans[MAX];

struct BST{
  struct Node{
    int v;
    Node *lc, *rc;
    int lcnt, rcnt;
    Node() { }
    Node(int vv): v(vv){
      lc = rc = NULL; lcnt = rcnt = 0;
    }
  }*root=NULL;

  void insert(int v){
    Node **p = &root;
    while(*p){
      if((*p)->v > v){
        (*p)->lcnt++;
        p = &((*p)->lc);
      }else{
        (*p)->rcnt++;
        p = &((*p)->rc);
      }
    }
    *p = new Node(v);
  }
  int get(int n){
    Node *p = root;
    while(p){
      if(p->lcnt + 1 == n){
        return p->v;
      }
      if(p->lcnt >= n) p = p->lc;
      else{
        n -= p->lcnt + 1;
        p = p->rc;
      }
    }
    return -1;
  }
}bst;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d",&a[i]);
    node[i] = {a[i],i};
  }
  sort(node,node+n);

  scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&Q[i].k,&Q[i].pos);
    Q[i].num = i;
  }
  sort(Q,Q+m);

  int i = 0, tailK = 0;
  while(i<m){
    int j = i + 1;
    while(j<m && Q[i].k == Q[j].k) j++;

    FOR(k,tailK,Q[i].k){
      bst.insert(node[k].pos);
    }

    FOR(k,i,j){
      int p = bst.get(Q[k].pos);
      ans[Q[k].num] = a[p];
    }
    tailK = Q[i].k; i = j;
  }
  FOR(i,0,m) printf("%d\n",ans[i]);

  return 0;
}
*/
