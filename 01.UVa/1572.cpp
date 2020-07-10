// Tag: 点边互化 循环节 iiii
// Link: [UVa 10129]
/*
如果能从一个正方形开始连接，最后回到它，则可以无限循环
虽然两个正方形相连时没有方向，但有了起点和终点，所以连边都为有向边
在连边的时候有两个限制条件：
  1. 有向边头尾指向的标号相匹配，即 A+ -> A-, B- -> B+
  2. 从一面进入正方形，要从另外三面出去，因为进入的一面已经被占用
这样判断有无环即可，但显然复杂度不行
因为标号只有 26 对，想办法把标号变为点，这样就只有 52 个点
和之前一样考虑环，但关注有向边头或尾指向的标号的转移，即
  [A+] -> [A- B+] -> [B- C+] -> [C- A-] -> [A+]
  共有4条边，如果统一考虑入边（头），标号的转移即为
    A- -> B- -> C- -> A+
  统一考虑出边（尾），标号的转移即为
    A+ -> B+ -> C+ -> A-
任选一种即可

正方形内部作为边，连边时，一面作为之前的入边，另一面作为之前的出边（边连接两个正方形）
也就是说如果两面为 [B+ -> D-]，在考虑入边时，B+ 本身即为入边，D- 作为出边，对应入边为 D+
因此连边为 B+ -> D+
反向，[B+ <- D-]，连边为 B- <- D-

因为标号为点，被两边相连后默认匹配，之前第一个限制条件也就满足了
第二个限制条件转化为，一面不能和自己连边

最后判有向环即可
*/
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

int n,c[60]; char s[10];
VR<int> G[60];

int toNum(char *s){
  return (s[0]-'A')*2 + (s[1]=='-');
}

bool topo(int u){
  if(c[u] == 1) return true;
  c[u] = -1;
  for(int v : G[u])
    if(c[v] == -1) return false;
    else if(c[v]==0 && !topo(v)) return false;
  c[u] = 1;
  return true;
}

int main(void){
  while(scanf("%d",&n)==1){
    MST(c,0);
    FOR(i,0,52) G[i].clear();
    while(n--){
      scanf("%s",s);
      for(int i=0;i<8;i+=2) if(s[i]!='0')
        for(int j=i+2;j<8;j+=2) if(s[j]!='0'){
          G[toNum(s+i)^1].push_back(toNum(s+j));
          G[toNum(s+j)^1].push_back(toNum(s+i));
        }
    }

    FOR(i,0,26*2) sort(ALL(G[i])), G[i].erase(unique(ALL(G[i])), G[i].end());
    bool ok = 0;
    FOR(i,0,52) if(!topo(i)){
      ok = 1; break;
    }
    printf("%s\n", ok ? "unbounded" : "bounded");
  }

  return 0;
}
