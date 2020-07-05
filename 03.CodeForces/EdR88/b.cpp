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

const int MAX = 1020;
int n,m,x,y; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&m,&x,&y);
    int ans = 0;
    FOR(k,0,n){
      scanf("%s",s);
      VR<int> v; int i=0,j;
      while(i<m){
        while(i<m && s[i]!='.') ++i;
        if(i>=m) break;
        j = i+1;
        while(j<m && s[j]=='.') ++j;
        v.push_back(j-i);
        i = j;
      }
#ifdef DEBUG
      putchar('*');
      for(int i : v) printf(" %d",i); putchar('\n');
#endif
      for(int i : v)
        if(2*x <= y){
          ans += i * x;
        }else{
          ans += (i/2)*y + ( (i&1) ? x : 0 );
        }
    }
    printf("%d\n",ans);
  }

  return 0;
}
