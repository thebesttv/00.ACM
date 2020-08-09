// Tag: 啥玩意 转化 iiii
// 数为节点，(a,b) 为边，如果一个大小为n>1的连通分量为树，则只能选择 n-1 个，否则可以选择 n 个
// 利用并查集维护节点信息
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
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 2e5 + 20;
int n,fa[MAX]; map<int,int> mp;
// fa[x] == -1: size 1, no edge
// fa[x] < -1: size -fa[x], tree
// fa[x] == 0: connected by not tree

int p(int x){
  return fa[x] <= 0 ? x : fa[x] = p(fa[x]);
}

void merge(int x, int y){
  x = p(x), y = p(y);
  if(x == y) { fa[x] = 0; return; }
  if(!fa[x]){ // if either x or y is not tree
    fa[y] = x;
  }else if(!fa[y]){
    fa[x] = y;
  }else{  // tree
    fa[x] += fa[y];
    fa[y] = x;
  }
}

int IDcnt = 0;
int ID(int x){
  if(mp.count(x)) return mp[x];
  return mp[x] = ++IDcnt;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(fa,-1); IDcnt = 0; mp.clear();
    scanf("%d",&n); int a,b;
    while(n--){
      scanf("%d%d",&a,&b);
      merge(ID(a),ID(b));
    }
    int ans = IDcnt;
    FORR(i,1,IDcnt) if(fa[i] < -1) --ans; // tree
    printf("Case #%d: %d\n",kase,ans);
  }

  return 0;
}
