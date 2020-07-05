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

const int MAX=120;
struct Point{
  int x,y;
}point[MAX];
int n;
int vx[MAX],vy[MAX];
int xMax,yMax;
bool a[MAX][MAX];
int sL[MAX][MAX]; // sL[i][j] = a[i][1:j]
int sU[MAX][MAX]; // sU[i][j] = a[1:i][j]

int get(int x, int *v){
  for(int i=0;;i++)
    if(v[i]==x) return i+1;
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    MST(a,0);

    FOR(i,0,n){
      scanf("%d%d",&point[i].x,&point[i].y);
      vx[i]=point[i].x, vy[i]=point[i].y;
    }
    sort(vx,vx+n); xMax=unique(vx,vx+n)-vx;
    sort(vy,vy+n); yMax=unique(vy,vy+n)-vy;

    FOR(i,0,n){
      point[i].x=get(point[i].x,vx);
      point[i].y=get(point[i].y,vy);
      a[point[i].x][point[i].y]=1;
    }

    FORR(i,1,xMax) FORR(j,1,yMax){
      sL[i][j] = sL[i][j-1]+a[i][j];
      sU[i][j] = sU[i-1][j]+a[i][j];
    }

    int ansMax=0;
    //排除特殊情况（一直线）
    FORR(i,1,xMax) ansMax=max(ansMax,sL[i][yMax]);
    FORR(i,1,yMax) ansMax=max(ansMax,sU[xMax][i]);

    FORR(i,1,xMax) if(sL[i][yMax])
      FORR(j,i+1,xMax) if(sL[j][yMax]){
        int le[MAX]={0}, on1[MAX]={0}, on2[MAX]={0};
        FORR(k,1,yMax){
          le[k] = sL[i][k-1] + sL[j][k-1];
          on1[k] = sU[j-1][k] - sU[i][k];
          on2[k] = sU[j][k] - sU[i-1][k];
        }

        int tMax=on1[1]-le[1];
        FORR(r,2,yMax){ // r从2开始，l从1开始，防止 l==r
          ansMax=max(ansMax,le[r]+on2[r]+tMax);
          tMax=max(tMax,on1[r]-le[r]);  // tMax 在r计算之后再更新
        }
      }
    printf("Case %d: %d\n",++kase,ansMax);
  }

  return 0;
}

/*
const int MAX=120;
struct Point{
  int x,y;
}point[MAX];
int n;
VR<int> vx,vy;
set<int> sx,sy;
bool a[MAX][MAX];
int xMax,yMax;
int sL[MAX][MAX]; // sL[i][j] = a[i][1:j]
int sU[MAX][MAX]; // sU[i][j] = a[1:i][j]

int get(int x, VR<int> &v){
  for(int i=0;;i++)
    if(v[i]==x) return i+1;
}

int main(void){
  int kase=0;
  while(scanf("%d",&n)==1 && n){
    sx.clear(), sy.clear();
    vx.clear(), vy.clear();
    MST(a,0);

    FORR(i,1,n){
      scanf("%d%d",&point[i].x,&point[i].y);
      sx.insert(point[i].x), sy.insert(point[i].y);
    }
    for(int i : sx) vx.push_back(i);
    for(int i : sy) vy.push_back(i);
    xMax=vx.size(); yMax=vy.size();

    FORR(i,1,n){
      point[i].x=get(point[i].x,vx);
      point[i].y=get(point[i].y,vy);
      a[point[i].x][point[i].y]=1;
    }

    FORR(i,1,xMax) FORR(j,1,yMax){
      sL[i][j] = sL[i][j-1]+a[i][j];
      sU[i][j] = sU[i-1][j]+a[i][j];
    }

    int ansMax=0;
    //排除特殊情况（一直线）
    FORR(i,1,xMax) ansMax=max(ansMax,sL[i][yMax]);
    FORR(i,1,yMax) ansMax=max(ansMax,sU[xMax][i]);

    FORR(i,1,xMax) if(sL[i][yMax])
      FORR(j,i+1,xMax) if(sL[j][yMax]){
        int le[MAX]={0}, on1[MAX]={0}, on2[MAX]={0};
        FORR(k,1,yMax){
          le[k] = sL[i][k-1] + sL[j][k-1];
          on1[k] = sU[j-1][k] - sU[i][k];
          on2[k] = sU[j][k] - sU[i-1][k];
#ifdef DEBUG
        printf("  line %d-%d, %d: %d, %d, %d\n",\
            i,j,k,le[k],on1[k],on2[k]);
#endif
        }

        int tMax=on1[1]-le[1];
        FORR(r,2,yMax){ // r从2开始，l从1开始，防止 l==r
          ansMax=max(ansMax,le[r]+on2[r]+tMax);
          tMax=max(tMax,on1[r]-le[r]);  // tMax 在r计算之后再更新
        }
      }
    printf("Case %d: %d\n",++kase,ansMax);
  }

  return 0;
}
*/
