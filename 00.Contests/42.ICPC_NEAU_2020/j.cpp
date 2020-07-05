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
int n, a[MAX][4], ans1[MAX][MAX], ans2[MAX][MAX];
int read(){
  char s[10]; scanf("%s",s);
  int ans = 0;
  FOR(i,0,6){
    ans = ans * 16 + (isdigit(s[i]) ? s[i]-'0' : s[i]-'A'+10);
  }
  return ans;
}
bool ok(int x, int y){
  int d1 = abs((x&0xff) - (y&0xff));
  int d2 = abs(((x>>8)&0xff) - ((y>>8)&0xff));
  int d3 = abs(((x>>16)&0xff) - ((y>>16)&0xff));
  return d1 + d2 + d3 >= 128;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FORR(i,1,n) FORR(j,1,3){
      a[i][j] = read();
    }

    FORR(i,1,n) FORR(j,1,n) if(i!=j){
      bool done = 0;
      ans1[i][j] = ans2[j][i] = 0;
      FORR(x,1,3){
        FORR(y,1,3) if(ok(a[i][x], a[j][y])){
          ans1[i][j] = x; ans2[j][i] = y;
#ifdef DEBUG
          printf("  (%d, %d): %d, %d\n",i,j,x,y);
#endif
          done = 1; break;
        }
        if(done) break;
      }
    }

    FORR(i,1,n){
      FORR(j,1,n) printf("%d ",ans1[i][j]);
      putchar('\n');
    }
    FORR(i,1,n){
      FORR(j,1,n) printf("%d ",ans2[i][j]);
      putchar('\n');
    }
  }

  return 0;
}
