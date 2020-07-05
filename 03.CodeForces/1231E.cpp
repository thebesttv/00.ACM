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

const int MAX = 120;
int n; char s[MAX], t[MAX];
int cnt1[128], cnt2[128];

bool bad(){
  MST(cnt1, 0), MST(cnt2, 0);
  FOR(i,0,n) ++cnt1[s[i]], ++cnt2[t[i]];
  FORR(i,'a','z') if(cnt1[i] != cnt2[i])
    return true;
  return false;
}

bool ok(int l, int r){
  int tail = l;
  FOR(i,0,n) if(tail < n && s[i] == t[tail]){
    ++tail;
  }
  return tail > r;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%s%s",&n,s,t);
    if(bad()){
      printf("-1\n"); continue;
    }
    int ansMin = n;
    FOR(i,0,n) FOR(j,i,n) if(ok(i,j)){
      ansMin = min(ansMin, n - (j-i+1));
    }
    printf("%d\n",ansMin);
  }

  return 0;
}
