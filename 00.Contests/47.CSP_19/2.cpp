// Tag: notag
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

int n,a,b;
struct Node{
  int p; LL x;
};
deque<Node> v1, v2;

void read(int n, deque<Node> &v){
  int p; LL x;
  while(n--){
    scanf("%d%lld",&p,&x);
    v.pb(Node{p,x});
  }
}

int main(void){
  scanf("%d%d%d",&n,&a,&b);
  read(a,v1), read(b,v2);
  LL ans = 0;
  while(!v1.empty() && !v2.empty()){
    Node &x = v1.front(), &y = v2.front();
    if(x.p == y.p){
      ans += x.x * y.x;
      v1.pop_front(), v2.pop_front();
    }else if(x.p < y.p){
      v1.pop_front();
    }else{
      v2.pop_front();
    }
  }
  printf("%lld\n",ans);

  return 0;
}
