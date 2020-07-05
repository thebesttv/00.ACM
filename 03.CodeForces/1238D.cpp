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

const int MAX = 3e5 + 20;
int n; char s[MAX];
bool ok[MAX];
LL ans = 0;

struct ST{
  int v[MAX];
  int sum(int x){
    int s = 0;
    while(x>0){
      s += v[x]; x -= x&-x;
    }
    return s;
  }
  void add(int x){
    while(x<=n){
      ++v[x]; x += x&-x;
    }
  }
}sg;

void add(int i){
  if(!ok[i]){
    ok[i] = 1;
    sg.add(i);
  }
}

int main(void){
  scanf("%d%s",&n,s+1);
  FORR(i,2,n){
    int j = i-1;
    while(j>=1 && s[j]!=s[i]) --j;
    if(j>=1 && s[j] == s[i]){
      add(j);
      ans += sg.sum(j);
    }
  }
  printf("%lld\n",ans);

  return 0;
}
