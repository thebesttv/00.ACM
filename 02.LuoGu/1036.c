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

int n,k,a[40],ans=0;

inline int get_bit(int x, int pos){
  return (x>>pos)&1;
}
inline int set_bit(int x, int pos, int v){
  if(v) return x | (1<<pos);
  else return x & (~(1<<pos));
}
bool prime(int n){
  if(n==2) return 1;
  if(!(n&1)) return 0;
  int t=sqrt(n);
  FORR(i,2,t) if(n%i==0) return 0;
#ifdef DEBUG
  printf("  %d is prime\n",n);
#endif
  return 1;
}

void dfs(int st, int cnt, int cur){
#ifdef DEBUG
  printf("dfs(");
  FOR(i,0,n) printf("%d",get_bit(st,i));
  printf(",%d,%d)\n",cnt,cur);
#endif
  if(cnt==k){
    int sum=0;
    FOR(i,0,cur) if(get_bit(st,i))
      sum+=a[i];
    if(prime(sum)) ans++;
    return;
  }
  if(cur>=n) return;
  if(n-cur > k-cnt) dfs(st,cnt,cur+1); // 0
  dfs(set_bit(st,cur,1), cnt+1, cur+1); // 1
}

int main(void){
  scanf("%d%d",&n,&k);
  FOR(i,0,n) scanf("%d",&a[i]);

  dfs(0,0,0);
  printf("%d\n",ans);

  return 0;
}
