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
int n,m; char G[MAX][MAX];

int main(void){
  scanf("%d%d",&n,&m);
  double sy = 0, l, r;
  int cnt = 0;
  FORR(i,1,n){
    scanf("%s",G[i]+1);
    FORR(j,1,m) if(G[i][j]!='.')
      sy += j, ++cnt;
  }

  FORR(j,1,m) if(G[n][j]!='.'){
    l = j; break;
  }
  ROR(j,m,1) if(G[n][j]!='.'){
    r = j; break;
  }

  string ans;
  if(sy < (l-0.5) * cnt) ans = "left";
  else if(sy > (r+0.5) * cnt) ans = "right";
  else ans = "balanced";
  printf("%s\n",ans.c_str());

  return 0;
}
