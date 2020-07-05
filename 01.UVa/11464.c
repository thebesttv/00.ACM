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

const int INF=0x3f3f3f3f;
const int MAX=20;
int n,ori[MAX][MAX],a[MAX][MAX];

inline int getbit(int x, int pos){
  return (x>>pos)&1;
}
inline int around(int i, int j){
  int sum=0;
  if(i>0) sum += a[i-1][j];
  if(i+1<n) sum += a[i+1][j];
  if(j>0) sum += a[i][j-1];
  if(j+1<n) sum += a[i][j+1];
  return sum;
}
bool check(int st){
  memcpy(a,ori,SIZ(a));
  FOR(i,0,n){
    a[0][i]=getbit(st,i);
    if(a[0][i] < ori[0][i]) return 0;
  }
  FOR(i,0,n-1) FOR(j,0,n){
    if(around(i,j)&1){
      if(a[i+1][j]==1) return 0;
      else a[i+1][j]=1;
    }
  }
  FOR(j,0,n) if(around(n-1,j)&1) return 0;
  return 1;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FOR(i,0,n) FOR(j,0,n)
      scanf("%d",&ori[i][j]);
    int ans=INF;
    FOR(i,0,(1<<n)) if(check(i)){
      int cnt=0;
      FOR(i,0,n) FOR(j,0,n)
        if(a[i][j]!=ori[i][j]) cnt++;
      ans=min(ans,cnt);
    }
    printf("Case %d: %d\n",kase, ans==INF ? -1 : ans );
  }

  return 0;
}
