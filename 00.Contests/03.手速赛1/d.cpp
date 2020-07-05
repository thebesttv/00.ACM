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
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define RE register
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;

const int MAX = 520;
int n,m, a[MAX], b[MAX];
int dp[MAX][MAX];
int r[MAX][MAX][2];
VR<int> pos[MAX*2];
VR<int> v;

int IDcnt = 0;
map<int, int> mp;
map<int, int> rmp;
int ID(int n){
  if(!mp.count(n))
    mp[n] = ++IDcnt,
    rmp[IDcnt] = n;
  return mp[n];
}

int f(int i, int j){
  if(a[i] != b[j]) return 0;
  int &ans = dp[i][j];
  if(ans != -1) return ans;

  ans = 1;
  FOR(k,0,i) if(a[k] < a[i]){
    for(int l : pos[a[k]]) if(l < j){
      int t = f(k,l) + 1;
      if(t > ans){
        ans = t;
        r[i][j][0] = k,
        r[i][j][1] = l;
      }
    }
  }
  return ans;
}

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]), v.push_back(a[i]);
  scanf("%d",&m);
  FOR(i,0,m) scanf("%d",&b[i]), v.push_back(b[i]);
  sort(ALL(v));
  for(int i : v){
    ID(i);
  }

  FOR(i,0,n) a[i] = ID(a[i]);
  FOR(i,0,m){
    b[i] = ID(b[i]);
    pos[b[i]].push_back(i);
  }
#ifdef DEBUG
  FOR(i,0,n) printf("%d ",a[i]); putchar('\n');
  FOR(i,0,m) printf("%d ",b[i]); putchar('\n');
#endif

  MST(dp, -1), MST(r,-1);
  int ansMax = 0, ri = -1, rj = -1;
  FOR(i,0,n){
    for(int j : pos[a[i]]){
      int t = f(i, j);
      if(t > ansMax){
        ansMax = t, ri = i, rj = j;
      }
    }
  }

  printf("%d\n",ansMax);

  VR<int> ansv;
  while(ri != -1 && rj != -1){
    ansv.push_back(a[ri]);
    int ti = r[ri][rj][0],
        tj = r[ri][rj][1];
    ri = ti, rj = tj;
  }
  ROR(i,ansv.size()-1,0)
    printf("%d ",rmp[ansv[i]]);
  putchar('\n');

  return 0;
}
