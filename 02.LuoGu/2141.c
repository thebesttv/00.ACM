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

const int MAXN = 110;
const int MAX = 10000 + 10;
int n, a[MAXN];
bool flag[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&a[i]);

  FOR(i,0,n) FOR(j,i+1,n){
    int t = a[i]+a[j];
    if(t<MAX) flag[t]=1;
  }
  int cnt=0;
  FOR(i,0,n) if(flag[a[i]])
    cnt++;
  printf("%d\n",cnt);

  return 0;
}
