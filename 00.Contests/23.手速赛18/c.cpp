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
int n,pos[128]; char s[MAX];
stack<char> st;

int main(void){
  scanf("%s",s); n = strlen(s);
  MST(pos,-1);
  FOR(i,0,n) pos[s[i]]=i;

  int i = 0;
  FORR(ch,'a','z'){
    while(!st.empty() && st.top()<=ch)
      putchar(st.top()), st.pop();

    while(i<n && i<=pos[ch]){
      if(s[i]<=ch) putchar(ch);
      else st.push(s[i]);
      ++i;
    }

    while(!st.empty() && st.top()<=ch)
      putchar(st.top()), st.pop();
  }
  while(!st.empty())
    putchar(st.top()), st.pop();
  putchar('\n');

  return 0;
}
