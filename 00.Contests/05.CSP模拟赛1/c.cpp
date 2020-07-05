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
int n,t,k,a,b;

int p[MAX];
int fa(int x){
  return p[x] < 0 ? x : p[x] = fa(p[x]);
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    MST(p,-1);
    scanf("%d%d",&n,&t);
    while(t--){
      scanf("%d%d%d",&k,&a,&b);
      int x = fa(a), y = fa(b);
      if(x == y){
        printf("Yes\n");
      }else{
        printf("No\n");
        p[x] = y;
      }
    }
  }

  return 0;
}
