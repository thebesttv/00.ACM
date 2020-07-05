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
int n,k,s[MAX];

int main(void){
  cin >> n >> k;
  ROR(i,n,1) s[i] = s[i+1] + i;
  double f = 0;
  FOR(i,0,k){
    double t = 0;
    FORR(j,0,n){
      t = max(t, 1.0*s[j+1]/n + j*f/n);
    }
    f = t;
  }
  printf("%.8lf\n",f);

  return 0;
}

/*
const int MAX = 120;
int n,k,ok=0,badCnt=0;
double ave, ans = 0;

double dfs(int cur){
  if(cur == k)
    return ave;
  double s = 1.0 * ok / n;
  s += dfs(cur+1) * badCnt / n;
#ifdef DEBUG
  printf("  dfs(%d): %lf\n",cur,s);
#endif
  return s;
}

int main(void){
  cin >> n >> k;
  ave = (n+1)/2.0;
  FORR(i,1,n)
    if(i >= ave) ok += i;
    else badCnt++;
  ans = dfs(1);
  cout << ans << endl;

  return 0;
}
*/
