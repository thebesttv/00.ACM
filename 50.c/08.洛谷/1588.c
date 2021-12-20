/*
题目描述
FJ丢失了他的一头牛，他决定追回他的牛。已知FJ和牛在一条直线上，初始位置分别为x和y，假定牛在原地不动。FJ的行走方式很特别：他每一次可以前进一步、后退一步或者直接走到2*x的位置。计算他至少需要几步追上他的牛。

输入输出格式
输入格式：
第一行为一个整数t(≤10)，表示数据组数；接下来每行包含一个两个正整数x和y(x,y≤10^5)，分别表示FJ和牛的坐标。

输出格式：
对于每组数据，输出最少步数。

输入输出样例
输入样例#1：
1
5 17

输出样例#1：
4
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int MAX=100000;
struct Node{
  int x;
  int step;

  Node() { }
  Node(int x_, int step_): x(x_), step(step_) { }
};
bool vis[MAX+20];

int bfs(int x, int y){
  queue<Node> q; memset(vis,0,sizeof(vis));
  q.push(Node(x,0)); vis[x]=1;
  while(!q.empty()){
    Node temp=q.front(); q.pop();
    if(temp.x==y) return temp.step;
    int t=temp.x*2;
    if(temp.x<y && t<=MAX && !vis[t]){
      q.push(Node(t,temp.step+1)); vis[t]=1;
    }
    t=temp.x+1;
    if(temp.x<y && t<=MAX && !vis[t]){
      q.push(Node(t,temp.step+1)); vis[t]=1;
    }
    t=temp.x-1;
    if(t>=0 && !vis[t]){
      q.push(Node(t,temp.step+1)); vis[t]=1;
    }
  }
}

int main(void){
  int T; scanf("%d",&T);
  while(T--){
    int x,y; scanf("%d%d",&x,&y);
    printf("%d\n",bfs(x,y));
  }

  return 0;
}
