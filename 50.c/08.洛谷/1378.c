/*
题目描述
在一个长方形框子里，最多有N（0≤N≤6）个相异的点，在其中任何一个点上放一个很小的油滴，那么这个油滴会一直扩展，直到接触到其他油滴或者框子的边界。必须等一个油滴扩展完毕才能放置下一个油滴。那么应该按照怎样的顺序在这N个点上放置油滴，才能使放置完毕后所有油滴占据的总体积最大呢？（不同的油滴不会相互融合）
注：圆的面积公式V=pi*r*r，其中r为圆的半径。

输入输出格式
输入格式：
第1行一个整数N。
第2行为长方形边框一个顶点及其对角顶点的坐标，x,y,x’,y’。
接下去N行，每行两个整数xi,yi，表示盒子的N个点的坐标。
以上所有的数据都在[-1000，1000]内。

输出格式：
一行，一个整数，长方形盒子剩余的最小空间（结果四舍五入输出）

输入输出样例
输入样例#1：
2
20 0 10 10
13 3
17 7

输出样例#1：
50
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

const int MAX=10;
const double PI=3.1415926535;
const double EPS=1e-7;
struct Cir{
  int x,y;
  double r;
}cir[MAX];
int n,X1,Y1,X2,Y2;
double ansMax=0;
bool vis[MAX];

double squ(){
  double sr=0;
  FOR(i,0,n) if(cir[i].r>EPS) sr+=cir[i].r*cir[i].r;
  return PI*sr;
}
double dis(int X1, int Y1, int X2, int Y2){
  return sqrt((X1-X2)*(X1-X2) + (Y1-Y2)*(Y1-Y2));
}
void dfs(int cur){
  //if(cur==n) {ansMax=max(ansMax,squ()); return;}
  if(cur==n){
    double t=squ();
#ifdef DEBUG
    printf("  get s: %lf\n",t);
#endif
    ansMax=max(ansMax,t);
    return;
  }

  FOR(i,0,n) if(!vis[i]){
    vis[i]=1;
    double & r=cir[i].r;
    r=0; dfs(cur+1);  //不扩展当前
    //扩展当前
    r=1<<30;
    FOR(j,0,n) if(vis[j] && j!=i && cir[j].r>EPS){
      r=min(r,dis(cir[j].x,cir[j].y,cir[i].x,cir[i].y)-cir[j].r);
    }
    r=min(r,(double)min(X2-cir[i].x,cir[i].x-X1));
    r=min(r,(double)min(Y2-cir[i].y,cir[i].y-Y1));
    if(r>EPS){
      dfs(cur+1);
    }
    vis[i]=0;
  }
}

int main(void){
  scanf("%d",&n);
  scanf("%d%d%d%d",&X1,&Y1,&X2,&Y2);
  if(X1>X2) swap(X1,X2),swap(Y1,Y2);
  if(Y1>Y2) swap(Y1,Y2);
#ifdef DEBUG
  printf("  square: (%d,%d) - (%d,%d)\n",X1,Y1,X2,Y2);
#endif
  FOR(i,0,n) scanf("%d%d",&cir[i].x,&cir[i].y);
  dfs(0);
  printf("%d\n",(int)floor((X2-X1)*(Y2-Y1)-ansMax+0.5));

  return 0;
}
