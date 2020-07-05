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

const int MAX = 520;
char s[20][MAX];
VR<int> st[20];
int n,m;

int len(int n){
  int s = 0;
  while(n) s += n&1, n>>=1;
  return s;
}

int col = 0, vis[MAX];
bool ok(int st){
  ++col;
  FOR(i,0,m) if(st&(1<<i)){
    FOR(j,0,n) if(s[i][j]=='1')
      vis[j] = col;
  }
  FOR(i,0,n) if(vis[i]!=col)
    return false;
  return true;
}

int main(void){
  FOR(i,1,1<<15) st[len(i)].push_back(i);
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FOR(i,0,m) scanf("%s",s[i]);

    bool done = 0;
    FORR(len,1,m){
      for(int x : st[len]) if(ok(x)){
        printf("%d\n",len);
        done = 1; break;
      }
      if(done) break;
    }
    if(!done) printf("-1\n");
  }

  return 0;
}
