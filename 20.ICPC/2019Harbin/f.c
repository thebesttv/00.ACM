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

const int MAX=2e6+20;
int n,a[6]; bool have[6][6];

int main(void){
  int T; scanf("%d",&T); getchar();
  while(T--){
    int ch; MST(have,0);
    FOR(i,0,6){
      do{
        ch = getchar();
        switch(ch){
          case 'h': have[i][0]=1; break;
          case 'a': have[i][1]=1; break;
          case 'r': have[i][2]=1; break;
          case 'b': have[i][3]=1; break;
          case 'i': have[i][4]=1; break;
          case 'n': have[i][5]=1; break;
        }
      }while(ch!='\n');
    }

    FOR(i,0,6) a[i]=i;
    bool ok=0;
    do{
      bool bad = 0;
      FOR(i,0,6) if(have[i][a[i]]==0){
        bad = 1; break;
      }
      if(!bad){
        ok = 1; break;
      }
    }while(next_permutation(a,a+6));
    printf("%s\n", ok ? "Yes" : "No");
  }

  return 0;
}
