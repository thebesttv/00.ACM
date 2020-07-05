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
int n,w[MAX],h[MAX];
bool G[MAX][MAX];
int f[MAX],r[MAX];
// f[i]: starting from i, the maxium number of nodes (including i)
//   f[u] = max{ f[v] } + 1
// r[i]: record the v that maximises f[u]

void calG(){
  FORR(i,0,n) FORR(j,0,n)
    if(w[i]<w[j] && h[i]<h[j])
      G[i][j]=1;
}

int dp(int u){
  int &a=f[u];
  if(a) return a;
  a=1;
  FORR(v,1,n) if(G[u][v])
    if(a < dp(v)+1){
      a = dp(v)+1; r[u]=v;
    }
  return a;
}

int main(void){
  scanf("%d",&n);
  scanf("%d%d",&w[0],&h[0]);
  FORR(i,1,n) scanf("%d%d",&w[i],&h[i]);

  calG();

  printf("%d\n",dp(0)-1);
  int p=r[0]; bool first=1;
  while(p){
    if(first) first=0;
    else putchar(' ');
    printf("%d",p);
    p = r[p];
  }
  putchar('\n');

  return 0;
}

/*
const int MAX=5020;
int n,w[MAX],h[MAX];
bool G[MAX][MAX];
int f[MAX];
// f[i]: starting from i, the maxium number of nodes (including i)
//   f[u] = max{ f[v] } + 1

void calG(){
  FORR(i,0,n) FORR(j,0,n)
    if(w[i]<w[j] && h[i]<h[j])
      G[i][j]=1;
}

int dp(int u){
  int &a=f[u];
  if(a) return a;
  a=1;
  FORR(v,1,n) if(G[u][v])
    a = max(a, dp(v)+1 );
  return a;
}

bool first=1;
void printAns(int u){ // print out path recursively
  if(u){  // skip node 0
    if(first) first=0;  // prune output
    else putchar(' ');
    printf("%d",u);
  }

  FORR(v,1,n) if(G[u][v] && f[u]==f[v]+1){
    printAns(v); break;
  }
}

int main(void){
  scanf("%d",&n);
  scanf("%d%d",&w[0],&h[0]);
  FORR(i,1,n) scanf("%d%d",&w[i],&h[i]);

  calG();

  printf("%d\n",dp(0)-1);
  printAns(0);
  putchar('\n');

  return 0;
}
*/
