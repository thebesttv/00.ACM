// Tag: 概率DP
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

const int MAX = 1020;
int w,b; double dp[MAX][MAX][2];  // 0: princess, 1: dragon
bool vis[MAX][MAX][2];

double f(int w, int b, int st){
  if(!w && !b) return 0;
  double &a = dp[w][b][st];
  if(vis[w][b][st]) return a;
  vis[w][b][st] = 1;

  if(!st){  // princess
    a += 1.0 * w / (w+b);
    if(b) a += f(w, b-1, 1) * b / (w+b);
  }else{    // dragon
    if(b){
      if(w) a += f(w-1, b-1, 0) * w / (w+b-1);
      if(b-1) a += f(w, b-2, 0) * (b-1) / (w+b-1);
      a *= 1.0 * b / (w+b);
    }
  }
#ifdef DEBUG
  printf("f[%d][%d][%d]: %.2lf\n",w,b,st,a);
#endif
  return a;
}

int main(void){
  scanf("%d%d",&w,&b);
  printf("%.10lf\n",f(w,b,0));

  return 0;
}
