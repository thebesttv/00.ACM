// Tag: 模板 unordered_map
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
#include<unordered_map>
#include<utility>
#include<algorithm>
#include<functional>
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

// 对于 unordered_map，重载等于号，并且定义hash
struct Node{
  int x, y;
  bool operator < (const Node &b) const {
    return x != b.x ? x < b.x : y < b.y;
  }
  bool operator == (const Node &b) const {  // [1]
    return x == b.x && y == b.y;
  }
};

// [2]
namespace std {
  template <> struct hash<Node>{
    size_t operator () (const Node &b) const {
      return hash<int>()(b.x) ^ (hash<int>()(b.y)<<1);
    }
  };
}

map<Node, int> mp;
unordered_map<Node, int> ump;

int get(int x = 1000) { return rand()%x; }

int main(void){
  int n = 1e6;
  FOR(i,0,n){
    Node t; t.x = get(), t.y = get();
    mp[t] = ump[t] = rand();
    if(i % int(1e5) == 0) printf("%d\n",i);
  }

  for(auto p : mp) if(p.SE != ump[p.FI]){
    printf("WRONG\n"); exit(1);
  }

  return 0;
}
