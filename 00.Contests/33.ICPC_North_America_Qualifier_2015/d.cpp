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

const int MAX = 50, THE = 250;
int n;
struct Point{
  int x, y;
}p[MAX];

LL f[42][500][500];

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);

  f[0][0+THE][0+THE] = 1;
  FORR(i,1,n) FORR(dx,-200,200) FORR(dy,-200,200) {
    f[i][dx+THE][dy+THE] = f[i-1][dx+THE][dy+THE]
                         + f[i-1][dx-p[i].x+THE][dy-p[i].y+THE];
  }
  printf("%lld\n",f[n][THE][THE] - 1);

  return 0;
}
