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

const int MAX=100020;
int n,m;
bool bad[MAX];

void initPrime(int n, VR<int> &prime, VR<int> &cnt){
  int r = sqrt(n+0.5);
  FORR(i,2,r) if(n%i==0){
    prime.push_back(i); int c = 0;
    while(n%i==0) n/=i, ++c;
    cnt.push_back(c);
    if(n==1) return;
  }
  if(n>1) prime.push_back(n), cnt.push_back(1);
}

int main(void){
  while(scanf("%d%d",&n,&m)==2){
    if(m==1){
      printf("0\n\n"); continue;
    }

    MST(bad,0);

    --n;
    VR<int> prime,cntM,ans;
    initPrime(m,prime,cntM);

    FOR(i,0,prime.size()){
      int p = prime[i], cnt = 0, x;
      //FORR(k,1,n){
      FOR(k,1,n){
        x = n-k+1;
        while(x%p==0) x/=p, ++cnt;
        x = k;
        while(x%p==0) x/=p, --cnt;
        if(cnt < cntM[i]) bad[k]=1;
      }
    }

    FOR(k,1,n) if(!bad[k])
      ans.push_back(k+1);

    printf("%d\n",(int)ans.size());
    if(ans.size()){
      printf("%d",ans[0]);
      FOR(i,1,ans.size()) printf(" %d",ans[i]);
    }
    putchar('\n');
  }

  return 0;
}

/*
const int MAX=100000;
int n,m; bool vis[MAX+20];
VR<int> prime;
int cnt[MAX],cntM[MAX];

bool add(int n, int d, int *v){
  if(n==1) return 1;
  FOR(i,0,prime.size()) if(n%prime[i]==0){
    while(n%prime[i]==0){
      n/=prime[i], v[i]+=d;
    }
    if(n==1) return true;
  }
  return n==1;
}

VR<int> rM;
bool ok(){
  for(int i : rM) if(cnt[i] < cntM[i])
    return false;
  return true;
}

int main(void){
  FORR(i,2,MAX) if(!vis[i]){
    prime.push_back(i);
    for(LL j=LL(i)*i;j<=MAX;j+=i) vis[j]=1;
  }

  while(scanf("%d%d",&n,&m)==2){
    --n;

    MST(cnt,0), MST(cntM,0); rM.clear();
    if(!add(m,1,cntM)){
      printf("0\n\n"); continue;
    }
    FOR(i,0,prime.size()) if(cntM[i])
      rM.push_back(i);

    VR<int> ans;
    FORR(k,1,n){
      add(n-k+1,1,cnt);
      add(k,-1,cnt);
      if(ok()) ans.push_back(k+1);
    }

    printf("%d\n",ans.size());
    if(ans.size()){
      printf("%d",ans[0]);
      FOR(i,1,ans.size()) printf(" %d",ans[i]);
    }
    putchar('\n');
  }

  return 0;
}
*/
