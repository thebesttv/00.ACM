/*
输入
第一行给出“炸弹”威力d(1 <= d <= 50)。第二行给出一个数组n(1 <= n <= 20)表示设置了大屏幕(有垃圾)的路口数目。接下来n行每行给出三个数字x, y, i, 分别代表路口的坐标(x, y)以及垃圾数量i. 点坐标(x, y)保证是有效的（区间在0到1024之间），同一坐标只会给出一次。

输出
输出能清理垃圾最多的投放点数目，以及能够清除的垃圾总量。
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct Node{
  int x;
  int y;
  int num;

  bool operator < (const Node &b){
    return (x<b.x || (x==b.x && y<b.y));
  }
}gar[24];
int n,d,Max,tot=0;

int Count(int x, int y);

int main(void){
  scanf("%d%d",&d,&n);
  int minx=1<<20,miny=1<<20,maxx=0,maxy=0;
  for(int i=0;i<n;i++){
    scanf("%d%d%d",&gar[i].x,&gar[i].y,&gar[i].num);
    miny=min(gar[i].y,miny);
    maxy=max(gar[i].y,maxy);
  }
  sort(gar,gar+n);
  //for(int i=0;i<n;i++) printf("%d,%d,%d\n",gar[i].x,gar[i].y,gar[i].num);
  minx=max(0,gar[0].x-d); miny=max(0,miny-d);
  maxx=min(1024,gar[n-1].x+d); maxy=min(1024,maxy+d);
  //printf("min:(%d,%d), max:(%d,%d)\n",minx,miny,maxx,maxy);
  for(int i=minx;i<=maxx;i++)
    for(int j=miny;j<=maxy;j++){
      int cou=Count(i,j);
      //printf("  (%d,%d) %d\n",i,j,cou);
      if(cou>Max){
        Max=cou; tot=1;
      }else if(cou==Max){
        tot++;
      }
    }
  printf("%d %d\n",tot,Max);

  return 0;
}

int Count(int x, int y){
  if(x<0 || y<0 || x>1024 || y>1024) return 0;
  int cou=0;
  for(int i=0;i<n;i++){
    if(gar[i].x>=x-d && gar[i].x<=x+d && gar[i].y>=y-d && gar[i].y<=y+d) cou+=gar[i].num;
  }
  return cou;
}
