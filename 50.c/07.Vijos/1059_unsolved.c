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

const int MAX=120;
const int MAXH=10020;
int n,a[MAX],cnt[MAXH];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    int tail=1,s=0,t;
    while(1){
      scanf("%d",&t);
      if(t==-1) break;
      s += (a[tail++]=t);
    }
    ROR(j,tail-1,0){
      cnt[s]++; s-=a[j];
    }
  }
  int ans=0;
  ROR(i,MAXH-1,1) if(cnt[i]==n) {ans=i; break;}
  printf("%d\n",ans);

  return 0;
}
