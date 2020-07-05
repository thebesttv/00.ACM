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
int n; char G[MAX][MAX],ori[MAX][MAX];

bool canPut(int x, int y){
  FOR(i,0,4){
    int tx=x+to[i][0], ty=y+to[i][1];
    while(tx>=0 && tx<n && ty>=0 && ty<n){
      if(G[tx][ty]=='X') break;
      if(G[tx][ty]!='.') return 0;
      tx+=to[i][0], ty+=to[i][1];
    }
  }
  return true;
}

bool ok(int st){
  memcpy(G,ori,SIZ(ori));
  FOR(i,0,16) if(st&(1<<i)){
    int x=i/4, y=i%4;
    if(G[x][y]!='.') return false;
    G[x][y]='B';
  }
  FOR(i,0,4) FOR(j,0,4) if(G[i][j]=='B')
    if(!canPut(i,j)) return false;
  return true;
}

int main(void){
  while(scanf("%d",&n)==1 && n){
    FOR(i,0,n) scanf("%s",ori[i]);
    int ansMax=0;
    ROR(i,(1<<16)-1,0) if(ok(i)){
      int cnt=0,t=i;
      while(t) cnt+=t&1, t>>=1;
      ansMax=max(ansMax,cnt);
    }
    printf("%d\n",ansMax);
  }

  return 0;
}
