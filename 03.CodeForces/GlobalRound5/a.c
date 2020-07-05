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
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
typedef long long LL;
typedef long long unsigned LLU;

int n,a,odd;

int main(void){
  scanf("%d",&n);
  while(n--){
    scanf("%d",&a);
    if(a&1){
      if(odd&1){
        a = (a+1)/2;
      }else{
        a = (a-1)/2;
      }
      odd++;
    }else{
      a/=2;
    }
    printf("%d\n",a);
  }

  return 0;
}

/*
const int MAX=20000;
int n,a[MAX],odd=0;

int main(void){
  scanf("%d",&n);
  FORR(i,1,n){
    scanf("%d",&a[i]);
    if(a[i]&1) odd++;
  }
  odd/=2;
  FORR(i,1,n){
    if(a[i]&1){
      if(odd>0) printf("%d\n",(int)floor(a[i]/2.0));
      else printf("%d\n",(int)ceil(a[i]/2.0));
      odd--;
    }else{
      printf("%d\n",a[i]/2);
    }
  }

  return 0;
}
*/
