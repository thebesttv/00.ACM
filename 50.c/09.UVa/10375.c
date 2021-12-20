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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10000;
int p,q,r,s;
VR<int> prime,e;
bool vis[MAX+20];

void prime_table(){
  vis[0]=vis[1]=1;
  int sq=sqrt(MAX);
  FORR(i,2,sq) if(!vis[i])
    for(int j=i*i;j<=MAX;j+=i) vis[j]=1;
  FORR(i,2,MAX) if(!vis[i]) prime.push_back(i);
}
void decom(int n, int d){
  FOR(i,0,prime.size()){
    while(n%prime[i]==0) {n/=prime[i]; e[i]+=d;}
    if(n==1) break;
  }
}
inline void add_fact(int n, int d){
  FORR(i,2,n) decom(i,d);
}

int main(void){
  prime_table(); e=prime;

  while(scanf("%d%d%d%d",&p,&q,&r,&s)==4){
    FOR(i,0,prime.size()) e[i]=0;
    add_fact(p,1);
    add_fact(q,-1);
    add_fact(p-q,-1);
    add_fact(r,-1);
    add_fact(s,1);
    add_fact(r-s,1);

    double ans=1;
    /*
    FOR(i,0,prime.size())
      if(e[i]>0) FOR(j,0,e[i]) ans*=prime[i];
      else if(e[i]<0) FOR(j,0,-e[i]) ans/=prime[i];
    */
    FOR(i,0,prime.size()) if(e[i])
      ans*=pow(prime[i],e[i]);
    printf("%.5lf\n",ans);
  }

  return 0;
}
