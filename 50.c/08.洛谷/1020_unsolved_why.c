/*
题目描述
某国为了防御敌国的导弹袭击，发展出一种导弹拦截系统。但是这种导弹拦截系统有一个缺陷：虽然它的第一发炮弹能够到达任意的高度，但是以后每一发炮弹都不能高于前一发的高度。某天，雷达捕捉到敌国的导弹来袭。由于该系统还在试用阶段，所以只有一套系统，因此有可能不能拦截所有的导弹。
输入导弹依次飞来的高度（雷达给出的高度数据是不大于50000的正整数），计算这套系统最多能拦截多少导弹，如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入输出格式
输入格式：
一行，若干个整数（个数少于100000）

输出格式：
2行，每行一个整数，第一个数字表示这套系统最多能拦截多少导弹，第二个数字表示如果要拦截所有导弹最少要配备多少套这种导弹拦截系统。

输入输出样例
输入样例#1：
389 207 155 300 299 170 158 65

输出样例#1：
6
2

说明
为了让大家更好地测试n方算法，本题开启spj，n方100分，nlogn200分
每点两问，按问给分
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

const int MAX=100020;
int h[MAX],f[MAX],n;

int main(void){
  while(scanf("%d",&h[n])==1) n++;

  int tMax=0;
  FOR(i,0,n){
    f[i]=1;
    FOR(j,0,i) if(h[j]>=h[i]) f[i]=max(f[i],f[j]+1);
    tMax=max(tMax,f[i]);
  }
  printf("%d\n",tMax);
  MST(f,0); tMax=0;
  FOR(i,0,n){
    f[i]=1;
    FOR(j,0,i) if(h[j]<h[i]) f[i]=max(f[i],f[j]+1);
    tMax=max(tMax,f[i]);
  }
  printf("%d\n",tMax);

  return 0;
}

//solution

/*
我是数据加强以后的第一篇题解（这也是我关于单调性的第一篇题解）这篇有纪念性的文章我要发博客上，不要认为我是复制他人题解

数据加强到了100000，你要是想得满分200，就必须通过单调性来做（想得100的用n^2算法），而且还要一个神奇的思想（我无法证明），那就是，求一个序列里面最少有多少最长不上升序列等于求这个序列里最长上升序列的长度。我们用f[x]数组（第一问）来记录当前长度为x的不上升序列中最大的结束点（这个运用了贪心的思想），如果当前数小于等于当前的最长不上升序列的结束点，那么我们把当前最长的不上升序列长度加一，把当前数作为这个 不下降序列的结束点，不然我们就用二分查找（为什么可以呢？这是因为我们运用了贪心的思/想后能保证长度越大的不上升序列结束点越小），试着用当前数去更新长度为x的不上升序列的结束点（又是贪心的思想，只更新长度最长且结束点小于自己的），然后第二问你再反着做就行了（把大于等于改为小于）
*/

#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;
const int maxn=100005;
int a[maxn];
int f[maxn];
int main()
{
  int n=0;
  int l,r,mid;
  while(scanf("%d",&a[++n])!=EOF)continue;
  n--;
  f[0]=1234123412;//这个数要大于50000，不然可能你就无法更新
  int ans1=0;
  for(int i=1;i<=n;i++){
    if(f[ans1]>=a[i]){
      f[ans1+1]=a[i];//结束点为a[i]
      ans1++; //当前最长不上升序列的长度加一
    }
    else {//二分查找
      l=0;r=ans1;
      while(l<r){
        mid=(l+r)/2;
        if(f[mid]>=a[i])l=mid+1;
        else {
          r=mid;    
        }
      }
      if(l!=0)f[l]=a[i];
    }
  }
  cout<<ans1<<endl;//输出第一问的答案
  memset(f,-1,sizeof(f));//这次前面要尽量小了，不然又无法更新
  int ans2=0;
  for(int i=1;i<=n;i++){
    if(f[ans2]<a[i]){
      f[ans2+1]=a[i];//结束点为a[i]
      ans2++; //当前最长上升序列长度加一
    }
    else {//二分查找
      l=0;r=ans2;
      while(l<r){
        mid=(l+r)/2;
        if(f[mid]>=a[i])r=mid;
        else {
          l=mid+1;    
        }
      }
      f[l]=a[i];
    }
  }
  cout<<ans2<<endl;//输出第二个答案
}
