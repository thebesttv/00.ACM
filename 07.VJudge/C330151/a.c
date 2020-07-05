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

const int MAX=1020;
int n,m;
struct Ind{
  int j,f; double r;
  Ind(int j, int f, double r): j(j), f(f), r(r) { }
  bool operator < (const Ind &b) const {
    return r > b.r;
  }
};
VR<Ind> v;

int main(void){
  while(scanf("%d%d",&m,&n)==2 && n!=-1){
    v.clear();
    FOR(i,0,n){
      int j,f; scanf("%d%d",&j,&f);
      v.push_back(Ind(j,f,1.0*j/f));
    }
    sort(v.begin(),v.end());
    double ans=0;
    for(Ind t : v){
      if(m>=t.f){
        ans+=t.j; m-=t.f;
        if(m==0) break;
      }else{
        ans+=t.r*m; break;
      }
    }
    printf("%.3lf\n",ans);
  }


  return 0;
}
