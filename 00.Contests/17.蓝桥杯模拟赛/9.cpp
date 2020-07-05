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

const int MAX = 1020;
const int to[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m,k; char s[MAX];
bool G[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  queue<pii> q, nq;
  FOR(i,0,n){
    scanf("%s",s);
    FOR(j,0,m) if(s[j]=='g'){
      q.push({i,j});
      G[i][j] = 1;
    }
  }
  scanf("%d",&k);

  while(k--){
    while(!q.empty()){
      pii t = q.front(); q.pop();
      FOR(i,0,4){
        int tx = t.FI + to[i][0],
            ty = t.SE + to[i][1];
        if(tx>=0 && tx<n && ty>=0 && ty<m)
          if(G[tx][ty]==0){
            G[tx][ty] = 1;
            nq.push({tx,ty});
          }
      }
    }
    while(!nq.empty()){
      q.push(nq.front());
      nq.pop();
    }
  }

  FOR(i,0,n){
    FOR(j,0,m) putchar(G[i][j] ? 'g' : '.');
    putchar('\n');
  }

  return 0;
}
