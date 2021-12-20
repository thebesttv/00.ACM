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

int main(void){
  bool found=0, negative=0;
  LL s=0; char ch;
  while(cin >> ch){
    if(ch=='#') break;
    if(!found && ch=='-'){
      negative = 1;
    }
    if(isdigit(ch)){
      found=1;
      s = s*16 + ch-'0';
    }else if(isalpha(ch) && tolower(ch)<='f'){
      found=1;
      s = s*16 + (tolower(ch)-'a'+10);
    }
  }
  printf("%lld\n", negative ? -s : s);

  return 0;
}
