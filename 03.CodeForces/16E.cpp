// Tag: 状压DP 概率DP
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

const int MAX = 20;
int n; double f[1<<18], p[MAX][MAX];
bool vis[1<<18]; queue<int> q;

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) FOR(j,0,n)
    scanf("%lf",&p[i][j]);
  int st = (1<<n) - 1;
  f[st] = 1; vis[st] = 1; q.push(st);
  while(!q.empty()){
    st = q.front(); q.pop();
    int c = 0; FOR(i,0,n) c += (st>>i)&1; c = c*(c-1)/2;
    FOR(i,0,n) if(st&(1<<i))
      FOR(j,0,n) if((st&(1<<j)) && i!=j){
        int tst = st ^ (1<<j);
        f[tst] += f[st] * p[i][j] / c;
        if(!vis[tst]) q.push(tst), vis[tst] = 1;
      }
  }
  FOR(i,0,n) printf("%.6lf ",f[1<<i]);
  putchar('\n');

  return 0;
}

/*
const int MAX = 20;
int n; double dp[1<<18], p[MAX][MAX];
bool vis[1<<18];

double f(int st){
  if(vis[st]) return dp[st];
  double &a = dp[st]; vis[st] = 1;
  int c = 0;
  FOR(i,0,n) if(st & (1<<i)){
    FOR(j,0,n) if((st & (1<<j)) == 0)
      a += f(st | (1<<j)) * p[i][j];
    ++c;
  }
  a /= c * (c+1) / 2;
#ifdef DEBUG
  printf("f(");
  FOR(i,0,n) putchar('0' + ((st>>i)&1));
  printf("): %lf\n",a);
#endif
  return a;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) FOR(j,0,n)
    scanf("%lf",&p[i][j]);
  int st = (1<<n) - 1;
  dp[st] = 1; vis[st] = 1;
  FOR(i,0,n) printf("%.6lf ",f(1<<i));
  putchar('\n');

  return 0;
}
*/
