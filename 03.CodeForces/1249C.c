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

LL cal(LL n){
  VR<int> v;
  while(n){
    v.push_back(n%3);
    n/=3;
  }
#ifdef DEBUG
  printf("ori: ");for(int x : v) printf("%d",x);
  putchar('\n');
#endif
  int i = 0; while(i<v.size() && !v[i]) i++;
  while(i<v.size()){
    int j = i; bool has2=0;
    while(j<v.size() && v[j]){
      if(v[j]==2) has2=1;
      j++;
    }
#ifdef DEBUG
    printf("  %d, %d, has2: %d\n",i,j,has2);
#endif

    if(!has2){
      i = j;
      while(i<v.size() && !v[i]) i++;
      continue;
    }
    //FOR(k,i,j) v[k]=0;
    FOR(k,0,j) v[k]=0;
    if(j==v.size()) v.push_back(1);
    else v[j]=1;
    i = j;
  }
#ifdef DEBUG
  printf("res: ");for(int x : v) printf("%d",x);
  putchar('\n');
#endif

  LL sum = 0;
  ROR(i,v.size()-1,0){
    sum = sum*3 + v[i];
  }
  return sum;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    LL n; scanf("%lld",&n);
    printf("%lld\n",cal(n));
  }

  return 0;
}
