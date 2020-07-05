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

int n;
LLU base; // biggest possible + 1

LLU clear(LLU a){
  while(a>=base) a/=10;
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    map<LLU,bool> mp;
    LLU k1,k2,tMax=0;
    scanf("%d%llu",&n,&k1);
    tMax=k2=k1;
    base=1; FOR(i,0,n) base*=10;

    do{
      k1 = clear(k1*k1); //tMax=max(k1,tMax);
      k2 = clear(k2*k2); tMax=max(tMax,k2);
      k2 = clear(k2*k2); tMax=max(tMax,k2);
    }while(k1!=k2);

    printf("%llu\n",tMax);
  }

  return 0;
}

/*
int n;
LLU base; // biggest possible + 1

LLU clear(LLU a){
  while(a>=base) a/=10;
  return a;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    map<LLU,bool> mp;
    LLU k,tMax=0;
    scanf("%d%llu",&n,&k);
    base=1; FOR(i,0,n) base*=10;

    while(!mp.count(k)){
      mp[k]=1; tMax=max(tMax,k);
      k=clear(k*k);
    }
    printf("%llu\n",tMax);
  }

  return 0;
}
*/
