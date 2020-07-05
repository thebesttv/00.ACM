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

int get(int len, int st){
  int s = 0;
  FORR(i,1,len)
    if(st&(1<<(i-1)))
      s += i;
    else s -= i;
  return s;
}

int main(void){
  map<int,int> mp; 
  mp[0] = 0;
  FORR(i,1,22){
    FOR(st,0,1<<i){
      int s = get(i,st);
      if(!mp.count(s))
        mp[s] = i;
    }
  }
  for(auto p : mp) if(p.FI>=0 && p.FI<=200)
    printf("f[%d]: %d\n",p.FI,p.SE);

  return 0;
}
