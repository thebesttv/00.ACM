// Tag: 树
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

const int MAX = 1020;
int n; char ori[MAX], s[MAX];
struct Node{
  int v; Node *l, *r;
  Node() { v = -1, l = r = nullptr; }
}root;

bool bad = 0;
void build(Node *u, int v, char *s){
  int ch = *s++;
  if(ch == ')'){
    if(u->v != -1) bad = 1;
    u->v = v; return;
  }
  if(ch == 'L'){
    if(!u->l) u->l = new Node;
    build(u->l, v, s);
  }else{
    if(!u->r) u->r = new Node;
    build(u->r, v, s);
  }
}

int main(void){
  while(scanf("%s",ori)==1){
    root = Node(); bad = 0;
    while(ori[1] != ')'){
      int v; sscanf(ori, "(%d,%s", &v, s);
#ifdef DEBUG
      printf("  node %d, %s\n",v,s);
#endif
      build(&root, v, s);
      scanf("%s",ori);
    }

    bool ok = 1;
    queue<Node*> q; q.push(&root);
    VR<int> ans;

    if(bad) goto BAD;

    while(!q.empty()){
      Node *t = q.front(); q.pop();
      if(!t || t->v == -1){
        ok = 0; break;
      }
      ans.push_back(t->v);
      if(t->l) q.push(t->l);
      if(t->r) q.push(t->r);
    }
    if(!ok) goto BAD;

    printf("%d",ans[0]);
    FOR(i,1,ans.size()) printf(" %d",ans[i]);
    putchar('\n');
    continue;

BAD:
    printf("not complete\n");
  }

  return 0;
}
