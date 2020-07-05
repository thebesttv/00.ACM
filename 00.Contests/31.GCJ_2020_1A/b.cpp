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

int n;

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d",&n);
    printf("Case #%d:\n",kase);
    if(n<=500){
      FORR(i,1,n) printf("%d %d\n",i,1);
      continue;
    }
    int x = n - 30;
    int s = 0, line = 1, dir = 1;
    while(x){
      if(x&1){
        if(dir==1) FORR(i,1,line)
          printf("%d %d\n",line,i);
        else ROR(i,line,1)
          printf("%d %d\n",line,i);
        dir = -dir;
        s += 1<<(line-1);
      }else{
        if(dir==1) printf("%d %d\n",line,1);
        else printf("%d %d\n",line,line);
        ++s;
      }
      x >>= 1; ++line;
    }
    while(s < n){
      printf("%d %d\n",line, dir==1 ? 1 : line);
      ++line; ++s;
    }
  }

  return 0;
}
