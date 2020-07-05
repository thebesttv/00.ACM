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

const int MAX=1020;
int n,m,d,c[MAX];
bool first=1;

void print(int v, int x){
  while(x--){
    if(first) first=0;
    else putchar(' ');
    printf("%d",v);
  }
}

int main(void){
  scanf("%d%d%d",&n,&m,&d);
  int s=0;
  FORR(i,1,m) scanf("%d",&c[i]), s+=c[i];

  if((m+1)*(d-1) + s < n){
    printf("NO\n"); return 0;
  }
  printf("YES\n");
  s = n - s;
  FORR(i,1,m){
    int t = min(d-1, s);
    print(0, t); s-=t;
    print(i,c[i]);
  }
  if(s) print(0,s);
  putchar('\n');

  return 0;
}
