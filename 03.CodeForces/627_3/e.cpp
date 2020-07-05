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

const int MAX = 2020;
int n,h,l,r,f[MAX][MAX],a[MAX];

int main(void){
  MST(f,-1); f[0][0] = 0;
  scanf("%d%d%d%d",&n,&h,&l,&r);
  FORR(i,1,n) scanf("%d",&a[i]);
  FOR(i,0,n) FOR(j,0,h) if(f[i][j]!=-1){
    int t1 = (j+a[i+1])%h,
        t2 = (j+a[i+1]-1+h)%h;
    f[i+1][t1] = max(f[i+1][t1], f[i][j] + (l<=t1 && t1<=r));
    f[i+1][t2] = max(f[i+1][t2], f[i][j] + (l<=t2 && t2<=r));
  }
  int ansMax = 0;
  FOR(j,0,h) ansMax = max(ansMax, f[n][j]);
  printf("%d\n",ansMax);

  return 0;
}
