/*
  解题报告：
    可以看出，对每个垃圾，有吃掉或堆放两种决策，且对第i个垃圾的决策不影响之前的决策，因此可以DP。
    令f[i][j]表示考虑前i个垃圾，堆放高度为j时的最大生命值，则：
      f[i][j] = max{ f[i-1][j] + obj[i].f - (obj[i].t-obj[i-1].t), f[i-1][j-obj[i].h] - (obj[i].t-obj[i-1].t) }
      初始化时都为-1（生命值为0也算作存活），f[1][0]=10+obj[1].f-obj[1].t, f[1][obj[1].h]=10-obj[1].t。
      要注意每次更新时判断 在之前状态下 和 进入当前状态且还没有吃掉 时的奶牛是否都存活。
      然后即可求解。
    ps: 可滚动数组优化，不过好像没什么必要。
*/

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
#define RE register

const int MAX=120;
int D,G;
struct Obj{
  int t,f,h;
  bool operator < (const Obj & b) const {return t<b.t;}
}obj[MAX];
int f[MAX][MAX];

int main(void){
  scanf("%d%d",&D,&G);
  FORR(i,1,G) scanf("%d%d%d",&obj[i].t,&obj[i].f,&obj[i].h);
  sort(obj+1,obj+1+G);

  MST(f,-1);
  f[1][0]=10+obj[1].f-obj[1].t;  //吃掉
  f[1][obj[1].h]=10-obj[1].t; //堆放
  FORR(i,2,G) FORR(j,0,D){
    Obj & o=obj[i];
    int cost=o.t-obj[i-1].t;
    if(f[i-1][j]>=0 && f[i-1][j]-(o.t-obj[i-1].t)>=0){  //<b></b>
      f[i][j]=max(f[i][j],f[i-1][j]+o.f-cost);
    }
    if(j-o.h>=0 && f[i-1][j-o.h]>=0){
      f[i][j]=max(f[i][j],f[i-1][j-o.h]-cost);
    }
  }
  int ans=-1;
  FORR(i,1,G) if(f[i][D]>=0) {ans=obj[i].t; break;} //判断能否出去
  if(ans==-1) ROR(i,G,1) FORR(j,0,D) if(f[i][j]>=0){  //若不能出去，求最大存活时间
    ans=max(ans,obj[i].t+f[i][j]);  //<b> 存活时间为obj[i].t+f[i][j]，而非单单obj[i].t </b>
  }
  printf("%d\n",ans);

  return 0;
}
