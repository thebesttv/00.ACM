// Tag: i 暴力
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

int n,l,cnt,len; char s[100];

bool dfs(int cur){
  if(cnt++ == n){ // total n+1 times, the 0th time empty string
    len = cur; return true;
  }
  FOR(i,0,l){ // cur: i+'A'
    bool ok = 1; s[cur] = i+'A';
    for(int j=1; j*2 <= cur+1; ++j){
      bool equal = 1;
      FOR(k,0,j) if(s[cur-k] != s[cur-j-k]){
        equal = 0; break;
      }
      if(equal) { ok = 0; break; }
    }
    if(!ok) continue;
    if(dfs(cur+1)) return true;
  }
  return false;
}

int main(void){
  while(scanf("%d%d",&n,&l)==2 && n){
    cnt = 0; dfs(0);
    FOR(i,0,len){
      if(i%4 == 0 && i%64 != 0) putchar(' ');
      putchar(s[i]);
      if(i == 63 || i==len-1) putchar('\n');
    }
    printf("%d\n",len);
  }

  return 0;
}
