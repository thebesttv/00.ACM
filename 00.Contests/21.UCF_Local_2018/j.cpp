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

int cx,cy,c,rx,ry,s;

bool out(int x1, int y1, int x2, int y2, int x, int y){
  if(cx<x1 || cx>x2 || cy<y1 || cy>y2)
    return 0;
  int d2 = (x-cx)*(x-cx) + (y-cy)*(y-cy);
  return d2 > c*c;
}
bool touch(int x1, int y1, int x2, int y2, int x, int y){
  if(cx<x1 || cx>x2 || cy<y1 || cy>y2)
    return 0;
  int d2 = (x-cx)*(x-cx) + (y-cy)*(y-cy);
  return d2 == c*c;
}

int cal(){
  int l = rx - c,
      r = rx + s + c,
      u = ry + s + c,
      d = ry - c;

  if(!(cx>=l && cx<=r && cy<=u && cy>=d))
    return 0;

  if(out(l,d,rx,ry,rx,ry)
  || out(rx+s,d,r,ry,rx+s,ry)
  || out(l,ry+s,rx,u,rx,ry+s)
  || out(rx+s,ry+s,r,u,rx+s,ry+s))
    return 0;

  if(touch(l,d,rx,ry,rx,ry)
  || touch(rx+s,d,r,ry,rx+s,ry)
  || touch(l,ry+s,rx,u,rx,ry+s)
  || touch(rx+s,ry+s,r,u,rx+s,ry+s))
    return 1;

  if(cx==l || cx==r || cy==u || cy==d)
    return 1;

  return 2;
}

int main(void){
  cin >> cx >> cy >> c >> rx >> ry >> s;
  printf("%d\n",cal());

  return 0;
}
