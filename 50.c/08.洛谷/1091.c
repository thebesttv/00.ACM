/*
题目描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK， 则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

输入输出格式
输入格式：
输入文件chorus.in的第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，用空格分隔，第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。

输出格式：
输出文件chorus.out包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

输入输出样例
输入样例#1：
8
186 186 150 200 160 130 197 220

输出样例#1：
4

说明
对于50％的数据，保证有n<=20；
对于全部的数据，保证有n<=100。
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

const int MAX=120;
int n,h[MAX],f[MAX],g[MAX];

int main(void){
  scanf("%d",&n);
  FOR(i,0,n) scanf("%d",&h[i]);
  FOR(i,0,n){
    f[i]=1;
    FOR(j,0,i) if(h[j]<h[i]) f[i]=max(f[i],f[j]+1);
  }
  ROR(i,n-1,0){
    g[i]=1;
    ROR(j,n-1,i) if(h[j]<h[i]) g[i]=max(g[i],g[j]+1);
  }
  int tMax=0;
  FOR(i,0,n) tMax=max(tMax,f[i]+g[i]-1);
  printf("%d\n",n-tMax);

  return 0;
}
