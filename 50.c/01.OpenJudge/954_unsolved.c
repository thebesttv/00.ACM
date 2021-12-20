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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

typedef long long LL;
const int MAX=5020;
const LL D=(1LL<<60)+7;
int a[MAX],f[MAX],n,ans;
LL g[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  FOR(i,0,n){
    f[i]=1,g[i]=1;
    FOR(j,0,i) if(a[j]>a[i])
      if(f[j]+1>f[i]) f[i]=f[j]+1,g[i]=g[j];
      else if(f[j]+1==f[i]) g[i]++;
    ans=max(ans,f[i]);
  }
  LL sum=0;
  ROR(i,n-1,0) if(f[i]==ans) sum+=g[i];
  printf("%d %lld\n",ans,sum);

  return 0;
}
