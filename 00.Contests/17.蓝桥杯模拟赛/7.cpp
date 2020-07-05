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

int n, cnt, p[10];

void dfs(int cur, int last, int s){
  if(cur == 6){
#ifdef DEBUG
    printf("  %d\n",s);
#endif
    ++cnt; return;
  }
  FORR(i,last,9)
    if(s + p[5-cur]*i <= n){
      dfs(cur+1,i, s + p[5-cur]*i);
    }else break;
}

int main(void){
  p[0] = 1;
  FOR(i,1,8) p[i] = p[i-1]*10;
  scanf("%d",&n);
  dfs(0, 0, 0);
  --cnt;  // 0
  printf("%d\n",cnt);

  return 0;
}
