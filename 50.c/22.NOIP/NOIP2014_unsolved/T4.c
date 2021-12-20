/*
描述
随着智能手机的日益普及，人们对无线网的需求日益增大。某城市决定对城市内的公共场所覆盖无线网。
假设该城市的布局为由严格平行的 129 条东西向街道和 129 条南北向街道所形成的网格状，并且相邻的平行街道之间的距离都是恒定值 1 。东西向街道从北到南依次编号为0,1,2...128,南北向街道从西到东依次编号为 0,1,2...128。
东西向街道和南北向街道相交形成路口，规定编号为 x 的南北向街道和编号为 y 的东西向街道形成的路口的坐标是（x, y）。在某些路口存在一定数量的公共场所。
由于政府财政问题，只能安装一个大型无线网络发射器。该无线网络发射器的传播范围是一个以该点为中心，边长为 2*d 的正方形。传播范围包括正方形边界。
例如下图是一个 d = 1 的无线网络发射器的覆盖范围示意图。

    +---+---+---+---+
    |   |   |   |   |
    +---*---*---*---+
    |   |   |   |   |   #: 无线网络发射器安装位置
    +---*---#---*---+   *: 被覆盖的节点
    |   |   |   |   |
    +---*---*---*---+
    |   |   |   |   |
    +---+---+---+---+

现在政府有关部门准备安装一个传播参数为 d 的无线网络发射器，希望你帮助他们在城 市内找出合适的安装地点，使得覆盖的公共场所最多。

格式
输入格式
第一行包含一个整数 d，表示无线网络发射器的传播距离。
第二行包含一个整数 n，表示有公共场所的路口数目。
接下来 n 行，每行给出三个整数 x, y, k, 中间用一个空格隔开，分别代表路口的坐标(x, y)以及该路口公共场所的数量。同一坐标只会给出一次。

输出格式
输出一行，包含两个整数，用一个空格隔开，分别表示能覆盖最多公共场所的安装地点方案数，以及能覆盖的最多公共场所的数量。

样例1
样例输入1
1
2
4 4 10
6 6 20

样例输出1
1 30

限制
对于 100%的数据，1 ≤ d ≤ 20，1 ≤ n ≤ 20， 0 ≤ x ≤ 128, 0 ≤ y ≤ 128, 0 < k ≤ 1,000,000。

来源
NOIP2014 提高组 Day2
*/

/*
  得分：100
  解题报告：
    直接枚举即可。
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

const int MAX=30;
struct Node{
  int x,y,n;
}node[MAX];
int d,n;

int main(void){
  scanf("%d%d",&d,&n);
  FOR(i,0,n) scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].n);
  int ansMax=0,cnt=0;
  FOR(i,0,129) FOR(j,0,129){
    int sum=0;
    FOR(k,0,n) if(node[k].x>=i-d && node[k].x<=i+d && node[k].y>=j-d && node[k].y<=j+d){
      sum+=node[k].n;
    }
    if(sum>ansMax) {ansMax=sum; cnt=1;}
    else if(sum==ansMax) cnt++;
  }
  printf("%d %d\n",cnt,ansMax);

  return 0;
}
