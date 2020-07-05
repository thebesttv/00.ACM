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

const int MAX = 20;
const int INF = 0x3f3f3f3f;
int n,G[MAX][MAX];
struct Point{
  int x,y;
}t1[MAX],t2[MAX];

bool inBetween(Point p1, Point p2, Point p3){
  int x1 = p1.x - p3.x,
      y1 = p1.y - p3.y,
      x2 = p2.x - p3.x,
      y2 = p2.y - p3.y;

  if(x1*y2 - x2*y1) return false;
  
  return ( p3.x > min(p1.x, p2.x) && p3.x < max(p1.x, p2.x) )
      || ( p3.y > min(p1.y, p2.y) && p3.y < max(p1.y, p2.y) );
}

bool ok(int i, int j){
  FORR(k,1,n) if(k!=i && k!=j)
    if(inBetween(t1[i],t1[j],t1[k]))
      return false;

  FORR(k,1,n)
    if(inBetween(t1[i],t1[j],t2[k]))
      return false;

  return true;
}

int main(void){
  MST(G,0x3f);
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d%d",&t1[i].x,&t1[i].y);
  FORR(i,1,n) scanf("%d%d",&t2[i].x,&t2[i].y);

  FORR(i,1,n) FORR(j,i+1,n) if(ok(i,j)){
    G[i][j] = G[j][i] = 1;
  }

  FORR(i,1,n) FORR(j,1,n) FORR(k,1,n)
    G[i][j] = min(G[i][j], G[i][k]+G[k][j]);

  printf("%d\n",G[1][n]==INF ? -1 : G[1][n]);

  return 0;
}
