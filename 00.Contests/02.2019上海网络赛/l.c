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
typedef long long LL;
typedef long long unsigned LLU;

struct Query{
  int n,num;
  bool operator < (const Query &b) const {
    return n > b.n;
  }
};
VR<Query> v[11];
int sum[1000020];
int ans[1000020];

const int LEN=30;
int len,a[LEN];

void cal(int i, int b){
  len=0;
  while(i){
    a[len++] = i%b;
    i/=b;
  }
}

int main(void){
  int T; scanf("%d",&T);
  int n,b;
  FORR(i,1,T){
    scanf("%d%d",&n,&b);
    v[b].push_back((Query){n,i});
  }
  FORR(base,2,10) if(v[base].size()){
    sum[0]=0;
    sort(v[base].begin(),v[base].end());
    int rMax=v[base][0].n;
    FORR(i,1,rMax){
      cal(i,base);
      sum[i]=0;
      FOR(j,0,len) sum[i]+=a[j];
      sum[i]+=sum[i-1];
    }
    for(Query Q : v[base]){
      ans[Q.num] = sum[Q.n];
    }
  }
  FORR(i,1,T) printf("Case #%d: %d\n",i,ans[i]);

  return 0;
}
