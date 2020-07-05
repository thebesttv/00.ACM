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

const int MAX=2e5 + 20;
int n,z,a[MAX];

bool ok(int k){
  int s = n-k;
  FOR(i,0,k) if(a[i+s] - a[i] < z)
    return false;
  return true;
}

int main(void){
  scanf("%d%d",&n,&z);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);
  int l = 0, r = n/2;
  while(l<r){
    int m = (l+r+1)/2;
    if(ok(m)){
      l = m;
    }else{
      r = m-1;
    }
  }
  printf("%d\n",l);

  return 0;
}

/*
const int MAX=2e5 + 20;
int n,z,a[MAX];

int main(void){
  scanf("%d%d",&n,&z);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);
  int i=0,ans=0;
  FOR(j,(n+1)/2,n){
    if(a[j]-a[i]>=z){
      ++ans, ++i;
    }
  }
  printf("%d\n",ans);

  return 0;
}
*/

/*
const int MAX=2e5+20;
int n,z,a[MAX];

int main(void){
  scanf("%d%d",&n,&z);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);

  int i=0,j=1,cnt=0;
  while(i<n && j<n){
    while(i<n && !a[i]) i++;
    j=max(j,i);
    while(j<n && a[j]-a[i]<z) j++;
    if(i==n || j==n) break;
    a[i]=a[j]=0; cnt++;
  }
  printf("%d\n",cnt);

  return 0;
}
*/
