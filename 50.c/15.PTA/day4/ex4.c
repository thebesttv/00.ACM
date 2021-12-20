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

const int MAX=20;
int n,m; char G[MAX][MAX];

int main(void){
  cin >> n; n*=2;
  FORR(i,1,n) FORR(j,1,n) cin >> G[i][j];
  cin >> m;

  int x1,y1,x2,y2,ycnt=n*n, wcnt=0;
  while(m-- && ycnt){
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(G[x1][y1] != '*' && G[x1][y1] == G[x2][y2]){
      ycnt-=2; G[x1][y1] = G[x2][y2] = '*';
      if(!ycnt) break;
      FORR(i,1,n){
        putchar(G[i][1]);
        FORR(j,2,n) printf(" %c",G[i][j]);
        putchar('\n');
      }
    }else{
      printf("Uh-oh\n");
      if(++wcnt == 3){
        printf("Game Over\n"); return 0;
      }
    }
  }
  if(!ycnt) printf("Congratulations!\n");

  return 0;
}
