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

set<int> st[200];

void print(int l, int r, int dep=0){
  if(l>r) return;
  st[dep].insert(l);
  FOR(i,0,dep) printf("  ");
  if(l<r) printf("(%d, %d) %d\n", l,r,r-l+1);
  else printf("%d\n",l);
  if(l>=r) return;

  int m=(l+r)/2;
  print(l,m,dep+1);
  print(m+1,r,dep+1);
}

int main(void){
  int n;
  while(scanf("%d",&n)==1 && n>0){
    FOR(i,0,200) st[i].clear();

    print(1,n);
    FOR(i,0,20){
      if(st[i].empty()) break;
      printf("%d:",i);
      FORR(j,1,n)
        if(st[i].find(j)!=st[i].end()) printf("%2d ",j);
        else printf("   ");
      putchar('\n');
    }
  }
  return 0;
}
