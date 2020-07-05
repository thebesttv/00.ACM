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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=50020;
int n,m,L,a[MAX];

int cal(int dis){
  int last=0,cnt=0;
  FORR(i,0,n){
    if(a[i]-last<dis) cnt++;
    else last=a[i];
  }
  return cnt;
}

int main(void){
  scanf("%d%d%d",&L,&n,&m);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n); a[n]=L;
  int l=0, r=L+1, ans;
#ifdef DEBUG
    FORR(mid,0,L) printf("  cal(%d): %d\n",mid,cal(mid));
#endif
  while(l<r){
    int mid=(l+r)/2;
    if(cal(mid)<=m){
      ans=mid; l=mid+1;
    }else r=mid;
  }
  printf("%d\n",ans);

  return 0;
}
