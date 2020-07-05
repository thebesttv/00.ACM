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

const int MAX = 120;
const int to[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const char output[4] = {'R','D','L','U'};
int n,m,k,len;
char G[MAX][MAX], s[MAX];
VR<pii> pos[128];

bool ok(int x, int y, int d){
  FOR(i,0,len){
    if(G[x][y] != s[i]) return 0;
    x = (x + to[d][0] + n)%n;
    y = (y + to[d][1] + m)%m;
  }
  return 1;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    FORR(i,'A','Z') pos[i].clear();
    scanf("%d%d",&n,&m);
    FOR(i,0,n){
      scanf("%s",G[i]);
      FOR(j,0,m) pos[G[i][j]].push_back({i,j});
    }

    scanf("%d",&k);
    printf("Word search puzzle #%d:\n",kase);
    while(k--){
      scanf("%s",s);
      len = strlen(s);
      bool done = 0;
      for(auto p : pos[s[0]]){
        FOR(d,0,4) if(ok(p.FI,p.SE,d)){
          printf("%c %d %d %s\n",output[d],p.FI+1,p.SE+1,s);
          done = 1; break;
        }
        if(done) break;
      }
    }
    putchar('\n');
  }

  return 0;
}
