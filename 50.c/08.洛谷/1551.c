/*
题目背景
若某个家族人员过于庞大，要判断两个是否是亲戚，确实还很不容易，现在给出某个亲戚关系图，求任意给出的两个人是否具有亲戚关系。

题目描述
规定：x和y是亲戚，y和z是亲戚，那么x和z也是亲戚。如果x,y是亲戚，那么x的亲戚都是y的亲戚，y的亲戚也都是x的亲戚。

输入输出格式
输入格式：
第一行：三个整数n,m,p，（n<=5000,m<=5000,p<=5000），分别表示有n个人，m个亲戚关系，询问p对亲戚关系。
以下m行：每行两个数Mi，Mj，1<=Mi，Mj<=N，表示Mi和Mj具有亲戚关系。
接下来p行：每行两个数Pi，Pj，询问Pi和Pj是否具有亲戚关系。

输出格式：
P行，每行一个’Yes’或’No’。表示第i个询问的答案为“具有”或“不具有”亲戚关系。

输入输出样例
输入样例#1：
6 5 3
1 2
1 5
3 4
5 2
1 3
1 4
2 3
5 6

输出样例#1：
Yes
Yes
No
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int p[5040];

int getParent(int x){
  return p[x]<0 ? x : p[x]=getParent(p[x]);
}
void merge(int x, int y){
  int px=getParent(x),py=getParent(y);
  if(px==py) return;
  if(p[px]<p[py]){  //|px| > |py|
    p[px]+=p[py];
    p[py]=px;
  }else{
    p[py]+=p[px];
    p[px]=py;
  }
}

int main(void){
  memset(p,-1,sizeof(p));
  int n,m,p; scanf("%d%d%d",&n,&m,&p);
  for(int i=0;i<m;i++){
    int x,y; scanf("%d%d",&x,&y);
    merge(x,y);
  }
  for(int i=0;i<p;i++){
    int x,y; scanf("%d%d",&x,&y);
    int px=getParent(x),py=getParent(y);
    printf("%s\n", px==py ? "Yes" : "No" );
  }

  return 0;
}
