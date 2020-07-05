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
int n,m;

struct Node{
  Node *left, *right, *up, *down;
  int val, x, y;
  void set(Node *l, Node *r, Node *u, Node *d, int v, int _x, int _y){
    left = l, right = r, up = u, down = d; val = v, x=_x, y=_y;
  }
}*col[MAX], *head;

void init(int m){
  head->right = col[1];
  head->left = col[m];
  FORR(i,1,m)
    col[i]->set(col[i-1], col[i+1], col[i], col[i], -i, -i, -i);
  col[1]->left = col[m]->right = head;
}

void addRow(VR<int> &v, int x){
  Node *pool = new Node[m+1];
  FORR(i,1,m){
    pool[i].set(&pool[i-1],&pool[i+1],col[i]->up,col[i],v[i], x, i);
    col[i]->up = &pool[i];
    pool[i].up->down = &pool[i];
  }
  pool[1].left = &pool[m];
  pool[m].right = &pool[1];
}

void cover(Node *u){
  u->up->down = u->down;
  u->down->up = u->up;
  u->left->right = u->right;
  u->right->left = u->left;
}

pair<Node*, int> q[MAX];
int qhead, qtail;

pii cal(Node *u){
  int sum=0, cnt=0;
  // up
  if(u->up->x > 0 &&  u->up->x < u->x)
    sum += u->up->val, ++cnt;
  // down
  if(u->down->x > u->x)
    sum += u->down->val, ++cnt;
  // left
  if(u->left->y < u->y)
    sum += u->left->val, ++cnt;
  // right
  if(u->right->y > u->y)
    sum += u->right->val, ++cnt;
  return {cnt,sum};
}

int main(void){
  head = new Node;
  FOR(i,0,MAX) col[i] = new Node;

  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d",&n,&m);
    init(m);
    LL total = 0;
    FORR(i,1,n){
      VR<int> v; int x;
      v.push_back(-1);
      FORR(j,1,m){
        scanf("%d",&x);
        v.push_back(x);
        total += x;
      }
      addRow(v, i);
    }

    map<Node*, bool> vis;
    qhead = qtail = 0;
    VR<Node *> delim;
    for(Node *u = head->right; u != head; u = u->right)
      for(Node *v = u->down; v != u; v = v->down){
        pii p = cal(v);
        int cnt = p.FI, sum = p.SE;
        if(v->val * cnt < sum){
          q[qtail++] = {v,1};
          delim.push_back(v); vis[v] = 1;
        }
      }

    for(Node *p : delim)
      cover(p);

    while(true){
      VR<Node *> delim;
      int level = q[qhead].SE;

      while(qhead < qtail){
        Node *u = q[qhead].FI, *v;
        int dep = q[qhead].SE;
        if(dep > level) break;
        ++qhead;

        if(u->up->x > 0 && u->up->x < u->x){
          v = u->up;
          if(!vis[v]){
            pii p = cal(v);
            if(p.FI * v->val < p.SE){
              q[qtail++] = {v, dep+1};
              vis[v] = 1; delim.push_back(v);
            }
          }
        }
        if(u->down->x > u->x){
          v = u->down;
          if(!vis[v]){
            pii p = cal(v);
            if(p.FI * v->val < p.SE){
              q[qtail++] = {v, dep+1};
              vis[v] = 1; delim.push_back(v);
            }
          }
        }
        if(u->left->y < u->y){
          v = u->left;
          if(!vis[v]){
            pii p = cal(v);
            if(p.FI * v->val < p.SE){
              q[qtail++] = {v, dep+1};
              vis[v] = 1; delim.push_back(v);
            }
          }
        }
        if(u->right->y > u->y){
          v = u->right;
          if(!vis[v]){
            pii p = cal(v);
            if(p.FI * v->val < p.SE){
              q[qtail++] = {v, dep+1};
              vis[v] = 1; delim.push_back(v);
            }
          }
        }
      }

      if(delim.empty()) break;
      for(Node *p : delim)
        cover(p);
    }

    int lev = q[qtail-1].SE;
    LL ans = total * (lev+1), d = 0;
    int i = 0, j;
    FORR(k,1,lev){
      j = i;
      while(j < qtail && q[j].SE == k) ++j;
      while(i<j){
        d += q[i].FI->val; ++i;
      }
      ans -= d;
    }
    printf("Case #%d: %lld\n",kase,ans);
  }

  return 0;
}
