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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=120;
int n,a,b,c;
char s[MAX],ans[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d%d",&n,&a,&b,&c);
    scanf("%s",s);
    int a2=0,b2=0,c2=0;
    FOR(i,0,n)
      if(s[i]=='R') a2++;
      else if(s[i]=='P') b2++;
      else c2++;

    int sum = min(a,c2) + min(b,a2) + min(c,b2);
    if(sum>=(n+1)/2){
      printf("YES\n");
      FOR(i,0,n){
        if(s[i]=='R' && b){
          ans[i]='P'; --b;
        }else if(s[i]=='P' && c){
          ans[i]='S'; --c;
        }else if(s[i]=='S' && a){
          ans[i]='R'; --a;
        }else ans[i]='*';
      }
      FOR(i,0,n) if(ans[i]=='*'){
        if(a){
          ans[i]='R', --a;
        }else if(b){
          ans[i]='P', --b;
        }else{
          ans[i]='S', --c;
        }
      }
      ans[n]=0;
      printf("%s\n",ans);
      /*
      FOR(i,0,n){
        if(s[i]=='R'){
          if(b){
            putchar('P'); b--;
          }else if(a){
            putchar('R'); a--;
          }else{
            putchar('S'); c--;
          }
        }else if(s[i]=='P'){
          if(c){
            putchar('S'); c--;
          }else if(b){
            putchar('P'); b--;
          }else{
            putchar('R'); a--;
          }
        }else{
          if(a){
            putchar('R'); a--;
          }else if(c){
            putchar('S'); c--;
          }else{
            putchar('P'); b--;
          }
        }
      }
      putchar('\n');
      */
    }else printf("NO\n");
  }

  return 0;
}
