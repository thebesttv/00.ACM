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

const int MAX=120;
int n; char s[MAX];

int main(void){
  while(scanf("%s",s)==1){
    n = strlen(s);
    int cnt0 = 0, cnt1 = 0, cnt01 = 0;
    FOR(i,0,n){
      if(s[i]=='0'){
        cnt0++;
        if(s[(i+1)%n]=='1')
          cnt01++;
      }else cnt1++;
    }
    double ps = 1.0 * cnt01 / cnt0;
    double pr = 1.0 * cnt1 / n;
    if(n * cnt01 == cnt0 * cnt1){
      printf("EQUAL\n");
    }else{
      printf("%s\n", ps > pr ? "ROTATE" : "SHOOT");
    }
  }

  return 0;
}
