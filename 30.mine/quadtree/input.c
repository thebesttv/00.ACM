// Tag: 
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

double get() { return 1.0 * rand() / RAND_MAX; }
int get(int x){
  x = get() * x;
  if(get() > 0.5) x = -x;
  return x;
}

int main(void){
  srand(time(NULL));
  int n = 100000; set<pii> st;
  int rng = 1e9;
  printf("%d\n",n);
  while(n--){
    double op = get();
    if(op > 0.9 && !st.empty()){
      int idx = get() * st.size();
      for(auto p : st) if(idx-- == 0){
        printf("remove %d %d\n",p.FI,p.SE);
        st.erase(p); break;
      }
    }else if(op > 0.3){ // add
      int x,y;
      do x = get(rng), y = get(rng); while(st.count({x,y}));
      printf("add %d %d\n",x,y); st.insert({x,y});
    }else{
      int x1 = get(rng), y1 = get(rng);
      int x2 = get(rng), y2 = get(rng);
      if(x1 > x2) swap(x1,x2);
      if(y1 > y2) swap(y1,y2);
      printf("query %d %d %d %d\n",x1,y1,x2,y2);
    }
  }

  return 0;
}
