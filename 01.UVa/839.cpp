// Tag: 树 边读入边计算
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
#include<utility>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define FORR(i,a,b) for(register int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(register int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(register int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define FGETS(s) fgets(s,sizeof(s),stdin)
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())
#define FI first
#define SE second
typedef long long LL;
typedef long long unsigned LLU;
typedef pair<int,int> pii;

bool ok;
int read(){
  int wl,dl,wr,dr;
  scanf("%d%d%d%d",&wl,&dl,&wr,&dr);
  if(!wl) wl = read();
  if(!wr) wr = read();
  if(1ll * wl * dl != 1ll * wr * dr)
    ok = 0;
  return wl + wr;
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    ok = 1; read();
    printf("%s\n", ok ? "YES" : "NO");
    if(T) putchar('\n');
  }

  return 0;
}
