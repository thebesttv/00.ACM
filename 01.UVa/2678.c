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

const int MAX=100020;
int n,s,a[MAX];

int main(void){
  while(scanf("%d%d",&n,&s)==2){
    FORR(i,1,n) scanf("%d",&a[i]);
    int i=1,j=1,tsum=a[1],ansMin=n+1;  // tsum = a[i:j]
    while(i<=n && j<=n){
      while(j<n && tsum<s) tsum+=a[++j];
      if(tsum<s) break;
      ansMin=min(ansMin,j-i+1);
      tsum-=a[i++];
    }
    printf("%d\n", ansMin==n+1 ? 0 : ansMin);
  }

  return 0;
}

/*
const int MAX=100020;
int n,s,a[MAX];

int main(void){
  while(scanf("%d%d",&n,&s)==2){
    int tsum=0,ansMin=n+1;
    for(int j=1,i=1;j<=n;j++){
      scanf("%d",&a[j]); tsum+=a[j];
      while(i<j && tsum-a[i]>=s) tsum-=a[i++];
      if(tsum>=s) ansMin=min(ansMin,j-i+1);
    }

    printf("%d\n", ansMin==n+1 ? 0 : ansMin);
  }

  return 0;
}
*/

/*
const int MAX=100020;
int n,s,a[MAX],b[MAX];

inline int sum(int l, int r){
  return b[r]-b[l-1];
}

int main(void){
  while(scanf("%d%d",&n,&s)==2){
    a[0]=b[0]=0;
    FORR(i,1,n){
      scanf("%d",&a[i]);
      b[i]=b[i-1]+a[i];
    }
    int ansMin=n+1;
    FORR(i,1,n){
      int l=i, r=n;
      while(l<r){
        int m=(l+r)/2;
        if(sum(i,m)>=s) r=m;
        else l=m+1;
      }
      if(sum(i,l)<s) break;
      else ansMin=min(ansMin,l-i+1);
    }
    printf("%d\n", ansMin==n+1 ? 0 : ansMin);
  }

  return 0;
}
*/
