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

const int MAX=200020;
int n,h,v[MAX];

inline bool isOut(int h){
  int i = lower_bound(v,v+n,h)-v;
  return v[i]==h;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&h,&n);
    FOR(i,0,n) scanf("%d",&v[i]);
    reverse(v,v+n);

    int cnt=0;
    while(h>2){
      if(!isOut(h-1)) h--;
      else{
        if(!isOut(h-2)) cnt++;
        h-=2;
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}
