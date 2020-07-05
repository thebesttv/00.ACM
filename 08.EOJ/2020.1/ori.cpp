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

int cnt[1000];
VR<int> v[1000];
struct Node{
};

int main(void){
  int n; scanf("%d",&n);
  v[1].push_back(1);
  ++cnt[1];

  FORR(i,2,n){
    int t = i;
    do{
      v[i].push_back(t);
      ++cnt[t];
      if(t&1) --t;
      else t /= 2;
    }while(t != 1);
    v[i].push_back(1);
    ++cnt[1];
    reverse(ALL(v[i]));
  }
  FORR(i,1,n){
    printf("cnt[%d]: %d\n",i,cnt[i]);
  }
  return 0;
}
