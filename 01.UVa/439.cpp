// Tag: notag
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

const int to[8][2] = {{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
int sx,sy,ex,ey; char s1[3],s2[3];
bool vis[10][10];
struct Node { int x,y,d; };

int main(void){
  while(scanf("%s%s",s1,s2)==2){
    MST(vis,0);
    sx = s1[0] - 'a' + 1;
    sy = s1[1] - '0';
    ex = s2[0] - 'a' + 1;
    ey = s2[1] - '0';
    queue<Node> q; int ans;
    q.push({sx,sy,0}); vis[sx][sy]=1;
    while(!q.empty()){
      Node t = q.front(); q.pop();
      if(t.x == ex && t.y == ey){
        ans = t.d; break;
      }
      FOR(d,0,8){
        int tx = t.x + to[d][0],
            ty = t.y + to[d][1];
        if(tx<1 || tx>8 || ty<1 || ty>8) continue;
        if(vis[tx][ty]) continue;
        q.push({tx,ty,t.d+1}); vis[tx][ty] = 1;
      }
    }
    printf("To get from %s to %s takes %d knight moves.\n",s1,s2,ans);
  }

  return 0;
}
