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

const int MAX = 1e5 + 20;
int n, kase, ans[MAX];

int compv[MAX];
struct Node{
  int a, b, c, n, ord;
  bool operator < (const Node &t) const {
    static int compCnt = 0;
    compv[a] = compv[b] = compv[c] = ++compCnt;
    int cnt = 0;
    if(compv[t.a] == compCnt) ++cnt;
    if(compv[t.b] == compCnt) ++cnt;
    if(compv[t.c] == compCnt) ++cnt;
    return cnt >= 1;
  }
}node[MAX];

struct List{
  int v; List *next;
  List(int v): v(v), next(nullptr) { }
}*mp[MAX];
int color[MAX];

int count(Node *p, List *&p1, List *&p2, List *&p3){
  int cnt = 0;
  p1 = p2 = nullptr;
  if(color[p->a]==kase){
    ++cnt;
    p1 = mp[p->a];
  }
  if(color[p->b]==kase){
    ++cnt;
    if(!p1) p1 = mp[p->b];
    else{
      p2 = mp[p->b];
      p3 = new List(p->c);
    }
  }
  if(color[p->c]==kase){
    ++cnt;
    if(p1){
      p2 = mp[p->c];
      if(p1->v == p->a){
        p3 = new List(p->b);
      }else{
        p3 = new List(p->a);
      }
    }
  }
  return cnt;
}

int main(void){
  int T; scanf("%d",&T);
  srand(~T);
  for(kase=1;kase<=T;++kase){
    scanf("%d",&n);
    queue<Node *> q;
    FOR(i,0,n-2){
      Node *p = node + i;
      scanf("%d%d%d",&p->a, &p->b, &p->c);
      p->n = i + 1; p->ord = -1;
      q.push(node + i);
    }
    // sort(node, node + n-2);
    random_shuffle(node, node + n - 2);

    int tail = 0;
    Node *p = q.front(); q.pop();
    p->ord = tail++;
    List *p1 = new List(p->a),
         *p2 = new List(p->b),
         *p3 = new List(p->c);
    p1->next = p2, p2->next = p3, p3->next = p1;
    mp[p->a] = p1, mp[p->b] = p2, mp[p->c] = p3;
    color[p->a] = color[p->b] = color[p->c] = kase;

    while(!q.empty()){
      p = q.front(); q.pop();
      int cnt = count(p, p1, p2, p3);
      if(cnt == 2){
        mp[p3->v] = p3;
        color[p3->v] = kase;

        p->ord = tail++;
        if(p1->next->v != p2->v)
          swap(p1, p2);
        p1->next = p3;
        p3->next = p2;
      }else q.push(p);
    }

    FOR(i,0,n-2){
      Node *p = node + i;
      ans[p->ord] = p->n;
    }
    p1 = mp[1];
    FOR(i,0,n){
      printf("%d ",p1->v);
      p1 = p1->next;
    }
    putchar('\n');
    ROR(i,n-3, 0){
      printf("%d ",ans[i]);
    }
    putchar('\n');
  }

  return 0;
}

/*
const int MAX = 1e5 + 20;
int n, ans[MAX];

struct Node{
  int a, b, c, n, ord;
}node[MAX];

struct List{
  int v; List *next;
  List(int v): v(v), next(nullptr) { }
};
map<int, List*> mp;

int count(Node *p, List *&p1, List *&p2, List *&p3){
  int cnt = 0;
  p1 = p2 = nullptr;
  if(mp.count(p->a)){
    ++cnt;
    p1 = mp[p->a];
  }
  if(mp.count(p->b)){
    ++cnt;
    if(!p1) p1 = mp[p->b];
    else{
      p2 = mp[p->b];
      p3 = new List(p->c);
    }
  }
  if(mp.count(p->c)){
    ++cnt;
    if(p1){
      p2 = mp[p->c];
      if(p1->v == p->a){
        p3 = new List(p->b);
      }else{
        p3 = new List(p->a);
      }
    }
  }
  return cnt;
}

int main(void){
  int T; scanf("%d",&T);
  srand(~T);
  while(T--){
    mp.clear();
    scanf("%d",&n);
    queue<Node *> q;
    FOR(i,0,n-2){
      Node *p = node + i;
      scanf("%d%d%d",&p->a, &p->b, &p->c);
      p->n = i + 1; p->ord = -1;
      q.push(node + i);
    }
    random_shuffle(node, node + n - 2);

    int tail = 0;
    Node *p = q.front(); q.pop();
    p->ord = tail++;
    List *p1 = new List(p->a),
         *p2 = new List(p->b),
         *p3 = new List(p->c);
    p1->next = p2, p2->next = p3, p3->next = p1;
    mp[p->a] = p1, mp[p->b] = p2, mp[p->c] = p3;

    while(!q.empty()){
      p = q.front(); q.pop();
      int cnt = count(p, p1, p2, p3);
      if(cnt == 2){
        mp[p3->v] = p3;

        p->ord = tail++;
        if(p1->next->v != p2->v)
          swap(p1, p2);
        p1->next = p3;
        p3->next = p2;
      }else q.push(p);
    }
    FOR(i,0,n-2){
      Node *p = node + i;
      ans[p->ord] = p->n;
    }
    p1 = mp[1];
    FOR(i,0,n){
      printf("%d ",p1->v);
      p1 = p1->next;
    }
    putchar('\n');
    //FOR(i,0,n-2){
    ROR(i,n-3, 0){
      printf("%d ",ans[i]);
    }
    putchar('\n');
  }

  return 0;
}
*/
