/*
  解题报告：
    几何概型，但是矩形在直线 y=x+w 和 y=x-w 之间的面积不太容易求得。
    [1]讨论求解
      没什么好说的，分类罢了，不过分类也要分得巧一些。
      可以计算 y=x-w 右边的面积 和 y=x+w 左边的面积 之和，如果>=原面积，就减去一个原面积，即为答案。
      不过还有更好的方法，是我从网上看到的。
      求出矩形分别在直线 y=x-w, y=x+w 右边的面积 S1, S2，有效面积即为S2-S1。
    [2]求出两直线之间的点，再求出形成的凸多边形的面积
      这个是我在考虑优化方法[1]的中途午睡时突然想到的，还特地起来试了一下 XD
      矩形的4个顶点、8个与直线的交点，而这12个点中，在两直线之间的点组成的即为有效多边形，其面积即为有效面积。
      先算出所有的有效点，然后找出最左下角的那个点P。因为是凸多边形，那么其他的点都与P都有所成角且都不同。
      将其他的点按照与P所成角排序，然后计算多边形面积即可。
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
#define FIN(s) freopen(s,"r",stdin)
#define FOUT(s) freopen(s,"w",stdout)
typedef long long LL;
typedef long long unsigned LLU;

int s1,s2,t1,t2,w;

double area(int w){  //矩形在 l: y=x+w 右边的面积（可能为非整数）
  //(s1,t2)   (s2,t2)
  //  A-----------B
  //  |           |
  //  D-----------C
  //(s1,t1)   (s2,t1)
  if(t1>=s2+w) return 0;  //C在l左上方
  if(t2<=s1+w) return (s2-s1)*(t2-t1);  //A在l右下方
  int a=s2-s1,b=t2-t1;
  if(a>=b){
    if(t1<=s1+w){ //A在l左上方
      return a*b - 0.5*(t2-s1-w)*(t2-s1-w);
    }else if(t2<=s2+w){ //D在l左上方
      return 0.5*((s2-t2+w) + (s2-t1+w))*b;
    }else{
      return 0.5*(s2-t1+w)*(s2-t1+w);
    }
  }else{
    if(t2<=s2+w){ //A在l左上方
      return a*b - 0.5*(t2-s1-w)*(t2-s1-w);
    }else if(t1<=s1+w){ //B在l左上方
      return 0.5*((s2-t1+w) + (s1-t1+w))*a;
    }else{
      return 0.5*(s2-t1+w)*(s2-t1+w);
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d%d%d%d",&t1,&t2,&s1,&s2,&w);
    double S1=area(-w),S2=area(w),S=(s2-s1)*(t2-t1);
    printf("Case #%d: %.8lf\n",kase,(S2-S1)/S);
  }

  return 0;
}


/*
int s1,s2,t1,t2,w;
struct Point{ //点，同时也是向量
  int x,y;
  double ang; //与点P所成角

  Point(int x_, int y_): x(x_), y(y_) { };
  bool operator < (const Point & b) const {
    return ang<b.ang;
  }
};
struct Line{  //矩形的四条边所在直线
  int a,b,c;
}line[4];

bool getXY(int & x, int & y, Line & l, int t){
  //计算 y=x+t 与 ax+by=c 的交点(x,y)（整点），并返回它是否在矩形边界
  x = (l.c-l.b*t)/(l.a+l.b);
  y = (l.c+l.a*t)/(l.a+l.b);
  return x>=s1 && x<=s2 && y>=t1 && y<=t2;
}
bool between(int x, int y){ //判断 (x,y) 是否在 y=x-w 和 y=x+w 之间
  return x-y<=w && y-x<=w;  //|x-y|<=w
}
int cross(const Point & a, const Point & b){
  return a.x*b.y - a.y*b.x;
}
bool com_left(const Point & a, const Point & b){  //寻找最左下角的点P
  return a.x!=b.x ? a.x<b.x : a.y<b.y;
}
double area(VR<Point> & v){ //计算多边形面积
  int n=v.size();
  double sum=0;
  FOR(i,1,n-1)
    sum+=cross(
        Point(v[i].x-v[0].x,v[i].y-v[0].y),
        Point(v[i+1].x-v[0].x,v[i+1].y-v[0].y));
  return sum/2;
}
double angle(const Point & a, const Point & b){ //计算两点所成角
  double ma=sqrt(a.x*a.x+a.y*a.y);
  double mb=sqrt(b.x*b.x+b.y*b.y);
  return acos((a.x*b.x+a.y*b.y)/ma/mb);
}

int main(void){
  int T; scanf("%d",&T);
  FORR(kase,1,T){
    scanf("%d%d%d%d%d",&t1,&t2,&s1,&s2,&w);
    line[0]=(Line){0,1,t1}; //y=t1
    line[1]=(Line){0,1,t2}; //y=t2
    line[2]=(Line){1,0,s1}; //x=t1
    line[3]=(Line){1,0,s2}; //x=t2

    int x,y;
    VR<Point> v;
    //(s1,t2)   (s2,t2)
    //  +-----------+
    //  |           |
    //  +-----------+
    //(s1,t1)   (s2,t1)
    if(between(s1,t1)) v.push_back(Point(s1,t1));
    if(between(s1,t2)) v.push_back(Point(s1,t2));
    if(between(s2,t1)) v.push_back(Point(s2,t1));
    if(between(s2,t2)) v.push_back(Point(s2,t2));

    double are=0; //有效面积
    double S=(s2-s1)*(t2-t1); //原面积
    FOR(i,0,4){ //矩形与两直线交点
      if(getXY(x,y,line[i],w))
        v.push_back((Point){x,y});
      if(getXY(x,y,line[i],-w))
        v.push_back((Point){x,y});
    }
    if(!v.size()) goto PRINT; //如果无交点
    sort(v.begin(),v.end(),com_left);
    v[0].ang=-1.0;  //确保P排序后在第一个
    FOR(i,1,v.size()){  //计算两点所成角
      v[i].ang = angle(Point(1,0),Point(v[i].x-v[0].x,v[i].y-v[0].y));
    }
    sort(v.begin(),v.end());
    are=fabs(area(v));
#ifdef DEBUG
    printf("  total: %d\n",v.size());
    FOR(i,0,v.size()){
      printf("  (%d,%d), ang: %lf\n",v[i].x,v[i].y,v[i].ang);
    }
    printf("  area: %lf\n",are);
#endif

PRINT:
    printf("Case #%d: %.8lf\n",kase,are/S);
  }

  return 0;
}
*/
