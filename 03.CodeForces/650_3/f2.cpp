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

const int MAX = 2e5 + 20;
int n,a[MAX],v[MAX],tail;
VR<int> pos[MAX];

int ID(int x){
  return lower_bound(v,v+tail,x)-v+1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tail = 0; scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]), v[tail++]=a[i], pos[i].clear();
    sort(v,v+tail); tail = unique(v,v+tail)-v;
    FORR(i,1,n) pos[ID(a[i])].push_back(i);
    FORR(i,1,tail) sort(ALL(pos[i]));

#ifdef DEBUG
    FORR(i,1,tail){
      printf("%d:",i);
      for(int x : pos[i]) printf(" %d",x);
      putchar('\n');
    }
#endif

    int tMax = pos[1].size(), cnt = pos[1].size();
    FORR(i,2,tail){
      tMax = max(tMax,(int)pos[i].size());
      if(pos[i-1].back() < pos[i].back()){
        auto it = lower_bound(ALL(pos[i]), pos[i-1].back());
        if(it == pos[i].begin()){
          cnt += pos[i].size(); tMax = max(tMax, cnt);
          continue;
        }
        tMax = max(tMax, cnt + int(pos[i].end() - it));
        cnt = pos[i].size();
      }

      cnt = pos[i].size();
      ROR(j,pos[i-1].size()-2,0){
        auto it = lower_bound(ALL(pos[i]), pos[i-1][j]);
        if(it == pos[i].begin()){
          cnt = pos[i].size() + (j+1); tMax = max(tMax, cnt);
          break;
        }
        tMax = max(tMax, (j+1) + int(pos[i].end() - it));
      }
    }
    printf("%d\n",n-tMax);
  }

  return 0;
}
