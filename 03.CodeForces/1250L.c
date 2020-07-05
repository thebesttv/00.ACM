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

int a,b,c;

bool ok(int a, int b, int c, int m){
  if(a<=m){
    b -= m-a; b -= m-c;
    return b <= m;
  }else{  // a > m
    if(c>m) return 0;
    a -= m;
    b = max(b-(m-c),0);
    c = 0;
    return a + b <= m;
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    if(a<c) swap(a,c);  // a >= c
    int l = (a+b+c)/3, r = max(a,max(b,c));
    while(l<r){
      int m = (l+r)/2;
      if(ok(a,b,c,m)) r = m;
      else l = m+1;
    }
    printf("%d\n",l);
    /*
    FORR(i,1,a+b+c) if(ok(a,b,c,i)){
      printf("%d\n",i); break;
    }
    */
  }

  return 0;
}
