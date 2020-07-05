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

const int MAX=1000020;
int n,a[MAX],s[MAX],top;

int main(void){
  while(scanf("%d",&n)==1 && n){
    top=0;
    FOR(i,0,n) scanf("%d",&a[i]);
    sort(a,a+n);
    int cnt=0;
    FOR(i,0,n){
      s[top++]=a[i];
      if(top>=2 && s[top-1]==s[top-2]){
        cnt++; top-=2;
      }
      if(top>=3 && s[top-3]+2==s[top-1] && s[top-2]+1==s[top-1]){
        cnt++; top-=3;
      }
    }
    printf("%d\n",cnt);
  }

  return 0;
}

/*
const int MAX=1000020;
int n,cnt[MAX];

int main(void){
  while(scanf("%d",&n)==1 && n){
    MST(cnt,0); int a;
    FOR(i,0,n){
      scanf("%d",&a); cnt[a]++;
    }
    int ans=0;
    FORR(i,1,n) if(cnt[i]){
      ans+=cnt[i]/2; cnt[i]&=1;
    }
    FORR(i,3,n) if(cnt[i-2] && cnt[i-1] && cnt[i]){
      ans++; cnt[i-2]=cnt[i-1]=cnt[i]=0;
    }
    printf("%d\n",ans);
  }

  return 0;
}
*/
