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

const int MAX = 44800;
int d, s[MAX + 20];

int main(void){
  FOR(i,1,MAX) s[i] = s[i-1] + i;
  int T; scanf("%d",&T);
  while(T--){
    int a, b; scanf("%d%d",&a,&b);
    d = abs(a-b);
    int i = lower_bound(s,s+MAX,d) - s;
    while(true){
      if(s[i]%2 == d%2){
        printf("%d\n",i); break;
      }
      ++i;
    }
  }

  return 0;
}

/*
const int MAX = 44800;
int d, a[MAX + 20];
const int vans[] = {
0, 1, 3, 2, 3, 5, 3, 5, 4, 5, 4, 5, 7, 5, 7, 5, 7, 6, 7, 6, 7
};

int main(void){
  FORR(i,1,MAX) a[i] = a[i-1] + i;
  int T; scanf("%d",&T);

  while(T--){
    int ta, tb; scanf("%d%d",&ta,&tb);
    d = abs(ta - tb);

    if(d <= 20){
      printf("%d\n",vans[d]);
      continue;
    }

    int idx = lower_bound(a,a+MAX,d) - a;
    int ans = 0;
    if(a[idx] == d){
      ans = idx;
    }else{
      --idx;
      int nxt = (idx&1) ? idx + 2 : idx + 1;
      int x = (idx&1) ? -1 : 2;
      ans = ((d - a[idx])&1) ? nxt : nxt + x;
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
