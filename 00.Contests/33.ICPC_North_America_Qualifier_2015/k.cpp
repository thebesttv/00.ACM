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
int n,fa[MAX];
struct Node{
  int x,y,r;
}node[MAX];

int p(int x){
  return fa[x] < 0 ? x : fa[x] = p(fa[x]);
}
void merge(int x, int y){
  x = p(x), y = p(y);
  if(x==y) return;
  fa[x] = y;
}

bool cross(const Node &a, const Node &b){
  int r2 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
  return r2 < (a.r+b.r)*(a.r+b.r);
}

int main(void){
  MST(fa,-1); scanf("%d",&n);
  int x, y, r, LEFT = n+1, RIGHT = n+2, ans = 0;
  FORR(i,1,n){
    scanf("%d%d%d",&x,&y,&r);
    if(x - r < 0) merge(i,LEFT);
    if(x + r > 200) merge(i, RIGHT);
    node[i] = {x,y,r};
    FOR(j,1,i) if(cross(node[i], node[j]))
      merge(i,j);

    if(p(LEFT) == p(RIGHT))
      break;
    ans = i;
  }

  printf("%d\n",ans);

  return 0;
}
