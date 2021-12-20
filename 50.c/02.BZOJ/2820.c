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
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10000020;
int t,n,m;
int prime[MAX],tail,mu[MAX],g[MAX],s[MAX];
bool vis[MAX];

void mu_g_table(int n){
  mu[1]=1;
  FORR(i,2,n){
    if(!vis[i]){
      prime[tail++]=i; mu[i]=-1; g[i]=1;
    }
    int t;
    FOR(j,0,tail){
      t=i*prime[j];
      if(t>n) break;
      vis[t]=1;
      if(i%prime[j]==0){
        mu[t]=0;
        g[t]=mu[i];
        break;
      }else{
        mu[t]=-mu[i];
        g[t]=mu[i]-g[i];
      }
    }
    s[i]=s[i-1]+g[i];
  }
}
LL f(LL n, LL m){
  if(n>m) swap(n,m);
  LL ans=0; int j;
  for(int i=1;i<=n;i=j+1){
    j=min(n/(n/i),m/(m/i));
    ans+=(s[j]-s[i-1])*(n/i)*(m/i);
  }
  return ans;
}

int main(void){
  mu_g_table(MAX-20);
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    printf("%lld\n",f(n,m));
  }

  return 0;
}

/*
void mu_table(int n){
  mu[1]=1;
  FORR(i,2,n){
    if(!vis[i]){
      prime[tail++]=i; mu[i]=-1;
    }
    int t;
    FOR(j,0,tail){
      t=i*prime[j];
      if(t>n) break;
      vis[t]=1;
      if(i%prime[j]==0){
        mu[t]=0; break;
      }else{
        mu[t]=-mu[i];
      }
    }
  }
}
void g_table(int n){
  int p;
  FOR(i,0,tail){
    p=prime[i];
    for(int j=p,cnt=1;j<=n;j+=p,cnt++){
      g[j]+=mu[cnt];
    }
  }
  FORR(i,1,n) s[i]=s[i-1]+g[i];
}
LL f(LL n, LL m){
  if(n>m) swap(n,m);
  LL ans=0; int j;
  for(int i=1;i<=n;i=j+1){
    j=min(n/(n/i),m/(m/i));
    ans+=(s[j]-s[i-1])*(n/i)*(m/i);
  }
  return ans;
}

int main(void){
  mu_table(MAX-20); g_table(MAX-20);
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    printf("%lld\n",f(n,m));
  }

  return 0;
}
*/
