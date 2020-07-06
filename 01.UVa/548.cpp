// Tag: 二叉树遍历
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

const int MAX = 10020;
int n,mid[MAX],post[MAX],pos[MAX];
char s[MAX*100];

struct Node{
  int v; Node *l, *r;
  Node() { v = 0, l = r = nullptr; }
};

int read(int *v){
  if(!FGETS(s)) return 0;
  char *p = s; int tail = 0;
  while(*p){
    int sum = 0, ch;
    do ch = *p++; while(!isdigit(ch));
    while(isdigit(ch)) sum = sum * 10 + ch-'0', ch = *p++;
    v[tail++] = sum;
  }
  return tail;
}

Node *build(int ml, int mr, int pl, int pr){
#ifdef DEBUG
  printf("  build(%d, %d, %d, %d)\n",ml,mr,pl,pr);
#endif
  Node *p = new Node;
  p->v = post[pr];
  if(ml == mr) return p;

  int m = pos[p->v];
  if(ml < m) p->l = build(ml,m-1,pl,pl + (m-ml) - 1);
  if(mr > m) p->r = build(m+1,mr,pl + (m-ml), pr-1);
  return p;
}

int main(void){
  while(read(mid) && (n = read(post))){
#ifdef DEBUG
    printf("mid: "); FOR(i,0,n) printf(" %d",mid[i]); putchar('\n');
    printf("post:"); FOR(i,0,n) printf(" %d",post[i]); putchar('\n');
#endif
    FOR(i,0,n) pos[mid[i]] = i;
    Node *root = build(0, n-1, 0, n-1);

    int ansMin = 0x3f3f3f3f, r = -1;
    queue<pair<Node*, int>> q; q.push({root,root->v});
    while(!q.empty()){
      auto t = q.front(); q.pop();
      Node *p = t.FI;
      if(p->l || p->r){
        if(p->l) q.push({p->l, t.SE + p->l->v});
        if(p->r) q.push({p->r, t.SE + p->r->v});
      }else if(t.SE < ansMin){
        ansMin = t.SE;
        r = p->v;
      }
    }
    printf("%d\n",r);
  }

  return 0;
}
