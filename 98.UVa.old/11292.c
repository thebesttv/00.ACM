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

const int MAX = 20000 + 10;
int n, m;
int r[MAX], h[MAX];

int main(void){
  //while(scanf("%d%d",&n,&m)!=EOF){
  //  if(!n && !m) break;
  while(scanf("%d%d",&n,&m) && n && m){
    FOR(i,0,n) scanf("%d",&r[i]); sort(r,r+n);
    FOR(i,0,m) scanf("%d",&h[i]); sort(h,h+m);
    if(n>m){
      printf("Loowater is doomed!\n"); break;
    }

    int i=0, j=0; LL ans=0;
    while(i<n && j<m){
      if(r[i] <= h[j]){ // able to cut off head
        ans+=h[j]; i++,j++;
      }else{  // unable
        j++;
      }
    }
    if(i>=n) printf("%lld\n",ans);
    else printf("Loowater is doomed!\n");
  }

  return 0;
}
