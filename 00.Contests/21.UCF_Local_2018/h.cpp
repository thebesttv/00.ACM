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

int n,m,ok[20];
int ansMin = 0x3f3f3f3f;
bool bad[20];

void dfs(int cur, int s){
  if(s) ansMin = min(ansMin, abs(s-m));
  FOR(i,0,n) if(ok[i]!=0 || (ok[i]==0 && cur)){
    if(s*10 + ok[i] <= 999)
      dfs(cur+1,s*10+ok[i]);
  }
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n){
    int x; scanf("%d",&x);
    bad[x] = 1;
  }

  n = 0;
  FORR(i,0,9) if(!bad[i])
    ok[n++] = i;

  scanf("%d",&m);

  if(n==1 && ok[0]==0){
    printf("%d\n",m);
    return 0;
  }

  dfs(0,0);

  printf("%d\n",ansMin);

  return 0;
}
