/*
题目描述
有n个人在一个水龙头前排队接水，假如每个人接水的时间为Ti（实数，非整数），请编程找出这n个人排队的一种顺序，使得n个人的平均等待时间最小。

输入输出格式
输入格式：
输入文件共两行，第一行为n；第二行有n个实数，分别表示第1个人到第n个人每人的接水时间T1，T2，…，Tn，每个数据之间有1个空格。
,
输出格式：
输出文件有两行，第一行为一种排队顺序，即1到n的一种排列；第二行为这种排列方案下的平均等待时间(输出结果精确到小数点后两位)。

输入输出样例
输入样例#1：
10 
56 12 1 99 1000 234 33 55 99 812

输出样例#1：
3 2 7 8 1 4 9 6 10 5
291.90

说明
n<=1000
ti<=1e6，不保证ti不重复
当ti重复时，按照输入顺序即可（sort是可以的）
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const double EPS=1e-6;
struct Ind{
  double t;
  int num;

  bool operator < (const Ind & b) const {
    return fabs(t-b.t)>EPS ? t<b.t : num<b.num;
  }
}ind[1020];
double s[1020];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%lf",&ind[i].t); ind[i].num=i+1;
  }
  sort(ind,ind+n);
  for(int i=0;i<n;i++) printf("%d ",ind[i].num); printf("\n");
  s[0]=ind[0].t;
  for(int i=1;i<n;i++) s[i]=s[i-1]+ind[i].t;
  double sum=0;
  for(int i=0;i<n-1;i++) sum+=s[i];
  printf("%.2lf\n",sum/n);
  
  return 0;
}
