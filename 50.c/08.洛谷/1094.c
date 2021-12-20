/*
题目描述
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。
你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。

输入输出格式
输入格式：
输入文件group.in包含n+2行:
第1行包括一个整数w，为每组纪念品价格之和的上上限。
第2行为一个整数n，表示购来的纪念品的总件数G
第3~n+2行每行包含一个正整数Pi (5 <= Pi <= w)表示所对应纪念品的价格。

输出格式：
输出文件group.out仅一行，包含一个整数，即最少的分组数目。

输入输出样例
输入样例#1：
100 
9 
90 
20 
20 
30 
50 
60 
70 
80 
90

输出样例#1：
6

说明
50%的数据满足：1<=n<=15
100%的数据满足：1<=n<=30000，80<=w<=200
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
#define DQ deque
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=30020;
int a[MAX],w,n;
DQ<int> q;

int main(void){
  scanf("%d%d",&w,&n);
  FOR(i,0,n) scanf("%d",&a[i]);
  sort(a,a+n);
  FOR(i,0,n) q.push_back(a[i]);
  int cnt=0;
  while(q.size()>1){
    int a=q.front(),b=q.back();
    if(a+b<=w) q.pop_front(),q.pop_back();
    else q.pop_back();
    cnt++;
  }
  if(!q.empty()) cnt++;
  printf("%d\n",cnt);

  return 0;
}
