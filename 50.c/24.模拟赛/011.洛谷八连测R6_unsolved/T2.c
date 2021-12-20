#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=2020;
const int MOD=1000000007;
int n,cnt;
int l[MAX],r[MAX];
bool G[MAX][MAX];
int rec[MAX];

bool check(int S){
  int ce=0,vis=0;
  int cnt=0; FOR(i,0,n) if((S>>i)&1) cnt++;
  if(cnt==1) return true;
  FOR(i,0,n) if((S>>i)&1){
    FOR(j,i+1,n) if((S>>j)&1 && G[i][j]) ce++,vis|=(1<<i),vis|=(1<<j);
    if(ce>=cnt) return false;
  }
  return vis==S && ce==cnt-1;
}

void dfs(int cur, int step){
#ifdef DEBUG
  FOR(i,0,step) printf(" %d",rec[i]); printf("\n");
#endif
  cnt = cnt+1==MOD ? 0 : cnt+1;
  FOR(i,cur+1,n){
    int tcnt=0;
    for(int j=0;j<step && tcnt<2;j++)
      if(G[rec[j]][i]) tcnt++;
    if(tcnt!=1) continue;
    rec[step]=i; dfs(i,step+1);
  }
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d%d",&l[i],&r[i]);
  FOR(i,0,n) FOR(j,i+1,n){
    if(l[j]>r[i] || r[j]<l[i]) continue;
    G[i][j]=G[j][i]=1;
  }

  if(n<=20){
    FOR(S,1,1<<n) if(check(S)){
      cnt++;
    }
    printf("%d\n",cnt);
  }else{
    FOR(i,0,n) {rec[0]=i; dfs(i,1);}
    printf("%d\n",cnt);
  }

  return 0;
}
