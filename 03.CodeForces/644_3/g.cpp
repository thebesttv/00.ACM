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

const int MAX = 60;
int n,m,a,b,G[MAX][MAX];
int r[MAX],c[MAX];

bool ok(){
  MST(r,0), MST(c,0);
  FORR(i,1,n){
    VR<pii> v;
    FORR(j,1,m) v.push_back({j,c[j]});
    sort(ALL(v), [](pii &a, pii &b){
      return a.SE < b.SE;
    });

    int cnt = a;
    for(auto p : v){
      if(p.SE < b && cnt > 0){
        G[i][p.FI]=1; ++r[i], ++c[p.FI];
        --cnt;
      }else G[i][p.FI]=0;
    }
    if(cnt) return false;
  }
  FORR(j,1,m) if(c[j] != b)
    return false;
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(ok()){
      printf("YES\n");
      FORR(i,1,n){
        FORR(j,1,m) putchar('0'+G[i][j]);
        putchar('\n');
      }
    }else printf("NO\n");
  }

  return 0;
}
