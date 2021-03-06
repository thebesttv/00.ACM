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

const int MAX=620;
int n,l,a[MAX];

int main(void){
  while(scanf("%d%d",&l,&n)==2){
    int s=0;
    FOR(i,0,n) scanf("%d",&a[i]), s+=a[i];
    if(s<l){
      printf("impossible\n"); continue;
    }
    sort(a,a+n,greater<int>());
    int cnt=0;
    FOR(i,0,n){
      cnt++;
      l = max(l-a[i],0);
      if(l==0) break;
    }
    printf("%d\n",cnt);
  }
  return 0;
}
