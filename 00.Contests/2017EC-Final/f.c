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

bool ok(int n){
  char s[100]; sprintf(s,"%d",n);
  int len = strlen(s);
  FOR(j,1,len){
    string ts;
    FOR(k,j,len) ts.push_back(s[k]);
    FOR(k,0,j) ts.push_back(s[k]);
    int tn = 0;
    for(char c : ts)
      tn = tn * 10 + c-'0';
    if(n<tn) return 0;
  }
  return 1;
}

int main(void){
  FORR(i,1,100000) if(ok(i)){
    printf("%d\n",i);
  }

  return 0;
}
