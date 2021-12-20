/*
描述
有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i-1, j)、 (i+1, j)、 (i, j-1)、 (i, j+1)上的砖都会改变颜色。请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。

输入
第一行是一个整数n (1≤n ≤15)，表示墙的大小。接下来的n行表示墙的初始状态。每一行包含n个字符。第i行的第j个字符表示位于位置(i,j)上的砖的颜色。“w”表示白砖，“y”表示黄砖。

输出
一行，如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。

样例输入
5
wwwww
wwwww
wwwww
wwwww
wwwww

样例输出
15
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

bool ori[20][20],a[20][20];
int n;

int Solve(int s);
int GetBit(int i, int n);
void Change(int i, int j);

int main(void){
  int T; scanf("%d",&T);
  for(int kase=0;kase<T;kase++){
    memset(ori,0,sizeof(ori)); memset(a,0,sizeof(a));
    int ans=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++) for(int j=0;j<n;j++){
      char c;
      while(!isalpha(c=getchar()));
      ori[i][j]=(c=='w' ? 0 : 1);
    }
    for(int i=0;i<(1<<n);i++){
      int t=Solve(i);
      if(t==-1) continue;
      else if(ans>=0) ans=min(ans,t);
      else ans=t;
    }
    if(ans==-1) printf("inf\n");
    else printf("%d\n",ans);
  }
  return 0;
}

int Solve(int s){
  memcpy(a,ori,sizeof(a));
  int ans=0;
  for(int i=0;i<n;i++){
    if(GetBit(s,i)){
      Change(0,i);
      ans++;
    }
  }
  for(int i=1;i<n;i++) for(int j=0;j<n;j++){
    if(!a[i-1][j]){
      Change(i,j);
      ans++;
    }
  }
  for(int i=0;i<n;i++) if(!a[n-1][i]) return -1;
  return ans;
}

int GetBit(int i, int n){
  return 1&(i>>n);
}

void Change(int i, int j){
  if(i>0) a[i-1][j]=!a[i-1][j];
  a[i][j]=!a[i][j];
  if(i<n-1) a[i+1][j]=!a[i+1][j];
  if(j>0) a[i][j-1]=!a[i][j-1];
  if(j<n-1) a[i][j+1]=!a[i][j+1];
}
