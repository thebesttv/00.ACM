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

const int MAX=128;
int l1,l2,f[MAX][MAX];
char to[MAX],s1[MAX],s2[MAX];
int G[5][5] = {{ 5,-1,-2,-1,-3},
               {-1, 5,-3,-2,-4},
               {-2,-3, 5,-2,-2},
               {-1,-2,-2, 5,-1},
               {-3,-4,-2,-1, 0}};

inline int g(char c1, char c2){
  return G[to[c1]][to[c2]];
}

int main(void){
  to['A']=0, to['C']=1, to['G']=2, to['T']=3, to['-']=4;
  scanf("%d%s",&l1,s1+1);
  scanf("%d%s",&l2,s2+1);

  MST(f,-0x3f); f[0][0]=0;
  FORR(j,1,l2) f[0][j] = f[0][j-1] + g('-',s2[j]);
  FORR(i,1,l1){
    f[i][0] = f[i-1][0] + g('-',s1[i]);
    FORR(j,1,l2){
      f[i][j] = f[i-1][j-1] + g(s1[i],s2[j]);
      f[i][j] = max( f[i][j], f[i][j-1] + g('-',s2[j]) );
      f[i][j] = max( f[i][j], f[i-1][j] + g('-',s1[i]) );
    }
  }
  printf("%d\n",f[l1][l2]);

  return 0;
}
