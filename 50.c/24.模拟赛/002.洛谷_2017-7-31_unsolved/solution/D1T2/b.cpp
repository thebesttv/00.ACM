#include"bits/stdc++.h"

#define REP(x,l,u) for(int x = l;x<u;x++)

using namespace std;

const int maxn = 510,mod = 1e9+7;

int n,m;

char st[maxn][maxn];

int f[maxn][maxn],g[maxn][maxn];

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

void Work(){  //滚动数组
  //f(x1,y1,x2,y2)->
  //  f(x1+1,y1,x2-1,y2)
  //  f(x1+1,y1,x2,y2-1)
  //  f(x1,y1+1,x2-1,y2)
  //  f(x1,y1+1,x2,y2-1)
  //省略y2，到达(x1,y1)时，共走了x1-1+y1-1步，可由x2推出y2
  f[1][m]=(st[1][1]==st[n][m]); //在两端，f是0，1取决于两端是否相同
  REP(t,1,(n+m)/2){
    REP(i,1,m+1) REP(j,1,m+1) g[i][j]=f[i][j], f[i][j]=0;
    REP(i,1,m+1) REP(j,1,m+1) if(g[i][j]){
      int x1=t-i+1,y1=i,x2=n-(t-(m-j)-1),y2=j;  //(x1,y1), (x2,y2)
      REP(k1,0,2) REP(k2,2,4){
        int tx1=x1+dx[k1],ty1=y1+dy[k1];
        int tx2=x2+dx[k2],ty2=y2+dy[k2];
        if(tx1>n || ty1>m || tx2<1 || ty2<1 || st[tx1][ty1]!=st[tx2][ty2])continue;
        (f[ty1][ty2]+=g[i][j])%=mod;
      }
    }
  }
  int ans=0;
  if((n+m-1)&1) REP(i,1,m+1) (ans+=f[i][i])%=mod;
  else REP(i,1,m+1) (ans+=f[i][i+1])%=mod, (ans+=f[i][i])%=mod;
  cout << ans << endl;
}

void Init(){
  scanf("%d%d",&n,&m);
  REP(i,1,n+1) scanf("%s",st[i]+1);
}

int main(){
  freopen("b8.in","r",stdin);
  Init();
  Work();
  //printf("%.10lf\n",(double)clock()/CLOCKS_PER_SEC);
  return 0;
}
