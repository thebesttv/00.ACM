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

const int MAX = 1e5 + 20;
int n,m,a[MAX],b[MAX];
int v[MAX];

void add(int x, int a){
  while(x<=n){
    v[x] += a;
    x += x&-x;
  }
}
int sum(int x){
  int s = 0;
  while(x>0){
    s += v[x];
    x -= x&-x;
  }
  return s;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(v,0);
    scanf("%d%d",&n,&m);
    map<int,int> mp;
    FORR(i,1,n){
      scanf("%d",&a[i]);
      add(i,1); mp[a[i]]=i;
    }
    FORR(i,1,m) scanf("%d",&b[i]);

    LL ans = 0; int i=1;
    while(i<=m){
      int pos = mp[b[i]], j = i;
      int ahead = sum(pos) - 1;
      ans += ahead * 2;
      while(j<=m && mp[b[j]]<=pos){
        add(mp[b[j]], -1);
        ++j; ans ++;
      }
      i = j;
      //
    }
    printf("%lld\n",ans);
  }
  return 0;
}
