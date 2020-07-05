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

const int MAX = 40;
int n,k; char s[MAX];

bool vis[MAX];
bool ok(int st){
  MST(vis,0);
  FOR(i,0,n) if(st&(1<<i)){
    if(s[i]=='1'){
      int l = max(0, i-k),
          r = min(n-1, i+k);
      FORR(j,l,r) vis[j]=1;
    }else{
      vis[i] = 1;
    }
  }

  FOR(i,0,n) if(!vis[i])
    return false;
  return true;
}

int main(void){
  scanf("%d%d",&n,&k);
  scanf("%s",s);

  LL ansMin = 0x3f3f3f3f;
  FOR(st,1,(1<<n)) if(ok(st)){
    LL sum = 0;
    FOR(i,0,n) if(st&(1<<i)) sum += i+1;
    ansMin = min(ansMin,sum);
  }
  printf("%lld\n",ansMin);

  return 0;
}
