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
const int maxn=1e5+5;
LL x[maxn];
LL s[maxn];

int main()
{
  int T;scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int a,b,d,r;scanf("%d%d%d",&a,&b,&d);
    int n=a;
    for(int i=1;i<=a;i++)
    {
      scanf("%lld",&x[i]);
      s[i]=s[i-1]+x[i];
    }
    r=s[a-1]+b;
    while(d--)
    {
      if(s[a-1]+b==a)break;
      if(a==b&&b==1)break;
      int p=a;
      a=lower_bound(s+1,s+1+n,a)-s;
      b=p-s[a-1];
    }
    printf("Case #%d: %d-%d\n",t,a,b);
  }
}














