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

typedef pair<int,int> pii;
const int MAX = 2000000;
char s[9][5][3];
int vis[MAX],kase;
double f[MAX];
int pow5[10];

void getAvailable(int st, VR<pii> &res){
  VR<pii> v; int j;
  FOR(i,0,9){
    j = st%5;
    if(j) v.push_back({i,j});
    st/=5;
  }
  FOR(i,0,v.size()) FOR(j,i+1,v.size()){
    if(s[v[i].FI][v[i].SE][0] == s[v[j].FI][v[j].SE][0]){
      res.push_back({i,j});
    }
  }
}

double dp(int st){
  double &a = f[st];
  if(vis[st]==kase) return a;
  vis[st] = kase; a = 0;

  VR<pii> ava;
  getAvailable(st, ava);

  if(ava.size()){
    for(auto &p : ava){
      a += dp(st - pow5[p.FI] - pow5[p.SE]);
    }
    a /= ava.size();
  }
  return a;
}

int main(void){
  pow5[0] = 1;
  FORR(i,1,9) pow5[i] = pow5[i-1]*5;

  while(scanf("%s",s[0][1])==1){
    ++kase; vis[0] = kase, f[0] = 1;
    scanf("%s%s%s",s[0][2],s[0][3],s[0][4]);
    FOR(i,1,9) FORR(j,1,4)
      scanf("%s",s[i][j]);
    double ans = dp(pow5[9]-1);
    printf("%.6lf\n",ans);
  }

  return 0;
}
