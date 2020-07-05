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
typedef pair<int,char> pii;

const int MAX = 1e6 + 20;
int n; char s[MAX];
int cnt[128];
VR<pii> v;

int main(void){
  scanf("%s",s); n = strlen(s);
  FOR(i,0,n) ++cnt[s[i]];
  FORR(i,'a','z') if(cnt[i])
    v.push_back({cnt[i],char(i)});
  sort(ALL(v)); reverse(ALL(v));

  if(v.size()==1){
    printf("NO\n");
  }else if(v.size()==2){
    if(v[1].FI==1){
      if(v[0].FI > 1) printf("NO\n");
      else{
        printf("YES\n%s\n",s);
      }
    }else if(v[1].FI==2){
      if(v[0].FI==2){
        printf("YES\n%c%c%c%c\n",v[0].SE,v[0].SE,v[1].SE,v[1].SE);
      }else{
        printf("NO\n");
      }
    }else{
      printf("YES\n");
      int d = min(v[0].FI, n/2-1);
      FOR(i,0,d) putchar(v[0].SE);
      putchar(v[1].SE);
      v[0].FI-=d, --v[1].FI;
      while(v[0].FI--) putchar(v[0].SE);
      while(v[1].FI--) putchar(v[1].SE);
      putchar('\n');
    }
  }else{
    int d = min(v[0].FI, n/2-1);
    FOR(i,0,d) putchar(v[0].SE);
    putchar(v[1].SE);
    v[0].FI-=d, --v[1].FI;
    while(v[0].FI--) putchar(v[0].SE);
    FOR(i,1,v.size())
      while(v[i].FI--) putchar(v[i].SE);
    putchar('\n');
  }
}
