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
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 120;
int n,k,d,len[MAX],sum[MAX];
int cur, p;

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(sum,0);
    scanf("%d%d",&n,&k); --k;
    FOR(i,0,n) scanf("%d",&len[i]);

    printf("CD #%d:\n",kase);
    scanf("%d",&d);
    while(d--){
      sum[k] = 0;
      int s,x; scanf("%d",&s);
      FOR(i,0,s){
        scanf("%d",&x);
        if(i&1){  // leaves
          if(p){
            int left = len[cur]-p;
            if(left > x){ // not enough for one song
              sum[cur] += x;
              continue;
            }else{  // enough
              x -= left;
              sum[cur] += left;
              cur = (cur+1)%n;
              p = 0;
            }
          }
          while(x >= len[cur]){
            x -= len[cur];
            sum[cur] += len[cur];
            cur = (cur+1)%n;
          }

          sum[cur] += x;
        }else{    // enters
          sum[k]+=x;
          p = x % len[k];
          if(!p) cur = (k+1)%n;
          else   cur = k;
        }
      }
      printf("%d\n",sum[k]);
    }
    putchar('\n');
  }

  return 0;
}
