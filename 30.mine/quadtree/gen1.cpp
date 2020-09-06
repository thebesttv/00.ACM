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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int RNG = 1e9;

double _get() { return 1.0 * rand() / RAND_MAX; }
int get(int x = RNG){
  x = _get() * x;
  if(_get() > 0.5) x = -x;
  return x;
}

int main(int argc, char *argv[]){
  srand(time(NULL));
  // argv[1:3]: add, remove, query 的权重（整数）
  int a = atoi(argv[1]), r = atoi(argv[2]), q = atoi(argv[3]);
  int sum = a + r + q;
  double pr = 1.0 * r / sum, pa = 1.0 * a / sum + pr;
  int n = 1e5; set<pii> st;
  printf("%d\n",n);
  while(n--){
    double op = _get();
    if(op <= pr && !st.empty()){  // remove
      int idx = _get() * st.size();
      for(auto p : st) if(idx-- == 0){
        printf("remove %d %d\n",p.FI,p.SE);
        st.erase(p); break;
      }
    }else if(op <= pa){ // add
      int x,y;
      do x = get(), y = get(); while(st.find({x,y}) != st.end());
      printf("add %d %d\n",x,y); st.insert({x,y});
    }else{  // query
      int x1 = get(), y1 = get();
      int x2 = get(), y2 = get();
      if(x1 > x2) swap(x1,x2);
      if(y1 > y2) swap(y1,y2);
      printf("query %d %d %d %d\n",x1,y1,x2,y2);
    }
  }

  return 0;
}
