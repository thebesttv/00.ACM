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

const int MAX=5020;
int n,m,k;
int fa[MAX],rk[MAX];

int p(int n){
  return fa[n]==-1 ? n : fa[n] = p(fa[n]);
}
void merge(int x, int y){
  int f1=p(x), f2=p(y);
  if(f1==f2) return;
  if(rk[f1]<rk[f2]){
    fa[f2]=f1; rk[f1]+=rk[f2];
  }else{
    fa[f1]=f2; rk[f2]+=rk[f1];
  }
}

int main(void){
  MST(fa,-1), MST(rk,-1);
  scanf("%d%d%d",&n,&m,&k);
  int x,y;
  while(m--){
    scanf("%d%d",&x,&y);
    merge(x,y);
  }
  while(k--){
    scanf("%d%d",&x,&y);
    printf("%s\n",p(x)==p(y) ? "Yes" : "No" );
  }

  return 0;
}
