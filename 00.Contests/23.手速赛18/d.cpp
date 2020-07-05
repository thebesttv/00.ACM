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

const int MAX = 100020, THE = 300;
int n,m,a[MAX],d[THE+10][MAX];

int dp(int p, int k){
  if(p>n) return 0;
  int &aa = d[k][p];
  if(aa!=-1) return aa;
  aa = dp(p+a[p]+k,k) + 1;
  return aa;
}

int cal(int p, int k){
  int s = 0;
  while(p<=n) p += a[p]+k, ++s;
  return s;
}

int main(void){
  MST(d,-1);
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&a[i]);

  int p,k; scanf("%d",&m);
  FOR(i,0,m){
    scanf("%d%d",&p,&k);
    if(k<=THE){
      printf("%d\n",dp(p,k));
    }else{
      printf("%d\n",cal(p,k));
    }
  }

  return 0;
}
