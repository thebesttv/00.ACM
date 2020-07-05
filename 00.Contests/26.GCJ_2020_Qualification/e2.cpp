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
int n,k,a[MAX][MAX],b[MAX];

bool divide(int k){
  if(k==n+1 || k==n*n-1) return false;
  FORR(i,1,n) b[i]=1, --k;
  ROR(i,n,1){
    int d=min(k,n-1);
    b[i]+=d; k-=d;
    if(!k) break;
  }
  if(b[1]<n && b[2]==n)
    ++b[1], --b[2];
  else if(b[n-1]==1 && b[n]>1)
    ++b[n-1], --b[n];
#ifdef DEBUG
  printf("\nconstruct b:");
  FORR(i,1,n) printf(" %d",b[i]);
  putchar('\n');
#endif
  return true;
}

struct Row{
  int i,j,k;
  void set(int _i, int _j, int _k){
    i=_i, j=_j, k=_k;
  }
}*row[50*50*50+20];

struct Node{
  Node *left,*right,*up,*down,*col;
  Row *row;
  int size;
  Node() { left = right = up = down = col = 0; row = 0; size = 0; }
  void set(Node *l, Node *r, Node *u, Node *d, Node *c, Row *ro){
    left=l, right=r, up=u, down=d, col=c, row=ro;
  }
}*col[50*50*3+20], *head;

void init(){
  head = new Node;
  int tot = 50*50*3;
  FORR(i,1,tot) col[i] = new Node;
  tot = 50*50*50;
  FORR(i,1,tot) row[i] = new Row;
}

void cover(Node *u){
  Node *col = u->col, *v;
  col->left->right = col->right;
  col->right->left = col->left;

  for(u=col->down; u!=col; u=u->down)
    for(v=u->right; v!=u; v=v->right){
      v->up->down = v->down;
      v->down->up = v->up;
      --(v->col->size);
    }
}

void uncover(Node *u){
  Node *col = u->col, *v;
  for(u=col->up; u!=col; u=u->up)
    for(v=u->left; v!=u; v=v->left){
      v->up->down = v;
      v->down->up = v;
      ++(v->col->size);
    }

  col->left->right = col;
  col->right->left = col;
}

Node *getMinCol(){
  int tMin = 0x3f3f3f3f; Node *r = nullptr;
  for(Node *u = head->right; u!=head; u=u->right)
    if(u->size < tMin){
      tMin = u->size;
      r = u;
    }
  return r;
}

bool DancingLink(stack<Node*> &st){
  if(head->right == head)
    return true;
  Node *col = getMinCol();
  cover(col);
  for(Node *u = col->down; u!=col; u=u->down){
    st.push(u);
    for(Node *v = u->right; v!=u; v=v->right)
      cover(v);
    if(DancingLink(st))
      return true;
    for(Node *v = u->left; v!=u; v=v->left)
      uncover(v);
    st.pop();
  }
  uncover(col);
  return false;
}

void addRow(int i, int j, int k, int tail, queue<Node*> &mPool){
  Node *v[3]; FOR(i,0,3) v[i] = new Node;
  int x[3] = { (i-1)*n+j, n*n + (i-1)*n+k, n*n*2 + (j-1)*n+k };
  row[tail]->set(i,j,k);
  FOR(i,0,3){
    v[i]->set(v[(i-1+3)%3], v[(i+1)%3], col[x[i]]->up, col[x[i]], col[x[i]], row[tail]);
    v[i]->up->down = v[i];
    v[i]->down->up = v[i];

    ++(col[x[i]]->size);
    mPool.push(v[i]);
  }
}

bool solve(){
  int tot = n*n*3;
  head->right = col[1];
  head->left = col[tot];
  FORR(i,1,tot){
    col[i]->set(col[i-1], col[i+1], col[i], col[i], col[i], nullptr);
    col[i]->size = 0;
  }
  col[1]->left = col[tot]->right = head;

  int tail = 1;
  queue<Node*> mPool;
  FORR(i,1,n) FORR(j,1,n)
    if(i==j)
      addRow(i,j,b[i],tail++,mPool);
    else FORR(k,1,n)
      addRow(i,j,k,tail++,mPool);
#ifdef DEBUG
  printf("  add %d row\n",tail-1);
#endif

  stack<Node*> st;
  bool res = DancingLink(st);
  if(res) while(!st.empty()){
    Node *u = st.top(); st.pop();
    Row *r = u->row;
    a[r->i][r->j] = r->k;
  }

  while(!mPool.empty()){
    delete mPool.front();
    mPool.pop();
  }
  return res;
}

int main(void){
  init();
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&k);
    printf("Case #%d: ",kase);
    if(!divide(k) || !solve()){
      printf("IMPOSSIBLE\n");
    }else{
      printf("POSSIBLE\n");
      FORR(i,1,n){
        FORR(j,1,n) printf("%d ",a[i][j]);
        putchar('\n');
      }
    }
  }

  return 0;
}
