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

const int MAX = 5e5 + 20;
int n,m,p[MAX],l[MAX];
VR<int> v;

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) scanf("%d",&p[i]);
  FOR(i,0,m) scanf("%d",&l[i]);
  sort(l,l+m);
  FOR(i,0,n) FOR(j,i+1,n){
    v.push_back(p[j]-p[i]);
  }
  sort(ALL(v));

  if(m > v.size()){
    printf("no\n"); return 0;
  }


  int cnt = 0;
  FOR(i,0,n){
    FOR(j,i+1,n)
      if(p[j] - p[i] <= 43)
        ++cnt;
      else
        break;
    printf("%d\n",cnt);
  }

  return 0;
}
