/*
描述
N位同学站成一排，音乐老师要请其中的(N-K)位同学出列，使得剩下的K位同学排成合唱队形。
合唱队形是指这样的一种队形：设K位同学从左到右依次编号为1，2…，K，他们的身高分别为T1，T2，…，TK， 则他们的身高满足T1<...<Ti>Ti+1>…>TK(1<=i<=K)。
你的任务是，已知所有N位同学的身高，计算最少需要几位同学出列，可以使得剩下的同学排成合唱队形。

格式
输入格式
输入的第一行是一个整数N(2<=N<=100)，表示同学的总数。第一行有n个整数，用空格分隔，第i个整数Ti(130<=Ti<=230)是第i位同学的身高(厘米)。

输出格式
输出包括一行，这一行只包含一个整数，就是最少需要几位同学出列。

样例1
样例输入1
8
186 186 150 200 160 130 197 220

样例输出1
4

限制
每个测试点1s

来源
NOIp 2004
*/

/*
  得分：100
  解题报告：
    一开始想到贪心，但发现不可行。
    后来发现，题目实质上在求最大上升子序列和最大下降子序列，使用动规，完成。
    也可以预先处理f(i),g(i)，其中
      f(i)为[1,i]中最大上升子序列的长度
      g(i)为[i,n]中最大下降子序列的长度
      f(i) = max{ f(j)+1 | 1<=j<i && a[j]<a[i] }
      g(i) = max{ g(j)+1 | i<j<=n && a[j]<a[i] }
    然后找到i，使得 t=f(i)+g(i)-1 最大，答案即为n=t。
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=120;
int a[MAX],n;
int f[MAX];

int cal(int m){
  memset(f,0,sizeof(f));
  f[0]=1;
  for(int i=1;i<=m;i++){
    int t=0;
    for(int j=0;j<i;j++) if(a[j]<a[i] && f[j]>t) t=f[j];
    f[i]=t+1;
  }
  int temp=f[m]; f[m]=0;
  f[n-1]=1;
  for(int i=n-2;i>=m;i--){
    int t=0;
    for(int j=n-1;j>i;j--) if(a[j]<a[i] && f[j]>t) t=f[j];
    f[i]=t+1;
  }
  return n-f[m]-temp+1;
}

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  int ansMin=n;
  for(int i=0;i<n;i++) ansMin=min(ansMin,cal(i));
  printf("%d\n",ansMin);

  return 0;
}
