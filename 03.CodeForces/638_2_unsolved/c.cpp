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

const int MAX = 1e5 + 20;
int n,k,v[MAX]; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&k);
    scanf("%s",s); sort(s,s+n);
    if(s[0] != s[k-1]){
      printf("%c\n",s[k-1]); continue;
    }

    if(s[k] == s[n-1]){
      int len = n - k;
      printf("%c",s[0]);
      if(len % k == 0)
        RORR(i,len/k,0) putchar(s[k]);
      else
        RORR(i,len/k+1,0) putchar(s[k]);
      putchar('\n');
    }else{
      printf("%c%s\n",s[0],s+k);
    }
  }

  return 0;
}
