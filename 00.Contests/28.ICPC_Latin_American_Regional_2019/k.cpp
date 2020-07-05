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

const int MAX = 1e4 + 20;
int n, sign; char s[MAX];
VR<int> v;
LL res[100];

void cal(int st){
  int l = 0, x = st;
  while(x) l += x&1, x>>=1;
  LL m = 1;
  FOR(i,0,n) if(st&(1<<i)){
    m *= v[i];
  }
  res[l] += m;
}

int main(void){
  scanf("%s",s); n = strlen(s);
  FOR(i,1,n) if(s[i-1] != s[i])
    v.push_back(-2*i-1);
  // sign = s[0]=='A' ? -1 : 1;

  if(!v.size()){
    n=0; res[0] = 1;
    sign = s[0]=='A' ? -1 : 1;
  }else{
    n = v.size();
    FOR(st,0,1<<n)
      cal(st);
    if(n&1){
      sign = s[0]=='A' ? 1 : -1;
    }else{
      sign = s[0]=='A' ? -1 : 1;
    }
  }
  printf("%d\n",n);
  printf("%lld",res[0]*sign);
  FORR(i,1,n) printf(" %lld",res[i]*sign);
  putchar('\n');

  return 0;
}
