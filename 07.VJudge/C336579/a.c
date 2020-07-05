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

const int MAX=1000020;
int n,a[MAX];
int occ[MAX],cnt;

map<int,int> mp;
int tail=0;
int ID(int n){
  if(mp.count(n)) return mp[n];
  return mp[n]=++tail;
}

int main(void){
  scanf("%d",&n);
  int x; FOR(i,0,n){
    scanf("%d",&x); a[i]=ID(x);
  }

  int ansMin=n,l=0,r=0;
  while(l<n){
    while(cnt<tail && r<n){
      if(occ[a[r]]++==0) ++cnt;
      ++r;
    }
    //printf("  %d, %d\n",l,r);
    //FORR(i,1,tail) printf("  cnt[%d]: %d\n",i,occ[i]);
    if(cnt==tail)
      ansMin=min(ansMin,r-l);
    else break;
    if((--occ[a[l]])==0) --cnt;
    ++l;
  }
  printf("%d\n",ansMin);

  return 0;
}
