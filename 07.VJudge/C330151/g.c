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

const int MAX=10020;
int n,h[MAX];

int main(void){
  while(scanf("%d",&n)==1 && n>0){
    FORR(i,1,n) scanf("%d",&h[i]);
    int ans=0,cnt=0;
    FORR(i,1,n) if(h[i]){
      int last=h[i]; ans++;
      FORR(j,i,n) if(h[j]){
        if(last>=h[j]){
          last=h[j]; h[j]=0; cnt++;
          if(cnt==n) break;
        }
      }
      if(cnt==n) break;
    }
    printf("%d\n",ans);
  }

  return 0;
}
