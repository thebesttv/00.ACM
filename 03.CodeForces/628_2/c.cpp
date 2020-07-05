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

const int MAX = 1e5 + 20;
int n,d[MAX];
VR<pii> edge;

int main(void){
  scanf("%d",&n);
  int u,v;
  FOR(i,1,n){
    scanf("%d%d",&u,&v);
    edge.push_back({u,v});
    ++d[u], ++d[v];
  }

  int p = -1;
  FORR(i,1,n) if(d[i]>=3){
    p = i; break;
  }

#ifdef DEBUG
  printf("  p: %d\n",p);
#endif
  if(p==-1) FOR(i,0,n-1)
    printf("%d\n",i);
  else{
    int tail = 3, cnt = 0;
    for(auto t : edge){
      if(t.FI != p && t.SE != p){
        printf("%d\n",tail++);
      }else if(cnt<3){
        printf("%d\n",cnt++);
      }else{
        printf("%d\n",tail++);
      }
    }
  }

  return 0;
}
