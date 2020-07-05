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
int n, m; char s[20], s1[20], s2[20];
map<string,int> mp;
VR<int> root;
struct Cmd{
  int type, x, y;
}cmd[MAX];

int IDcnt=0;
int ID(char *s){
  if(mp.count(s)) return mp[s];
  return mp[s] = ++IDcnt;
}

VR<int> G[MAX];
struct Node{
  int size, dep, l, r, fa, maxChild, top;
  bool vis;
}node[MAX];

void dfs1(int u){
  Node &p = node[u]; p.vis=1, p.size=1;
  for(int v : G[u]) if(!node[v].vis){
    node[v].dep = p.dep+1; node[v].fa = u;
    dfs1(v); p.size += node[v].size;
    if(!p.maxChild || node[p.maxChild].size < node[v].size)
      p.maxChild = v;
  }
}

int dfnCnt=0;
void dfs2(int u){
  Node &p = node[u]; p.l = ++dfnCnt;
  if(!p.fa || node[p.fa].maxChild!=u) p.top = u;
  else p.top = node[p.fa].top;

  if(p.maxChild) dfs2(p.maxChild);
  for(int v : G[u]) if(node[v].dep == p.dep+1 && v != p.maxChild){
    dfs2(v);
  }
  p.r = dfnCnt;
}

struct HJT{
  int v[MAX], n, tail;
  struct Node{
    int s;
    Node *lc, *rc;
  }*node[MAX<<2], *head[MAX];

  void pushup(Node *u){
    u->s = 0;
    if(u->lc) u->s += u->lc->s;
    if(u->rc) u->s += u->rc->s;
  }

  void add(int h, int p, int val){
#ifdef DEBUG
    printf("  add(%d,%d,%d)\n",h,p,val);
#endif
    while(tail < h){
      head[tail++] = add(1,1,n,1,0);
    }
    head[h] = add(1,1,n,p,val);
    tail++;
  }

  Node *add(int u, int cl, int cr, int p, int val){
    Node *o = new Node; node[u] = o;
    if(cl == cr){
      v[p] += val; o->s = v[p];
      o->lc = o->rc = 0;
      return o;
    }

    int m = (cl+cr)>>1;
    if(p<=m){
      o->lc = add(u<<1,cl,m,p,val);
      o->rc = node[u<<1|1];
    }else{
      o->lc = node[u<<1];
      o->rc = add(u<<1|1,m+1,cr,p,val);
    }
    pushup(o);
    return o;
  }

  int sum(int a, int b, int x){
    return sum(head[a],head[b],1,n,x);
  }
  int sum(Node *u, Node *v, int cl, int cr, int p){
    if(cl == cr){
      return (v ? v->s : 0) - (u ? u->s : 0);
    }
    int m = (cl+cr)>>1;
    if(p<=m) return sum(u ? u->lc : 0, v ? v->lc : 0, cl, m, p);
    else return sum(u ? u->rc : 0, v ? v->rc : 0, m+1, cr, p);
  }
  /*
  int sum(int a, int b, int ql, int qr){
#ifdef DEBUG
    printf("  sum(%d,%d,%d,%d): %d\n",a,b,ql,qr,sum(head[a],head[b],1,n,ql,qr));
#endif
    return sum(head[a],head[b],1,n,ql,qr);
  }
  */

  /*
  int sum(Node *u, Node *v, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return (v ? v->s : 0) - (u ? u->s : 0);
    }
    int m = (cl+cr)>>1, s=0;
    if(ql<=m) s += sum(u ? u->lc : 0, v ? v->lc : 0, cl, m, ql, qr);
    if(qr>=m+1) s += sum(u ? u->rc : 0, v ? v->rc : 0, m+1, cr, ql, qr);
    return s;
  }
  */
}st;

int main(void){
  st.tail = 1;
  scanf("%d",&n); int x, y;
  FORR(i,1,n){
    scanf("%s%s",s,s1); x = ID(s1);
    if(s[0]=='n'){
      root.push_back(x);
      cmd[i] = {1,x,0};
    }else if(s[0]=='c'){
      scanf("%d",&y);
      cmd[i] = {2,x,y};
    }else{
      scanf("%s",s2); y = ID(s2);
      G[x].push_back(y);
      cmd[i] = {3,x,y};
    }
  }

  for(int u : root){
    node[u].dep = 1;
    dfs1(u), dfs2(u);
  }

  st.n = n;
  FORR(i,1,n)
    if(cmd[i].type==2)
      st.add(i, node[cmd[i].x].l, cmd[i].y);
    else if(cmd[i].type==3)
      st.add(i, node[cmd[i].y].l, st.sum(1,i,node[cmd[i].x].l));

  scanf("%d",&m);
  int a, b, u;
  while(m--){
    scanf("%d%d%s",&a,&b,s);
    if(!mp.count(s)){
      printf("0\n"); continue;
    }
    u = ID(s);
    /*
    int ans = 0;
    while(u){
#ifdef DEBUG
      printf("u: %d, node[u].top: %d, node[u].fa: %d\n",u,node[u].top,node[u].fa);
#endif
      x = node[node[u].top].l, y = node[u].l;
      if(x>y) swap(x,y);
      ans += st.sum(a-1,b,x,y);
      u = node[ node[u].top ].fa;
    }
    */
    int ans = st.sum(a-1,b,node[u].l);
    printf("%d\n",ans);
  }

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n, m; char s[20], s1[20], s2[20];
map<string,int> mp;
VR<int> root;
struct Cmd{
  int type, x, y;
}cmd[MAX];

int IDcnt=0;
int ID(char *s){
  if(mp.count(s)) return mp[s];
  return mp[s] = ++IDcnt;
}

VR<int> G[MAX];
struct Node{
  int size, dep, l, r, fa, maxChild, top;
  bool vis;
}node[MAX];

void dfs1(int u){
  Node &p = node[u]; p.vis=1, p.size=1;
  for(int v : G[u]) if(!node[v].vis){
    node[v].dep = p.dep+1; node[v].fa = u;
    dfs1(v); p.size += node[v].size;
    if(!p.maxChild || node[p.maxChild].size < node[v].size)
      p.maxChild = v;
  }
}

int dfnCnt=0;
void dfs2(int u){
  Node &p = node[u]; p.l = ++dfnCnt;
  if(!p.fa || node[p.fa].maxChild!=u) p.top = u;
  else p.top = node[p.fa].top;

  if(p.maxChild) dfs2(p.maxChild);
  for(int v : G[u]) if(node[v].dep == p.dep+1 && v != p.maxChild){
    dfs2(v);
  }
  p.r = dfnCnt;
}

struct HJT{
  int v[MAX], n, tail;
  struct Node{
    int s;
    Node *lc, *rc;
  }*node[MAX<<2], *head[MAX];

  void pushup(Node *u){
    u->s = 0;
    if(u->lc) u->s += u->lc->s;
    if(u->rc) u->s += u->rc->s;
  }

  void add(int h, int p, int val){
#ifdef DEBUG
    printf("  add(%d,%d,%d)\n",h,p,val);
#endif
    while(tail < h){
      head[tail++] = add(1,1,n,1,0);
    }
    head[h] = add(1,1,n,p,val);
    tail++;
  }

  Node *add(int u, int cl, int cr, int p, int val){
    Node *o = new Node; node[u] = o;
    if(cl == cr){
      v[p] += val; o->s = v[p];
      o->lc = o->rc = 0;
      return o;
    }

    int m = (cl+cr)>>1;
    if(p<=m){
      o->lc = add(u<<1,cl,m,p,val);
      o->rc = node[u<<1|1];
    }else{
      o->lc = node[u<<1];
      o->rc = add(u<<1|1,m+1,cr,p,val);
    }
    pushup(o);
    return o;
  }

  int sum(int a, int b, int ql, int qr){
#ifdef DEBUG
    printf("  sum(%d,%d,%d,%d): %d\n",a,b,ql,qr,sum(head[a],head[b],1,n,ql,qr));
#endif
    return sum(head[a],head[b],1,n,ql,qr);
  }

  int sum(Node *u, Node *v, int cl, int cr, int ql, int qr){
    if(ql <= cl && cr <= qr){
      return (v ? v->s : 0) - (u ? u->s : 0);
    }
    int m = (cl+cr)>>1, s=0;
    if(ql<=m) s += sum(u ? u->lc : 0, v ? v->lc : 0, cl, m, ql, qr);
    if(qr>=m+1) s += sum(u ? u->rc : 0, v ? v->rc : 0, m+1, cr, ql, qr);
    return s;
  }
}st;

int main(void){
  st.tail = 1;
  scanf("%d",&n); int x, y;
  FORR(i,1,n){
    scanf("%s%s",s,s1); x = ID(s1);
    if(s[0]=='n'){
      root.push_back(x);
      cmd[i] = {1,x,0};
    }else if(s[0]=='c'){
      scanf("%d",&y);
      cmd[i] = {2,x,y};
    }else{
      scanf("%s",s2); y = ID(s2);
      G[x].push_back(y);
      cmd[i] = {3,x,y};
    }
  }

  for(int u : root){
    node[u].dep = 1;
    dfs1(u), dfs2(u);
  }

  st.n = n;
  FORR(i,1,n) if(cmd[i].type==2)
    st.add(i, node[cmd[i].x].l, cmd[i].y);

  scanf("%d",&m);
  int a, b, u;
#ifdef DEBUG
  //  sum(0,2,1,1): 100 100 u: 3, node[u].top: 1, node[u].fa: 1 sum(1,5,1,2): 0
  printf("%d\n",st.sum(0,2,1,1));
  printf("%d\n",st.sum(0,3,1,1));
  printf("%d\n",st.sum(0,4,1,1));
  printf("%d\n",st.sum(0,5,1,1));
#endif

  while(m--){
    scanf("%d%d%s",&a,&b,s);
    if(!mp.count(s)){
      printf("0\n"); continue;
    }
    u = ID(s);
    int ans = 0;
    while(u){
#ifdef DEBUG
      printf("u: %d, node[u].top: %d, node[u].fa: %d\n",u,node[u].top,node[u].fa);
#endif
      x = node[node[u].top].l, y = node[u].l;
      if(x>y) swap(x,y);
      ans += st.sum(a-1,b,x,y);
      u = node[ node[u].top ].fa;
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
