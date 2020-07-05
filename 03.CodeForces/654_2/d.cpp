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

const int MAX = 320;
int n,k,G[MAX][MAX],r[MAX],c[MAX];

void test(){
  int s = 0, o = 0;
  FORR(i,1,n) FORR(j,1,n)
    s += G[i][j];
  FORR(i,1,n) o += r[i];
  if(s != o) goto BAD;

  FORR(i,1,n){
    s = 0;
    FORR(j,1,n) s += G[i][j];
    if(s != r[i]) goto BAD;
  }

  FORR(j,1,n){
    s = 0;
    FORR(i,1,n) s += G[i][j];
    if(s != r[j]) goto BAD;
  }

  return;
BAD:
  printf("WRONG\n"); exit(1);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    int bs = k / n; k %= n;
    FORR(i,1,n){
      r[i] = c[i] = bs;
      if(k) ++r[i], ++c[i], --k;
    }
    int ans = (r[n]-r[1])*(r[n]-r[1]) * 2;
    PQ<pii> q;
    FORR(i,1,n) q.push({c[i],i});
    MST(G,0);
    FORR(i,1,n){
      FORR(j,1,r[i]){
        pii t = q.top(); q.pop();
        G[i][t.SE] = 1;
        q.push({t.FI-1,t.SE});
      }
    }

    test();

    printf("%d\n",ans);
    FORR(i,1,n){
      FORR(j,1,n) putchar('0' + G[i][j]);
      putchar('\n');
    }
  }

  return 0;
}
