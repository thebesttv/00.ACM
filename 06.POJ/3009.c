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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=22;
const int to[4][2]={{0,-1},{0,1},{-1,0},{1,0}};
int n,m,ex,ey;

struct Node{
  int x,y,cnt;
  int G[MAX];
  Node() { MST(G,0); }
};

int main(void){
  while(scanf("%d%d",&m,&n)==2 && m){
    Node s; s.cnt=0; int x;
    FORR(i,1,n) FORR(j,1,m){
      scanf("%d",&x);
      if(x==1) s.G[i]|=(1<<j);
      else if(x==2) s.x=i,s.y=j;
      else if(x==3) ex=i, ey=j;
    }
    queue<Node> q; q.push(s);
    int ans=-1;
    while(!q.empty()){
      Node t=q.front(); q.pop();
      if(t.cnt>=10) continue;
      FOR(k,0,4){
        int tx=t.x+to[k][0], ty=t.y+to[k][1];
        if(tx<1 || tx>n || ty<1 || ty>m || (t.G[tx]&(1<<ty)) )
          continue;
        bool blocked=0;
        while(tx>=1 && tx<=n && ty>=1 && ty<=m){
          if(tx==ex && ty==ey){
            ans=t.cnt+1; break;
          }
          if(t.G[tx]&(1<<ty)){  // hits block
            blocked=1; break;
          }
          tx+=to[k][0], ty+=to[k][1];
        }
        if(ans!=-1) break;
        if(!blocked) continue;
        Node tt=t; tt.G[tx]&=(~(1<<ty));
        tt.x=tx-to[k][0], tt.y=ty-to[k][1];
        tt.cnt = t.cnt+1;
        q.push(tt);
      }
      if(ans!=-1) break;
    }
    printf("%d\n",ans);
  }
  return 0;
}
