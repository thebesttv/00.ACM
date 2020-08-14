// Tag: 状压DP ii TODO
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
#include<functional>
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
#define pb push_back
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

const int MAX = 12;
int n,m; LL f[MAX][1<<MAX];
bool ok[1<<MAX];

void dfs(int cur, int st){
  if(cur == 11) { ok[st]=1; return; }
  dfs(cur+1, st);
  for(int i = cur+2; i <= 11; ++i){
    dfs(i, st | (1<<(i-1)) | (1<<(i-2)));
  }
}

int main(void){
  dfs(0,0);
  while(scanf("%d%d",&n,&m)==2 && n){
    int full = (1<<m)-1;
    MST(f,0); f[0][full] = 1;
    FORR(i,1,n) FOR(st1,0,1<<m){
      LL &a = f[i][st1];
      FOR(st2,0,1<<m) if((st1 & (~st2) & full)==((~st2) & full) && ok[st1&st2]){
#ifdef DEBUG
        if(i == 1) printf("%d <- %d\n",st1,st2);
#endif
        a += f[i-1][st2];
      }
    }
    printf("%lld\n",f[n][(1<<m)-1]);
  }

  return 0;
}

/*
const int MAX = 177147+10;
int n,m; LL f[12][MAX];
int v[11],g[MAX][11]; // 3^11

void dfs(int cur, int st){
  if(cur == 11){
    FOR(i,0,11) g[st][i] = v[10-i];
    return;
  }
  FOR(i,0,3){
    v[cur] = i;
    dfs(cur+1, st*3+i);
  }
}

VR<int> gen(){
  VR<int> v; int rec[11];
  std::function<void(int, int)> f = [&](int cur, int st){
    if(cur == m){
      v.push_back(st); return;
    }
    rec[cur] = 2;
    f(cur+1, st*3+2);

    if(cur + 2 <= m){
      rec[cur] = rec[cur+1] = 1;
      f(cur+2, (st*3+1)*3+1);
    }
  };
  f(0, 0);
  return v;
}

int main(void){
  dfs(0,0);
  while(scanf("%d%d",&n,&m)==2 && n){
    MST(f,-1); f[0][0] = 1;
    LL ans = 0;
    for(int x : gen()) ans += f[n][x];
  }

  return 0;
}
*/
