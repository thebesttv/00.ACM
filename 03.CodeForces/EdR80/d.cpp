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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 3e5 + 20;
int n,m, a[MAX][8];
int vis[1<<9];

int col = 0;
int ri, rj;
bool ok(int x){
  MST(vis,-1);
  FOR(i,0,n){
    int mask = 0;
    FOR(j,0,m) if(a[i][j] >= x)
      mask |= 1 << j;
    vis[mask] = i;
  }

  int dst = (1<<m)-1;
  FOR(i,0,1<<m) FOR(j,0,1<<m)
    if( (i|j)==dst && vis[i]!=-1 && vis[j]!=-1){
      ri = vis[i], rj = vis[j]; return true;
    }
  return false;
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m)
    scanf("%d",&a[i][j]);

  int l = 0, r = 1e9 + 1;
  while(l<r){
    int m = (l+r+1)/2;
    if(ok(m)) l = m;
    else r = m-1;
  }
  printf("%d %d\n",ri+1,rj+1);

  return 0;
}
