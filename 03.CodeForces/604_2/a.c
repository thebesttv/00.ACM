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

const int MAX = 1e5+20;
int n; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s); n = strlen(s);

    if(s[0]=='?'){
      if(s[1]=='a') s[0]='b';
      else s[0]='a';
    }

    FOR(i,1,n) if(s[i]=='?'){
      if(s[i-1]=='a'){
        if(s[i+1]=='b') s[i]='c';
        else s[i]='b';
      }else if(s[i-1]=='b'){
        if(s[i+1]=='a') s[i]='c';
        else s[i]='a';
      }else{  // c
        if(s[i+1]=='a') s[i]='b';
        else s[i]='a';
      }
    }

    bool ok = 1;
    FOR(i,1,n) if(s[i]==s[i-1]){
      ok = 0; break;
    }
    if(!ok) printf("-1\n");
    else printf("%s\n",s);
  }

  return 0;
}
