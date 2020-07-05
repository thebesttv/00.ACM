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
int n,tail; char s[MAX],t[MAX],v[MAX];

bool bad(){
  int c0 = 0, c1 = 0;
  FOR(i,0,n){
    if(s[i]=='0') ++c0;
    if(t[i]=='0') ++c1;
  }
  return c0 != c1;
}

int main(void){
  scanf("%d%s%s",&n,s,t);
  if(bad()){
    printf("-1\n"); return 0;
  }

  FOR(i,0,n) if(s[i]!=t[i]){
    v[tail++] = s[i];
  }

  int c0 = 0, c1 = 0;
  FOR(i,0,tail)
    if(v[i]=='0'){
      if(c1) --c1, ++c0;
      else ++c0;
    }else{
      if(c0) --c0, ++c1;
      else ++c1;
    }
  printf("%d\n",c0+c1);

  return 0;
}
