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

const int MAX = 220;
int n,ans[MAX];
struct Node{
  bool used;
  VR<int> v;
}node[MAX];

int vis[MAX], color;
bool fit(int idx, Node &t, int &x){
  color ++; x = -1;
  if(t.v.size() > idx) return false;
  FOR(i,idx - t.v.size() + 1, idx) vis[ans[i]] = color;
  for(int y : t.v) if(vis[y] != color){
    if(x == -1) x = y;
    else return false;
  }
  return true;
}

bool _ok(){
  queue<int> q; int x; ans[n] = -1;
  FORR(i,3,n){
    bool done = 0;
    FOR(j,1,n) if(!node[j].used && fit(i, node[j], x)){
      q.push(j); node[j].used = true;
      ans[i] = x; done = true;
#ifdef DEBUG
    printf("    idx: %d, find match %d\n",i,x);
#endif
      break;
    }
    if(!done) break;
  }
  while(!q.empty()) node[q.front()].used = false, q.pop();
  return ans[n] != -1;
}

bool ok(int idx){
  node[idx].used = true;

  ans[1] = node[idx].v[0];
  ans[2] = node[idx].v[1];
#ifdef DEBUG
  printf("  trying node %d, prefix: %d, %d\n",idx, ans[1],ans[2]);
#endif
  if(_ok()) return true;

  swap(ans[1],ans[2]);
#ifdef DEBUG
  printf("  trying node %d, prefix: %d, %d\n",idx, ans[1],ans[2]);
#endif
  if(_ok()) return true;

#ifdef DEBUG
  printf("  node %d failed\n",idx);
#endif
  node[idx].used = false;
  return false;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);

    FOR(i,1,n){
      node[i].used = false;
      VR<int> &v = node[i].v; v.clear();
      int k,x; scanf("%d",&k);
      while(k--){
        scanf("%d",&x), v.push_back(x);
      }
    }
    if(n == 2){
      printf("%d %d\n",node[1].v[0], node[1].v[1]);
      continue;
    }

    FOR(i,1,n) if(node[i].v.size() == 2 && ok(i)){
      FORR(j,1,n) printf("%d ",ans[j]);
      putchar('\n'); break;
    }
  }

  return 0;
}
