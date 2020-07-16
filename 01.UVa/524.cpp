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

const int MAX = 20;
int n,a[MAX]; bool vis[MAX], isPrime[40];

bool prime(int n){
  FOR(i,2,n) if(n%i==0) return false;
  return true;
}

void dfs(int cur){
  if(cur == n){
    if(!isPrime[a[0] + a[n-1]]) return;
    printf("1"); FOR(i,1,n) printf(" %d",a[i]); putchar('\n');
    return;
  }

  FORR(i,2,n) if(!vis[i] && isPrime[i + a[cur-1]]){
    vis[i] = 1; a[cur] = i;
    dfs(cur+1);
    vis[i] = 0;
  }
}

int main(void){
  isPrime[2] = 1;
  FOR(i,3,40) isPrime[i] = prime(i);

  int kase = 0;
  while(scanf("%d",&n)==1){
    if(kase) putchar('\n');
    printf("Case %d:\n",++kase);
    if(n == 1) continue;

    a[0] = 1; vis[1] = 1;
    dfs(1);
  }

  return 0;
}
