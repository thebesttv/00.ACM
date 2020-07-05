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

const int MAX = 60;
int n,k,a[MAX][MAX],b[MAX],cnt[MAX];

#ifdef DEBUG
int color = 0, DEcol[MAX];
bool ok(){
  int s = 0;
  FORR(i,1,n) s += a[i][i];
  if(s != k){
    printf("  s: %d, k: %d\n",s,k);
    return 0;
  }

  FORR(i,1,n){
    ++color;
    FORR(j,1,n)
      if(DEcol[a[i][j]]==color) return 0;
      else DEcol[a[i][j]] = color;
    FORR(j,1,n) if(DEcol[j]!=color) return 0;
  }

  FORR(j,1,n){
    ++color;
    FORR(i,1,n)
      if(DEcol[a[i][j]]==color) return 0;
      else DEcol[a[i][j]] = color;
    FORR(i,1,n) if(DEcol[i]!=color) return 0;
  }

  return 1;
}
#endif

struct Node{
  Node *left,*right,*up,*down,*col;
  int i,j,k,cnt;
  Node(){
    left = right = up = down = col = 0;
    i = j = k = cnt = 0;
  }
  Node(int i, int j, int k): i(i), j(j), k(k){
    left = right = up = down = col = 0;
  }
  void set(Node *l, Node *r, Node *u, Node *d, Node *c){
    left = l, right = r, up = u, down = d, col = c;
  }
}col[7520],head;

void cover(Node *u){
  Node *col = u->col;
  col->left->right = col->right;
  col->right->left = col->left;
#ifdef DEBUGALL
  printf("  cover column %d\n",col->j);
#endif

  for(u=col->down; u!=col; u=u->down)
    for(Node *v=u->right; v!=u; v=v->right){
      v->up->down = v->down;
      v->down->up = v->up;
      --v->col->cnt;
    }
}

void uncover(Node *u){
  Node *col = u->col;
#ifdef DEBUG_ALL
  printf("  uncover column %d\n",col->j);
#endif
  for(u=col->up; u!=col; u=u->up)
    for(Node *v=u->left; v!=u; v=v->left){
      v->up->down = v;
      v->down->up = v;
      ++v->col->cnt;
    }

  col->left->right = col;
  col->right->left = col;
}

stack<Node*> st;

Node *getMinCol(Node *head){
  int tMin = 0x3f3f3f3f; Node *r = 0;
  for(Node *u=head->right;u!=head;u=u->right)
    if(u->cnt < tMin){
      tMin = u->cnt; r = u;
    }
  return r;
}

bool solve(Node *head){
#ifdef DEBUG_ALL
  printf("  in solve\n");
#endif
  if(head->right == head)
    return true;
  // Node *col = head->right;
  Node *col = getMinCol(head);
  // if(col->down == col) return false;

  cover(col);
  for(Node *u = col->down; u!=col; u=u->down){
    for(Node *v = u->right; v!=u; v=v->right)
      cover(v);
    st.push(u);

    if(solve(head))
      return true;

    st.pop();
    for(Node *v = u->left; v!=u; v=v->left)
      uncover(v);
  }
  uncover(col);
  return false;
}

queue<Node*> mPool;
void addRow(int i, int j, int k){
#ifdef DEBUG_ALL
  printf("  add row (%d,%d) %d\n",i,j,k);
#endif
  Node *a = new Node(i,j,k);
  Node *b = new Node(i,j,k);
  Node *c = new Node(i,j,k);
  mPool.push(a), mPool.push(b), mPool.push(c);
  int x1 = (i-1)*n+j,
      x2 = n*n + (i-1)*n + k,
      x3 = n*n*2 + (j-1)*n + k;
  // l, r, u, d
  a->set(c,b,col[x1].up,&col[x1],&col[x1]);
  b->set(a,c,col[x2].up,&col[x2],&col[x2]);
  c->set(b,a,col[x3].up,&col[x3],&col[x3]);

  col[x1].up = a;
  col[x2].up = b;
  col[x3].up = c;

  a->up->down = a;
  b->up->down = b;
  c->up->down = c;

  ++col[x1].cnt, ++col[x2].cnt, ++col[x3].cnt;
}

bool DL(){
  while(!mPool.empty()){
    delete mPool.front();
    mPool.pop();
  }
  int tot = n*n*3;
  head.right = &col[1];
  head.left = &col[tot];
  FORR(i,1,tot){
    col[i].left = &col[i-1];
    col[i].right = &col[i+1];
    col[i].up = col[i].down = col[i].col = &col[i];
    col[i].j = i;
    col[i].cnt = 0;
  }
  col[1].left = col[tot].right = &head;

  FORR(i,1,n) FORR(j,1,n)
    if(i==j)
      addRow(i,j,b[i]);
    else FORR(k,1,n)
      addRow(i,j,k);

  while(!st.empty()) st.pop();

  if(solve(&head)){
    while(!st.empty()){
      Node *p = st.top(); st.pop();
      a[p->i][p->j] = p->k;
    }
    return true;
  }else
    return false;
}

bool divide(int k){
  if(k==n+1 || k==n*n-1 || (n==3 && k%n))
    return false;

  FORR(i,1,n) b[i]=1, --k;
  ROR(i,n,1){
    int d = min(n-1, k);
    b[i] += d; k -= d;
    if(!k) break;
  }
  if(b[n-1] == 1 && b[n]>1){
    --b[n]; ++b[n-1];
  }else if(b[2]==n && b[1]<n){
    ++b[1], --b[2];
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&k);
    printf("Case #%d: ",kase);

    if(!divide(k)){
      printf("IMPOSSIBLE\n"); continue;
    }

    FORR(i,1,n) a[i][i] = b[i];
#ifdef DEBUG
    printf("create:");
    FORR(i,1,n) printf(" %d",b[i]);
    putchar('\n');
#endif

    if(!DL()){
      printf("IMPOSSIBLE\n"); continue;
    }else printf("POSSIBLE\n");

    FORR(i,1,n){
      FORR(j,1,n) printf("%d ",a[i][j]);
      putchar('\n');
    }
#ifdef DEBUG
    if(!ok()){
      printf("WRONG\n");
      exit(1);
    }
#endif
  }

  return 0;
}

/*
const int MAX = 60;
int n,k,a[MAX][MAX],b[MAX],cnt[MAX];

#ifdef DEBUG
int color = 0, DEcol[MAX];
bool ok(){
  int s = 0;
  FORR(i,1,n) s += a[i][i];
  if(s != k){
    printf("  s: %d, k: %d\n",s,k);
    return 0;
  }

  FORR(i,1,n){
    ++color;
    FORR(j,1,n)
      if(DEcol[a[i][j]]==color) return 0;
      else DEcol[a[i][j]] = color;
    FORR(j,1,n) if(DEcol[j]!=color) return 0;
  }

  FORR(j,1,n){
    ++color;
    FORR(i,1,n)
      if(DEcol[a[i][j]]==color) return 0;
      else DEcol[a[i][j]] = color;
    FORR(i,1,n) if(DEcol[i]!=color) return 0;
  }

  return 1;
}
#endif

struct Node{
  Node *left,*right,*up,*down,*col;
  int i,j,k;
  Node(){
    left = right = up = down = col = 0;
    i = j = k = 0;
  }
  Node(int i, int j, int k): i(i), j(j), k(k){
    left = right = up = down = col = 0;
  }
  void set(Node *l, Node *r, Node *u, Node *d, Node *c){
    left = l, right = r, up = u, down = d, col = c;
  }
}col[7520],head;

void cover(Node *u){
  Node *col = u->col;
  col->left->right = col->right;
  col->right->left = col->left;
#ifdef DEBUG
  // printf("  cover column %d\n",col->j);
#endif

  for(u=col->down; u!=col; u=u->down)
    for(Node *v=u->right; v!=u; v=v->right){
      v->up->down = v->down;
      v->down->up = v->up;
    }
}

void uncover(Node *u){
  Node *col = u->col;
#ifdef DEBUG
  // printf("  uncover column %d\n",col->j);
#endif
  for(u=col->up; u!=col; u=u->up)
    for(Node *v=u->left; v!=u; v=v->left){
      v->up->down = v;
      v->down->up = v;
    }

  col->left->right = col;
  col->right->left = col;
}

stack<Node*> st;

bool solve(Node *head){
#ifdef DEBUG
  // printf("  in solve\n");
#endif
  if(head->right == head)
    return true;
  Node *col = head->right;
  if(col->down == col) return false;

  cover(col);
  for(Node *u = col->down; u!=col; u=u->down){
    for(Node *v = u->right; v!=u; v=v->right)
      cover(v);
    st.push(u);

    if(solve(head))
      return true;

    st.pop();
    for(Node *v = u->left; v!=u; v=v->left)
      uncover(v);
  }
  uncover(col);
  return false;
}

void addRow(int i, int j, int k){
#ifdef DEBUG
  //printf("  add row (%d,%d) %d\n",i,j,k);
#endif
  Node *a = new Node(i,j,k);
  Node *b = new Node(i,j,k);
  Node *c = new Node(i,j,k);
  int x1 = (i-1)*n+j,
      x2 = n*n + (i-1)*n + k,
      x3 = n*n*2 + (j-1)*n + k;
  // l, r, u, d
  a->set(c,b,col[x1].up,&col[x1],&col[x1]);
  b->set(a,c,col[x2].up,&col[x2],&col[x2]);
  c->set(b,a,col[x3].up,&col[x3],&col[x3]);

  col[x1].up = a;
  col[x2].up = b;
  col[x3].up = c;

  a->up->down = a;
  b->up->down = b;
  c->up->down = c;
}

bool DL(){
  int tot = n*n*3;
  head.right = &col[1];
  head.left = &col[tot];
  FORR(i,1,tot){
    col[i].left = &col[i-1];
    col[i].right = &col[i+1];
    col[i].up = col[i].down = col[i].col = &col[i];
    col[i].j = i;
  }
  col[1].left = col[tot].right = &head;
#ifdef DEBUG
  printf("  created %d columns\n",tot);
#endif

  FORR(i,1,n) FORR(j,1,n)
    if(i==j)
      addRow(i,j,b[i]);
    else FORR(k,1,n)
      addRow(i,j,k);

  while(!st.empty()) st.pop();

  if(solve(&head)){
#ifdef DEBUG
    printf("  DL successful\n");
#endif
    while(!st.empty()){
      Node *p = st.top(); st.pop();
      a[p->i][p->j] = p->k;
    }
    return true;
  }else
    return false;
}

bool divide(int k){
  if(k==n+1 || k==n*n-1 || (n==3 && k%n))
    return false;

  FORR(i,1,n) b[i]=1, --k;
  ROR(i,n,1){
    int d = min(n-1, k);
    b[i] += d; k -= d;
    if(!k) break;
  }
  if(b[n-1] == 1 && b[n]>1){
    --b[n]; ++b[n-1];
  }else if(b[2]==n && b[1]<n){
    ++b[1], --b[2];
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&k);
    printf("Case #%d: ",kase);

    if(!divide(k)){
      printf("IMPOSSIBLE\n"); continue;
    }

    FORR(i,1,n) a[i][i] = b[i];
#ifdef DEBUG
    printf("create:");
    FORR(i,1,n) printf(" %d",b[i]);
    putchar('\n');
#endif

    if(!DL()){
      printf("IMPOSSIBLE\n"); continue;
    }else printf("POSSIBLE\n");

    FORR(i,1,n){
      FORR(j,1,n) printf("%d ",a[i][j]);
      putchar('\n');
    }
#ifdef DEBUG
    if(!ok()){
      printf("WRONG\n");
      exit(1);
    }
#endif
  }

  return 0;
}
*/
