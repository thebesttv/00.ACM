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

const int MAX = 1020;
int n,a[MAX],x,cnt0,cnt1;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&x);
    cnt0=cnt1=0;
    FOR(i,0,n) scanf("%d",&a[i]), a[i]&1 ? ++cnt1 : ++cnt0;
    bool ok = 1;
    if((x&1)==0){
      if(!cnt0) ok = 0;
      else --cnt0, --x;
    }
    if(ok){
      while(x >= 3){
        if(cnt0 >= 2){
          x -= 2, cnt0 -= 2;
        }else if(cnt1 >= 2){
          x -= 2, cnt1 -= 2;
        }
      }
      ok = cnt1;
    }

    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}

/*
const int MAX = 1020;
int n,a[MAX],x,cnt0,cnt1;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&x);
    cnt0=cnt1=0;
    FOR(i,0,n) scanf("%d",&a[i]), a[i]&1 ? ++cnt1 : ++cnt0;
    bool ok;
    if(cnt0 >= x-1){
      ok = cnt1;
    }else if(cnt0==0){
      ok = x&1;
    }else{
      int t = (x-cnt0)|1;
      ok = cnt1 >= t;
    }
    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}
*/
