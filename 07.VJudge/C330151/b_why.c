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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10;
const int to[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n; char G[MAX][MAX];

struct Node{
  int x,y,cnt;
  Node(int x, int y, int cnt): x(x), y(y), cnt(cnt) { }
  bool operator < (const Node &b) const {
    return cnt < b.cnt;
  }
};
VR<Node> v;

int cal(int x, int y){
  int sum=1;
  FOR(i,0,4){
    int tx=x+to[i][0], ty=y+to[i][1];
    while(tx>=1 && tx<=n && ty>=1 && ty<=n){
      if(G[tx][ty]=='.') sum++;
      else break;
      tx+=to[i][0], ty+=to[i][1];
    }
  }
  return sum;
}

bool canPut(int x, int y){
  return G[x][y]=='.';
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    v.clear();
    FORR(i,1,n) scanf("%s",G[i]+1);
    FORR(i,1,n) FORR(j,1,n) if(G[i][j]=='.'){
      v.push_back(Node(i,j,cal(i,j)));
    }
    sort(v.begin(),v.end());

    int cnt=0;
    for(Node t : v) if(canPut(t.x,t.y)){
      G[t.x][t.y]='B'; cnt++;
      FOR(i,0,4){
        int tx=t.x+to[i][0], ty=t.y+to[i][1];
        while(tx>=1 && tx<=n && ty>=1 && ty<=n){
          if(G[tx][ty]=='.') G[tx][ty]='N';  // no putting
          else if(G[tx][ty]!='N') break;  // <b> 战火可能相交,此时没关系 :( </b>
          tx+=to[i][0], ty+=to[i][1];
        }
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
