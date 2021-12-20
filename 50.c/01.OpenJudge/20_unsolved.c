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

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int n,m,p,b; scanf("%d",&n);
    double ansMax=0; int minB=1<<30,sum=0;
    FOR(i,0,n){
      scanf("%d",&m);
      int tb=0,tsum=0; double t,tans=0;
      FOR(j,0,m){
        scanf("%d%d",&b,&p);
        t=(double)min(minB,b)/(sum+p);
        if(t>tans) {tans=t; tb=min(minB,b); tsum=sum+p;}
      }
      minB=tb; sum=tsum; ansMax=(double)minB/sum;
    }
    printf("%.3lf\n",ansMax);
  }

  return 0;
}
