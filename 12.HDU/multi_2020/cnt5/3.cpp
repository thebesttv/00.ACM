// Tag: 模拟 折纸 啥玩意 iii
// 尼玛，看题解叭
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

VR<int> v[20];
int n,k,pos[12][1040],G[420][1040];
int a[2*200*1024+20];

int main(void){
  v[1].push_back(1); v[1].push_back(2);
  FORR(i,2,10){
    VR<int> &cv = v[i], ov = v[i-1];
    bool st = 0; int r = 1<<(i-1), n = 1<<i;
    for(int i=0;i<r;i+=2) swap(ov[i],ov[i+1]);
    FOR(i,0,r){
      if(!st){
        cv.push_back(n-ov[i]+1);
        cv.push_back(ov[i]);
      }else{
        cv.push_back(ov[i]);
        cv.push_back(n-ov[i]+1);
      }
      st = !st;
    }
#ifdef DEBUG
    if(i > 5) continue;
    printf("%2d:",i); for(int x : cv) printf(" %d",x); putchar('\n');
#endif
  }

  FORR(i,1,10) FOR(j,0,v[i].size())
    pos[i][v[i][j]] = j + 1;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    int siz = 2 * n * (1<<k);
    FORR(i,1,siz) scanf("%d",&a[i]);

    int up = 1, cnt = 0, rng = 1<<k; n*=2;
    FORR(i,1,rng){
      int p = pos[k][i];
#ifdef DEBUG
      printf("  p: %d\n",p);
#endif
      if(up) FORR(j,1,n)
        G[j][p] = a[++cnt];
      else ROR(j,n,1)
        G[j][p] = a[++cnt];
      up = 1^up;
    }

    bool first = true;
    ROR(i,n,1) FORR(j,1,rng){
      if(first) first = false;
      else putchar(' ');
      printf("%d",G[i][j]);
    }
    putchar('\n');
  }

  return 0;
}
