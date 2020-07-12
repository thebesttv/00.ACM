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

const int MAX = 128;
int n,lc[MAX],rc[MAX],pos[MAX];
char pre[MAX],in[MAX];

int dfs(int l1, int r1, int l2, int r2){
  if(l1 >= r1 || l2 >= r2) return 0;
  int u = pre[l1], m = pos[u];
  lc[u] = dfs(l1+1, l1+1 + m - l2, l2, m);
  rc[u] = dfs(l1+1 + m - l2, r1, m+1, r2);
  return u;
}

void print(int u){
  if(!u) return;
  print(lc[u]); print(rc[u]); putchar(u);
}

int main(void){
  while(scanf("%s%s",pre,in)==2){
    //MST(lc,0), MST(rc,0);
    n = strlen(pre);
    FOR(i,0,n) pos[in[i]] = i;
    int root = dfs(0,n,0,n);
    print(root); putchar('\n');
  }

  return 0;
}
