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

const int MAX=40;
int l1,l2; char s1[MAX],s2[MAX];
int f[MAX][MAX]; LL g[MAX][MAX];

int main(void){
  int T; scanf("%d",&T); getchar();
  FORR(kase,1,T){
    fgets(s1+1,sizeof(s1)-1,stdin);
    fgets(s2+1,sizeof(s2)-1,stdin);
    l1 = strlen(s1+1); s1[l1--]=0;
    l2 = strlen(s2+1); s2[l2--]=0;
#ifdef DEBUG
    printf("%s\n%s\n",s1+1,s2+1);
#endif
    MST(f,0x3f);
    f[0][0]=0, g[0][0]=1;
    FORR(i,1,l1) f[i][0]=i, g[i][0]=1;
    FORR(j,1,l2) f[0][j]=j, g[0][j]=1;

    FORR(i,1,l1) FORR(j,1,l2){
      if(s1[i]==s2[j]){
        f[i][j]=f[i-1][j-1]+1;
        g[i][j]=g[i-1][j-1];
      }else{
        int x1=f[i-1][j], x2=f[i][j-1];
        if(x1==x2){
          f[i][j]=x1+1; g[i][j]=g[i-1][j]+g[i][j-1];
        }else if(x1<x2){
          f[i][j]=x1+1; g[i][j]=g[i-1][j];
        }else{
          f[i][j]=x2+1; g[i][j]=g[i][j-1];
        }
      }
    }
#ifdef DEBUG
    FORR(i,1,l1) FORR(j,1,l2)
      printf("f[%d][%d]: %d\n",i,j,f[i][j]);
#endif
    printf("Case #%d: %d %lld\n",kase,f[l1][l2],g[l1][l2]);
  }

  return 0;
}
