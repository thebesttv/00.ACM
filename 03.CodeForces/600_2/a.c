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

const int MAX=1e5+20;
int n,a[MAX],b[MAX];

bool ok(){
  int i=0;
  while(i<n && a[i]==b[i]) i++;
  if(i>=n) return true;

  int d = a[i] - b[i];
  if(d>0) return false;
  int j = i+1;
  while(j<n && d == a[j] - b[j]) j++;
  if(j>=n) return true;

  if(a[j]-b[j] != 0) return false;
  while(j<n){
    if(a[j]!=b[j]) return false;
    j++;
  }
  return true;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d",&n);
    FOR(i,0,n) scanf("%d",&a[i]);
    FOR(i,0,n) scanf("%d",&b[i]);
    printf("%s\n",ok() ? "YES" : "NO");
  }
  return 0;
}
