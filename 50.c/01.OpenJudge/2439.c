/*
描述
For the daily milking, Farmer John's N cows (1 ≤ N ≤ 50,000) always line up in the same order. One day Farmer John decides to organize a game of Ultimate Frisbee with some of the cows. To keep things simple, he will take a contiguous range of cows from the milking lineup to play the game. However, for all the cows to have fun they should not differ too much in height.
Farmer John has made a list of Q (1 ≤ Q ≤ 200,000) potential groups of cows and their heights (1 ≤ height ≤ 1,000,000). For each group, he wants your help to determine the difference in height between the shortest and the tallest cow in the group.

输入
Line 1: Two space-separated integers, N and Q.
Lines 2..N+1: Line i+1 contains a single integer that is the height of cow i
Lines N+2..N+Q+1: Two integers A and B (1 ≤ A ≤ B ≤ N), representing the range of cows from A to B inclusive.

输出
Lines 1..Q: Each line contains a single integer that is a response to a reply and indicates the difference in height between the tallest and shortest cow in the range.

样例输入
6 3
1
7
3
4
2
5
1 5
4 6
2 2

样例输出
6
3
0
*/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[200020],n;
int amin[200020][18];
int amax[200020][18];

void rmq_init();
int qmin(int l, int r, int k);
int qmax(int l, int r, int k);

int main(void){
  int m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  rmq_init();
  int l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d",&l,&r);
    int k=floor(log(r-l+1)/log(2));
    printf("%d\n",qmax(l,r,k)-qmin(l,r,k));
  }

  return 0;
}

void rmq_init(){
  for(int i=1;i<=n;i++) amax[i][0]=amin[i][0]=a[i];
  int k=floor(log(n)/log(2));
  for(int j=1;j<=k;j++)
    for(int i=n;i>=1;i--) if(i+(1<<(j-1))<=n){
      amin[i][j]=min(amin[i][j-1],amin[i+(1<<(j-1))][j-1]);
      amax[i][j]=max(amax[i][j-1],amax[i+(1<<(j-1))][j-1]);
    }
}
int qmin(int l, int r, int k){
  return min(amin[l][k],amin[r-(1<<k)+1][k]);
}
int qmax(int l, int r, int k){
  return max(amax[l][k],amax[r-(1<<k)+1][k]);
}
