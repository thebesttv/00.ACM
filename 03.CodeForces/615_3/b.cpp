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

const int MAX = 1020;
int n;
struct Node{
  int x, y, d;
  bool operator < (const Node &b) const {
    return d < b.d;
  }
}node[MAX];

bool ok(){
  if(node[0].x==0 && node[0].y==0)
    return false;

  FOR(i,1,n){
    int dx = node[i].x - node[i-1].x;
    int dy = node[i].y - node[i-1].y;
    if(dx<0 || dy < 0 || (dx + dy==0))
      return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n){
      scanf("%d%d",&node[i].x,&node[i].y);
      node[i].d = node[i].x + node[i].y;
    }
    sort(node, node+n);

    if(!ok()){
      printf("NO\n"); continue;
    }

    printf("YES\n");
    FOR(i,0,n){
      int dx = i==0 ? node[i].x : (node[i].x - node[i-1].x);
      int dy = i==0 ? node[i].y : (node[i].y - node[i-1].y);
      while(dx){ putchar('R'); --dx; }
      while(dy){ putchar('U'); --dy; }
    }
    putchar('\n');
  }

  return 0;
}
