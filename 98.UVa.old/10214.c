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

const int MAX = 2020;
int a, b; VR<int> v[MAX];

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

LL get(int a, int b){
  LL ans = 0;
  //FORR(i,1,a) FORR(j,1,min(i,b)) if(gcd(i,j)==1){
  FORR(i,1,a) for(int j : v[i]) if(gcd(i,j)==1){
    if(j>b) break;
    ans += (b - j) / i + 1;
  }
  return ans;
}

int main(void){
  FORR(i,1,2000) FORR(j,1,i)
    if(gcd(i,j)==1) v[i].push_back(j);

  while(scanf("%d%d",&a,&b)==2 && a){
    LL k = get(a,b)*4ll + 4;
    LL n = 4ll*a*b + 2ll * (a+b);
    printf("%.7lf\n",1.0*k/n);
  }

  return 0;
}

/*
int a, b;

int gcd(int a, int b){
  return !b ? a : gcd(b,a%b);
}

LL get(int a, int b){
  LL ans = 0;
  FORR(i,1,a) FORR(j,1,min(i,b)) if(gcd(i,j)==1){
    ans += (b - j) / i + 1;
  }
  return ans;
}

int main(void){
  while(scanf("%d%d",&a,&b)==2 && a){
    LL k = get(a,b)*4ll + 4;
    LL n = 4ll*a*b + 2ll * (a+b);
#ifdef DEBUG
    printf("  get %lld, k: %lld, n: %lld\n",get(a,b),k,n);
#endif
    printf("%.7lf\n",1.0*k/n);
  }

  return 0;
}
*/
