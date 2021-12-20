#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
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

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=220;
int n,m,t,c[120][2];
int f[MAX][MAX];

int main(void){
  scanf("%d%d%d",&n,&m,&t);
  FORR(i,1,n) scanf("%d%d",&c[i][0],&c[i][1]);

  FORR(i,1,n) ROR(j,m,c[i][0]) ROR(k,t,c[i][1])
    f[j][k]=max(f[j][k],f[j-c[i][0]][k-c[i][1]]+1);
  printf("%d\n",f[m][t]);

  return 0;
}
