/*
题目描述
为了准备一个独特的颁奖典礼，组织者在会场的一片矩形区域（可看做是平面直角坐标系的第一象限）铺上一些矩形地毯。
一共有 n 张地毯，编号从 1 到n 。现在将这些地毯按照编号从小到大的顺序平行于坐标轴先后铺设，后铺的地毯覆盖在前面已经铺好的地毯之上。
地毯铺设完成后，组织者想知道覆盖地面某个点的最上面的那张地毯的编号。
注意：在矩形地毯边界和四个顶点上的点也算被地毯覆盖。

输入输出格式
输入格式：
输入共 n+2 行。
第一行，一个整数n，表示总共有 n 张地毯。
接下来的 n 行中，第 i+1 行表示编号 i 的地毯的信息，包含四个正整数 a,b,g,k ，每两个整数之间用一个空格隔开，分别表示铺设地毯的左下角的坐标 (a,b) 以及地毯在x轴和y轴方向的长度。
第n+2 行包含两个正整数x和y，表示所求的地面的点的坐标(x,y)。

输出格式：
输出共1 行，一个整数，表示所求的地毯的编号；若此处没有被地毯覆盖则输出-1 。

输入输出样例
输入样例#1：
3
1 0 2 3
0 2 3 3
2 1 3 3
2 2

输出样例#1：
3

输入样例#2：
3
1 0 2 3
0 2 3 3
2 1 3 3
4 5

输出样例#2：
-1

说明
对于30% 的数据，有 n≤2
对于50% 的数据，0≤a,b,g,k≤100
对于100%的数据，有 0≤n≤10,000，0≤a,b,g,k≤100,000
noip2011提高组D1T1
*/

/*
  解题报告：
    遍历所有的地毯，看(x,y)是否被覆盖即可。
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
typedef long long LL;
typedef long long unsigned LLU;

const int MAX=10004;
struct Node{
  int x,y,g,k;
  int ord;  //当前地毯编号

  bool operator < (const Node & b) const {
    return x==b.x ? y<b.y : x<b.x;
  }
}a[MAX];

int main(void){
  int n; scanf("%d",&n);
  FOR(i,0,n){
    scanf("%d%d%d%d",&a[i].x,&a[i].y,&a[i].g,&a[i].k);
    a[i].ord=i+1;
  }
  int x,y,ans=-1; scanf("%d%d",&x,&y);
  sort(a,a+n);

  FOR(i,0,n){ //遍历判断
    Node & t=a[i];
    if(t.x>x && t.y>y) break; //剪枝
    if(t.x<=x && (t.x+t.g)>=x && t.y<=y && (t.y+t.k)>=y)  //如果被覆盖
      ans=max(ans,t.ord);
  }
  printf("%d\n",ans);

  return 0;
}
