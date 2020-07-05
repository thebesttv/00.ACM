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

char s[200];

bool match(char c1, char c2){
  if(c1=='(') return c2==')';
  if(c1=='[') return c2==']';
  return 0;
}
int main(void){
  int T; scanf("%d",&T); getchar();
  while(T--){
    FGETS(s); int len=strlen(s); s[--len]=0;
    stack<char> st;
    bool ok=1;
    FOR(i,0,len){
      if(s[i]=='(' || s[i]=='[')
        st.push(s[i]);
      else{
        while(!st.empty() && !match(st.top(),s[i]))
          st.pop();
        if(st.empty()){
          ok=0; break;
        }else{
          st.pop();
        }
      }
    }
    if(!st.empty()) ok=0;
    printf("%s\n", ok ? "Yes" : "No" );
  }

  return 0;
}
