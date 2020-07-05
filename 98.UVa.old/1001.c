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

const int MAX=120;
int n; double G[MAX][MAX];

struct Node{
  int x,y,z,r;
}node[MAX];

double dis(int i, int j){
  int dx = node[i].x - node[j].x;
  int dy = node[i].y - node[j].y;
  int dz = node[i].z - node[j].z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n!=-1){
    FORR(i,1,n){
      scanf("%d%d%d%d",&node[i].x,&node[i].y,&node[i].z,&node[i].r);
    }
    scanf("%d%d%d",&node[0].x,&node[0].y,&node[0].z); node[0].r=0;
    scanf("%d%d%d",&node[n+1].x,&node[n+1].y,&node[n+1].z); node[n+1].r=0;

    n++;
    FORR(i,0,n){
      G[i][i]=0;
      FORR(j,i+1,n){
        double d = dis(i,j) - node[i].r - node[j].r;
        G[i][j] = G[j][i] = max(d,0.0);
      }
    }
    FORR(k,0,n) FORR(i,0,n) FORR(j,0,n)
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    printf("Cheese %d: Travel time = %.0lf sec\n",++kase,G[0][n]*10);
  }

  return 0;
}
