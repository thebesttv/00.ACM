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

const int MAX = 2e5 + 20;
int n; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s+1);
    n = strlen(s+1) + 2;
    s[0] = 'R';
    s[n-1] = 'R';
    int tMax = 0,i=0,j=0;
    while(i<n){
      j = i+1;
      while(j<n && s[j]!='R') ++j;
      tMax = max(tMax,j-i);
      i = j;
    }
    printf("%d\n",tMax);
  }

  return 0;
}
