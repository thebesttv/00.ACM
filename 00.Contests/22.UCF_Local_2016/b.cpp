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

int p,q;
char s[120],s2[120];
bool same[128][128];

bool ok(){
  int n = strlen(s);
  FOR(i,0,n) s2[n-1-i]=s[i];
  FOR(i,0,n) if(!same[s[i]][s2[i]])
    return 0;
  return 1;
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    MST(same,0);
    scanf("%d",&p);
    char ch1, ch2;
    FORR(i,'a','z') same[i][i]=1;
    FOR(i,0,p){
      cin >> ch1 >> ch2;
      same[ch1][ch2] = same[ch2][ch1] = 1;
    }

    scanf("%d",&q);
    printf("Test case #%d:\n",kase);
    while(q--){
      scanf("%s",s);
      printf("%s %s\n",s, ok() ? "YES" : "NO");
    }
    putchar('\n');
  }

  return 0;
}
