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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MOD = 1e9 + 7;
int x, y;

int pow(int a, int x){
  if(x==0) return 1;
  if(x==1) return a;
  int ans = pow(a,x>>1);
  ans = 1ll*ans*ans%MOD;
  if(x&1) ans = 1ll*ans*a%MOD;
  return ans;
}

int mu(int n){
  if(n==1) return 1;
  int r = sqrt(n+0.5), cnt = 0;
  FORR(i,2,r) if(n%i==0){
    n/=i; ++cnt;
    if(n%i==0) return 0;
  }
  if(n>1) ++cnt;
  return cnt&1 ? -1 : 1;
}

int f(int n){
  int r = sqrt(n+0.5);
  int ans = 0;
  FORR(i,1,r) if(n%i==0){
    ans = (ans + 1ll*mu(i)*pow(2,n/i-1) )%MOD;
    if(i*i != n)
      ans = (ans + 1ll*mu(n/i)*pow(2,i-1) )%MOD;
    // printf("  mu(%d): %d, 2^%d\n",i,mu(i),n/i-1);
    // printf("  mu(%d): %d, 2^%d\n",n/i,mu(n/i),i-1);
  }
  ans = (ans+MOD)%MOD;
  return ans;
}

int main(void){
  scanf("%d%d",&x,&y);
  if(x>y || y%x) printf("0\n");
  else printf("%d\n",f(y/x));

  return 0;
}
