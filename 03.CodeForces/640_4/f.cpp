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

int a,b,c;

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a,&b,&c);
    string s;
    if(a && c) --b;

    if(a){
      s += "00"; --a;
      while(a--) s += '0';
    }

    if(c){
      s += "11"; --c;
      while(c--) s += '1';
    }

    if(b){
      if(s.empty()) s += '1';

      if(s.back() == '1')
        FOR(i,0,b) s += '0' + (i&1);
      else
        FOR(i,0,b) s += '0' + ((i&1)==0);
    }

    printf("%s\n",s.c_str());
  }

  return 0;
}
