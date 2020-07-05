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

const int MAX=200020;
int n,m,x[MAX];

int pos(int i, int v){
  if(i==v) return 1;
  if(v<i) return v+1;
  return v;
}

int f(int i){
  int ans=0;
  FOR(j,1,m){
    ans += abs(pos(i,x[j]) - pos(i,x[j+1]));
  }
  return ans;
}

int main(void){
  scanf("%d%d",&n,&m);
  FORR(i,1,m) scanf("%d",&x[i]);

  FORR(i,1,n) printf("%d ",f(i));
  putchar('\n');

  return 0;
}
