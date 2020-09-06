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
  int n = 1e5; set<pii> st;
  printf("%d\n",n);
  int x = get(1e8), y = get(1e8); deque<pii> v;
  FOR(i,0,int(5e4) - 20){
    printf("add %d %d\n", x + i/224, y + i%224);
    v.push_back({x + i/224, y + i%224});
  }
  FOR(i,0,20){
    random_shuffle(ALL(v));
    printf("remove %d %d\n",v[0].FI,v[0].SE);
    v.pop_front();
  }
  FOR(i,0,int(5e4)){
    int x1 = get(), y1 = get(), x2 = get(), y2 = get();
    if(x1 > x2) swap(x1,x2);
    if(y1 > y2) swap(y1,y2);
    printf("query %d %d %d %d\n",x1,y1,x2,y2);
  }

  return 0;
}
