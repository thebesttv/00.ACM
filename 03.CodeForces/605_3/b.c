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

const int MAX = 1e5 + 20;
int n, cnt[26]; char s[MAX];

int main(void){
  int T; scanf("%d",&T); getchar();
  while(T--){
    MST(cnt,0);
    //scanf("%s",s);
    FGETS(s); n = strlen(s);
    s[--n] = 0;
    FOR(i,0,n) ++cnt[s[i]-'A'];
    int l = cnt['L'-'A'],
        r = cnt['R'-'A'],
        u = cnt['U'-'A'],
        d = cnt['D'-'A'];
    int cnt1 = min(l,r), cnt2 = min(u,d);
    if(!cnt1 && !cnt2){
      printf("0\n\n");
    }else if(!cnt1){
      printf("2\nUD\n");
    }else if(!cnt2){
      printf("2\nLR\n");
    }else{
      printf("%d\n",(cnt1+cnt2)*2);
      FOR(i,0,cnt1) putchar('R');
      FOR(i,0,cnt2) putchar('D');
      FOR(i,0,cnt1) putchar('L');
      FOR(i,0,cnt2) putchar('U');
      putchar('\n');
    }
  }

  return 0;
}
