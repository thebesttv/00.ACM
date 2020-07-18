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

const int MAX = 120;
int n,a[MAX],b[MAX]; bool vis[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n); MST(vis,0);
    FOR(i,0,n*2) scanf("%d",&a[i]);
    int tail = 0;
    FOR(i,0,n*2) if(!vis[a[i]]){
      vis[a[i]] = 1; b[tail++] = a[i];
    }
    FOR(i,0,n) printf("%d ",b[i]); putchar('\n');
  }

  return 0;
}
