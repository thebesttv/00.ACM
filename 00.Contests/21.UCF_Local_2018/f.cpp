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

int n,cnt[100],f[2048][100], r[100];
char s[20];

int tail = 0;
void dfs(int cur){
  if(cur==n){
#ifdef DEBUG
    printf("%d:",tail);
    FOR(i,1,100) FOR(j,0,r[i])
      printf(" %d",i);
    putchar('\n');
#endif
    FOR(i,1,100) f[tail][i] = r[i];
    ++tail; return;
  }

  int a = s[cur]-'0';
  if(a){
    ++r[a];
    dfs(cur+1);
    --r[a];
  }else return;

  if(cur+1<n){
    int b = a*10 + s[cur+1]-'0';
    ++r[b];
    dfs(cur+2);
    --r[b];
  }
}

bool ok(int k){
  int s = 0;
  FOR(i,1,100)
    s += max(f[k][i]-cnt[i],0);
  return s<=1;
}

int main(void){
  scanf("%s%d",s,&n);
  FOR(i,0,n){
    int v; scanf("%d",&v);
    ++cnt[v];
  }

  n = strlen(s);
  dfs(0);

  bool done = 0;
  FOR(i,0,tail) if(ok(i)){
    done=1; break;
  }
  printf("%d\n",done);

  return 0;
}
