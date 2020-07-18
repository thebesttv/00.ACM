// Tag: ii
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

const int MAX = 1e6 + 20;
int n; char s[MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%s",s); n = strlen(s);
    int ca = 0, cb = 0, dead = 0, sad = 0, last = -1;
    FOR(i,0,n){
      if(s[i] == 'a') ++ca;
      else ++cb, last = i;
      if(cb > ca) { dead = 1; break; }
    }
    ca = 0, cb = 0;
    FOR(i,0,n){
      if(s[i] == 'a') ++ca;
      else ++cb;
      if(i == last){
        if(ca > cb) { sad = 1; }
        break;
      }
    }

    if(dead) printf("Dead Fang\n");
    else if(sad) printf("Sad Fang\n");
    else printf("Happy Fang\n");
  }

  return 0;
}
