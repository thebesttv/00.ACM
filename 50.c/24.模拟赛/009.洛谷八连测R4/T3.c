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

const int MAX=20;
int n,m,ansMin=1<<30;;
int a[MAX][MAX];
int r[MAX],c[MAX],rmax[MAX],cmax[MAX];

inline void dfs(int i, int j, int cnt){  //i: r, j: c 搜索最小的 不稳的数 个数
  if(cnt>ansMin) return;
  if(i==n && j==m) {ansMin=cnt; return;}
  
  if(i<n && j<m){
    FORR(x,0,rmax[i]) FORR(y,0,cmax[j]){
      r[i]=x; c[j]=y;
      register int tcnt=0;
      FORR(ii,0,i){
        register int t=a[ii][j]+r[ii]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      FOR(jj,0,j){
        register int t=a[i][jj]+r[i]+c[jj];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(i+1,j+1,cnt+tcnt);
    }
  }else if(i<n){
    FORR(x,0,rmax[i]){
      r[i]=x;
      register int tcnt=0;
      FOR(jj,0,j){
        register int t=a[i][jj]+r[i]+c[jj];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(i+1,m,cnt+tcnt);
    }
  }else{
    FOR(y,0,cmax[j]){
      c[j]=y;
      register int tcnt=0;
      FORR(ii,0,i){
        register int t=a[ii][j]+r[ii]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) tcnt++;
      }
      dfs(n,j+1,cnt+tcnt);
    }
  }
}

int main(void){
  scanf("%d%d",&n,&m);
  FOR(i,0,n) FOR(j,0,m) scanf("%d",&a[i][j]);
  FOR(i,0,n){
    register int rMin=1<<30;
    FOR(j,0,m) rMin=min(rMin,a[i][j]);
    rmax[i]=12-rMin;
  }
  FOR(j,0,m){
    register int cMin=1<<30;
    FOR(i,0,n) cMin=min(cMin,a[i][j]);
    cmax[j]=12-cMin;
  }

  if(n<=5 && m<=5) dfs(0,0,0);
  else{
    int sum=0;
    FOR(i,0,n) FOR(j,0,m) sum+=a[i][j];
    srand(sum*sum%1000007*sum);
    int T=500000;
    while(T--){
      FOR(i,0,n) r[i]=rand()%5;
      FOR(j,0,m) c[j]=rand()%5;
      int cnt=0;
      FOR(i,0,n) FOR(j,0,m){
        int t=a[i][j]+r[i]+c[j];
        if(t!=3 && t!=6 && t!=9 && t!=12) cnt++;
      }
      ansMin=min(ansMin,cnt);
    }
  }
  printf("%d\n",n*m-ansMin);

  return 0;
}
