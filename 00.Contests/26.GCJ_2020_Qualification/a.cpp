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
int n,a[MAX][MAX],cnt[MAX],col[MAX],color;

void count(int x){
  if(col[x] != color)
    col[x] = color, cnt[x]=0;
  ++cnt[x];
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    FORR(i,1,n) FORR(j,1,n) scanf("%d",&a[i][j]);

    int s = 0, r = 0, c = 0;
    FORR(i,1,n) s += a[i][i];

    FORR(i,1,n){
      ++color;
      FORR(j,1,n) count(a[i][j]);
      FORR(j,1,n) if(cnt[j]>1){
        ++r; break;
      }
    }

    FORR(j,1,n){
      ++color;
      FORR(i,1,n) count(a[i][j]);
      FORR(i,1,n) if(cnt[i]>1){
        ++c; break;
      }
    }
    printf("Case #%d: %d %d %d\n",kase,s,r,c);
  }

  return 0;
}
