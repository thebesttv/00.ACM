/*
题目描述
C国和W国爆发了战争！YJC决定对W国的n个城市进行轰炸。每个城市都有一个重要度ai。设xi=‘重要度大于ai的城市数+1’，那么编号为i城市就是第xi个被轰炸的城市。显然这样能保证重要度大的城市先被轰炸，重要度相同的城市同时被轰炸。现在YJC想知道，对于每一个i，xi等于多少？

输入输出格式
输入格式：
第一行包含一个整数n，表示城市个数。
第二行包含n个整数，第i个整数ai表示第i个城市的重要度。

输出格式：
一行，包含n个整数，第i个整数xi表示第i个城市是第几个被轰炸的城市。

输入输出样例
输入样例#1：
5
3 1 3 1 1

输出样例#1：
1 3 1 3 3

说明
对于100%的数据，满足1≤n≤2000，1≤ai≤10^9。
*/

/*
  得分：100
  解题报告：
  对每个城市记录重要度和序号，先对重要度排序，记录轰炸次序，再对序号排序，输出即可。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Node1{
  int a,x,n;

  bool operator < (const Node1 & b) const {
    return a>b.a;
  }
}ori[2020];
struct Node2{
  int a,x,n;

  bool operator < (const Node2 & b) const {
    return n<b.n;
  }
}res[2020];

int main(void){
  int n; scanf("%d",&n);
  for(int i=1;i<=n;i++){
    scanf("%d",&ori[i].a); ori[i].n=i;
  }
  sort(ori+1,ori+1+n);
  for(int i=1;i<=n;i++){
    if(ori[i].a==ori[i-1].a) ori[i].x=ori[i-1].x;
    else ori[i].x=i;
    res[i].a=ori[i].a; res[i].x=ori[i].x; res[i].n=ori[i].n;
  }
  sort(res+1,res+1+n);
  for(int i=1;i<=n;i++){
    if(i!=1) printf(" ");
    printf("%d",res[i].x);
  }
  printf("\n");

  return 0;
}
