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

const int MAX = 40;
int n;
struct Cir{
  int x,y,r,r2;
}cir[MAX];

bool conf(Cir &a, Cir &b){
  int d2 = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  return d2 < (a.r+b.r)*(a.r+b.r);
}

bool ok(int st){
  FOR(i,0,n) if(st&(1<<i))
    FOR(j,i+1,n) if(st&(1<<j))
      if(conf(cir[i],cir[j]))
        return false;
  return true;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d%d%d",&cir[i].x,&cir[i].y,&cir[i].r);
    cir[i].r2 = cir[i].r * cir[i].r;
  }

  int ansMax = 0;
  FOR(st,1,(1<<n)) if(ok(st)) {
    int sum = 0;
    FOR(j,0,n) if(st&(1<<j))
      sum += cir[j].r2;
    ansMax = max(ansMax, sum);
  }

  printf("%d\n",ansMax);

  return 0;
}
