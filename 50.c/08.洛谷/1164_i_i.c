/*
题目背景
uim神犇拿到了uoi的ra（镭牌）后，立刻拉着基友小A到了一家……餐馆，很低端的那种。
uim指着墙上的价目表（太低级了没有菜单），说：“随便点”。

题目描述
不过uim由于买了一些辅（e）辅（ro）书，口袋里只剩M元（M<=10000）。
餐馆虽低端，但是菜品种类不少，有N种（N<=100），第i种卖ai元（ai<=1000）。由于是很低端的餐馆，所以每种菜只有一份。
小A奉行“不把钱吃光不罢休”，所以他点单一定刚好吧uim身上所有钱花完。他想知道有多少种点菜方法。
由于小A肚子太饿，所以最多只能等待1秒。

输入输出格式
输入格式：
第一行是两个数字，表示N和M。
第二行起N个正数ai（可以有相同的数字，每个数字均在1000以内）。

输出格式：
一个正整数，表示点菜方案数。

输入输出样例
输入样例#1：
4 4
1 1 2 2

输出样例#1：
3
*/

#include<iostream>
#include<cstdio>
using namespace std;

int f[10004];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  f[0]=1;
  for(int i=1;i<=n;i++){
    int a; scanf("%d",&a);
    for(int j=m;j>=0;j--){
      if(j>=a) f[j]+=f[j-a];
    }
  }
  printf("%d\n",f[m]);

  return 0;
}

/*
int f[104][10004];
//f[i][j]: 只有前 i 个物品，组成总价为 j 的方案数
//f[i][j] = f[i-1][j] + f[i-1][j-ai], j>=ai //即使用第 i 个，或不使用第 i 个
//        = f[i-1][j], j<ai //j<ai时，只能不使用第 i 个

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=0;i<=n;i++) f[i][0]=1;
  for(int i=1;i<=n;i++){
    int a; scanf("%d",&a);
    for(int j=1;j<=m;j++){
      if(j>=a){
        f[i][j]=f[i-1][j]+f[i-1][j-a];
      }else{
        f[i][j]=f[i-1][j];
      }
    }
  }
  printf("%d\n",f[n][m]);

  return 0;
}
*/
