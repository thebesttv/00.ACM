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

const int MAX = 520;
int n,a[MAX],b;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    int c0 = 0, c1 = 0;
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&b), b ? ++c1 : ++c0;

    bool ok = 1;
    if(!c1 || !c0) FOR(i,1,n) if(a[i-1] > a[i]){
      ok = 0; break;
    }
    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}

/*
const int MAX = 520;
int n,m,a[MAX],b[MAX];
deque<int> v1,v2;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    v1.clear(), v2.clear();
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n){
      scanf("%d",&b[i]);
      if(b[i]==0) v1.push_back(a[i]);
      else        v2.push_back(a[i]);
    }
    bool ok = 1;
    if(v1.size()==0) FOR(i,1,v2.size()) if(v2[i-1] > v2[i]){
      ok = 0; break;
    }
    if(v2.size()==0) FOR(i,1,v1.size()) if(v1[i-1] > v1[i]){
      ok = 0; break;
    }

    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}
*/
