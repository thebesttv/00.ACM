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

const int MAX=1020;
int n,m,a[MAX][MAX];
int up[MAX][MAX], le[MAX][MAX], ri[MAX][MAX];
// up[i][j]: block 上部共有几个空格(包括自己), left, right 亦然

int main(void){
  FOR(i,0,MAX) le[0][i]=ri[0][i]=0x3f3f3f3f;

  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    char ch;
    FORR(i,1,n){
      int cnt=0;  // 当前方块左边空出的大小
      FORR(j,1,m){
        do ch=getchar(); while(ch!='F' && ch!='R');
        a[i][j] = ch=='F';

        if(a[i][j]){
          up[i][j]=up[i-1][j]+1;
          if(le[i-1][j])
            le[i][j] = min(le[i-1][j], ++cnt);
          else
            le[i][j] = ++cnt;
        }else{
          up[i][j]=0;
          le[i][j]=cnt=0;
        }
      }
    }
    FORR(i,1,n){
      int cnt=0;
      ROR(j,m,1)
        if(a[i][j]){
          if(ri[i-1][j])
            ri[i][j] = min(ri[i-1][j], ++cnt);
          else
            ri[i][j] = ++cnt;
        }else{
          ri[i][j] = cnt = 0;
        }
    }

    int ansMax=0;
    FORR(i,1,n) FORR(j,1,m) if(a[i][j]){
      int s = up[i][j] * (le[i][j]+ri[i][j]-1);
      ansMax = max(ansMax, s);
    }
    printf("%d\n",ansMax*3);
  }
  return 0;
}

/*
const int MAX=1020;
int n,m,a[MAX][MAX];
int up[MAX][MAX];

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    scanf("%d%d",&n,&m);
    char ch;
    FORR(i,1,n) FORR(j,1,m){
      do ch=getchar(); while(ch!='F' && ch!='R');
      a[i][j]= ch=='F';
      if(a[i][j]) up[i][j]=up[i-1][j]+1;
      else up[i][j]=0;
    }

    int ansMax=0;
    FORR(i,1,n) FORR(j,1,m) if(a[i][j]){
      //错误，不能只向右扩展，必须要尝试向左扩展
      //int k=j;
      //while(k+1<=m && up[i][k+1]>=up[i][j]) k++;
      //ansMax=max(ansMax,up[i][j] * (k-j+1));

      //向左右扩展
      int l=j,r=j;
      while(l-1>=1 && up[i][l-1]>=up[i][j]) l--;
      while(r+1<=m && up[i][r+1]>=up[i][j]) r++;
      ansMax=max(ansMax,up[i][j]*(r-l+1));
    }
    printf("%d\n",ansMax*3);
  }
  return 0;
}
*/
