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

const int MAX = 3020;
int n,a[MAX],pos[MAX],v[MAX],tail;

int ID(int x){
  return lower_bound(v,v+tail,x)-v+1;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    tail = 0; scanf("%d",&n);
    FORR(i,1,n) scanf("%d",&a[i]), v[tail++]=a[i];
    sort(v,v+tail); tail = unique(v,v+tail)-v;
    FORR(i,1,n) pos[ID(a[i])]=i;

    int tMax = 1, cnt = 1;
    FORR(i,2,n){
      if(pos[i] > pos[i-1]) ++cnt;
      else cnt = 1;
      tMax = max(tMax, cnt);
    }
    printf("%d\n",n-tMax);
  }

  return 0;
}
