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
int n,c0[MAX],c1[MAX]; char s[MAX];

int cnt(int x, int l, int r){
  if(x) return c1[r] - c1[l-1];
  else  return c0[r] - c0[l-1];
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s+1); n = strlen(s+1);
    FORR(i,1,n)
      c0[i] = c0[i-1] + (s[i]=='0'),
      c1[i] = c1[i-1] + (s[i]=='1');

    int ans = min(c0[n], c1[n]);
    FOR(i,1,n){
      ans = min(ans, cnt(0,1,i) + cnt(1,i+1,n));
      ans = min(ans, cnt(1,1,i) + cnt(0,i+1,n));
    }
    printf("%d\n",ans);
  }

  return 0;
}
