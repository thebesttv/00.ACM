// Tag: 链表 高效率
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

const int MAX = 100020;
int n,m,reversed;
struct Node{
  int v;
  Node *l, *r;
}*node[MAX], pool[MAX], *zero;

void link(Node *u, Node *v){
  u->r = v, v->l = u;
}

int main(void){
  FORR(i,1,100000) node[i] = pool + i;
  zero = new Node; zero->v = 0;
  zero->l = zero->r = zero;

  int kase = 0;
  while(scanf("%d%d",&n,&m)==2){
    reversed = 0;
    FORR(i,1,n){
      node[i]->v = i;
      node[i]->l = node[i-1];
      node[i]->r = node[i+1];
    }
    node[1]->l = node[n]->r = zero;

    int op,x,y;
    while(m--){
      scanf("%d",&op);
      if(op==4) reversed ^= 1;
      else{
        scanf("%d%d",&x,&y);
        if(op==3){
          swap(node[x]->v, node[y]->v);
          swap(node[x], node[y]);
        }else if((op-1) ^ reversed){  // right
          link(node[x]->l, node[x]->r);
          link(node[x], node[y]->r);
          link(node[y], node[x]);
        }else{ // left
          link(node[x]->l, node[x]->r);
          link(node[y]->l, node[x]);
          link(node[x], node[y]);
        }
      }
    }

    Node *head; int cnt = 1; LL sum = 0;
    if(!reversed){
      FORR(i,1,n) if(node[i]->l == zero){
        head = node[i]; break;
      }
      while(head != zero){
        if(cnt&1) sum += head->v;
        head = head->r; ++cnt;
      }
    }else{
      FORR(i,1,n) if(node[i]->r == zero){
        head = node[i]; break;
      }
      while(head != zero){
        if(cnt&1) sum += head->v;
        head = head->l; ++cnt;
      }
    }
    printf("Case %d: %lld\n",++kase,sum);
  }

  return 0;
}
