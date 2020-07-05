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

const int MAX = 2e5 + 20;
int n,q; char s[MAX];
int cnt[26][MAX];

bool ok(int l, int r){
  if(l==r || s[l] != s[r]) return true;
  else{
    int sum = 0;
    FOR(i,0,26) if(cnt[i][r] - cnt[i][l-1])
      ++sum;
    return sum >= 3;
  }
}

int main(void){
  scanf("%s",s+1);
  n = strlen(s+1);
  FORR(i,1,n){
    s[i] -= 'a';
    ++cnt[s[i]][i];
    FOR(j,0,26) cnt[j][i] += cnt[j][i-1];
  }

  int l, r;
  scanf("%d",&q);
  while(q--){
    scanf("%d%d",&l,&r);
    printf("%s\n", ok(l,r) ? "Yes" : "No");
  }

  return 0;
}
