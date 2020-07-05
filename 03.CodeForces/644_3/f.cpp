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

int n,m; char str[20];
string s[20];

bool ok(const string &str){
  FORR(i,2,n){
    int cnt = 0;
    FOR(j,0,m) if(str[j] != s[i][j])
      ++cnt;
    if(cnt>1) return false;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    FORR(i,1,n){
      scanf("%s",str);
      s[i] = string(str);
    }

    if(n==1){
      printf("%s\n",s[1].c_str());
      continue;
    }

    bool done = 0;
    FOR(i,0,m){
      int ori = s[1][i];
      FORR(ch,'a','z'){
        s[1][i] = ch;
        if(ok(s[1])){
          printf("%s\n",s[1].c_str());
          done = 1; break;
        }
      }
      s[1][i] = ori;
      if(done) break;
    }
    if(!done) printf("-1\n");
  }

  return 0;
}
