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

const int MAX=100020;
const int INF=0x3f3f3f3f;
int n,m,a[MAX];

int cal(int lim){
  int s=0,cnt=0;
  FOR(i,0,n){
    if(s+a[i]<=lim) s+=a[i];
    else s=a[i], cnt++;
  }
  if(s) cnt++;
  return cnt;
}

int main(void){
  scanf("%d%d",&n,&m);
  int s=0,tMax=0;
  FOR(i,0,n){
    scanf("%d",&a[i]), s+=a[i];
    tMax=max(tMax,a[i]);
  }
  int l=tMax, r=s+1,ans;
  while(l<r){
    int mid=(l+r)/2;
    if(cal(mid)<=m){
      ans=mid; r=mid;
    }else l=mid+1;
  }
  printf("%d\n",ans);

  return 0;
}
