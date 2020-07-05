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

int n,m; char str[100];

string fromK(LL k){
  string s;
  while(k){
    s += (k&1) + '0';
    k>>=1;
  }
  s.resize(m, '0');
  reverse(ALL(s));
  return s;
}

void advance(string &s){
  ROR(i,m-1,0)
    if(s[i]=='1') s[i]='0';
    else{
      s[i] = '1'; break;
    }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    set<string> st;
    FOR(i,0,n) scanf("%s",str), st.insert(str);
    LL k = (1ll<<m) - n;
    k = (k-1)/2;
    string ans(fromK(k));
#ifdef DEBUG
    printf("  initial: %s, k: %lld\n",ans.c_str(),k);
#endif
    int cnt = 0;
    for(auto s : st)
      if(s <= ans) ++cnt;
#ifdef DEBUG
    printf("  cnt: %d\n",cnt);
#endif

    while(cnt){
      advance(ans);
#ifdef DEBUG
      printf("  advance to %s\n",ans.c_str());
#endif
      if(!st.count(ans))
        --cnt;
    }
    printf("%s\n",ans.c_str());
  }

  return 0;
}
