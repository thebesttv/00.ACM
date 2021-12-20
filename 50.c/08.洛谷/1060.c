/*
题目描述
金明今天很开心，家里购置的新房就要领钥匙了，新房里有一间他自己专用的很宽敞的房间。更让他高兴的是，妈妈昨天对他说：“你的房间需要购买哪些物品，怎么布置，你说了算，只要不超过N元钱就行”。今天一早金明就开始做预算，但是他想买的东西太多了，肯定会超过妈妈限定的N元。于是，他把每件物品规定了一个重要度，分为5等：用整数1~5表示，第5等最重要。他还从因特网上查到了每件物品的价格（都是整数元）。他希望在不超过N元（可以等于N元）的前提下，使每件物品的价格与重要度的乘积的总和最大。
设第j件物品的价格为v[j]，重要度为w[j]，共选中了k件物品，编号依次为j1，j2，……，jk，则所求的总和为：
v[j1]*w[j1]+v[j2]*w[j2]+ …+v[jk]*w[jk]。（其中*为乘号）
请你帮助金明设计一个满足要求的购物单。

输入输出格式
输入格式：
输入的第1行，为两个正整数，用一个空格隔开：
N m （其中N（<30000）表示总钱数，m（<25）为希望购买物品的个数。）
从第2行到第m+1行，第j行给出了编号为j-1的物品的基本数据，每行有2个非负整数
v p （其中v表示该物品的价格(v<=10000)，p表示该物品的重要度(1~5)）

输出格式：
输出只有一个正整数，为不超过总钱数的物品的价格与重要度乘积的总和的最大值（<100000000）。

输入输出样例
输入样例#1：
1000 5
800 2
400 5
300 5
400 3
200 2

输出样例#1：
3900

说明
NOIP2006 普及组 第二题
*/

//ori
//f[i][j]: 使用前 i 个物品，共有 j 元时的最优解
//f[i][j] = f[i-1][j], j<vi
//          max(f[i-1][j], f[i-1][j-vi]+vi*pi), j>=vi
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=30;
int f[MAX][30000];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=m;i++){
    int v,p; scanf("%d%d",&v,&p);
    for(int j=n;j>=0;j--){
      f[i][j]=f[i-1][j];
      if(j>=v) f[i][j]=max(f[i][j],f[i-1][j-v]+v*p);
    }
  }
  printf("%d\n",f[m][n]);

  return 0;
}

/*
//空间优化
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[30020];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++){
    int v,p; scanf("%d%d",&v,&p);
    for(int j=n;j>=0;j--){
      if(j>=v) f[j]=max(f[j],f[j-v]+v*p);
    }
  }
  printf("%d\n",f[n]);

  return 0;
}
*/

/*
//f[i][j]: 从第 i 个物件到第 n 个物件，共有 j 元时的最优解
//f[i][j] = f[i+1][j], j<vi
//          max(f[i+1][j], f[i+1][j-vi]+vi*pi), j>=vi
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX=30;
int f[MAX][30020];
int v[MAX],p[MAX];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) scanf("%d%d",&v[i],&p[i]);
  for(int i=m;i>=0;i--){
    for(int j=0;j<=n;j++){
      //if(j<v[i]) f[i][j]=f[i+1][j];
      //else f[i][j]=max(f[i+1][j],f[i+1][j-v[i]]+v[i]*p[i]);
      f[i][j]=f[i+1][j];
      if(j>=v[i]) f[i][j]=max(f[i][j],f[i+1][j-v[i]]+v[i]*p[i]);
    }
  }
  printf("%d\n",f[0][n]);

  return 0;
}
*/

/*
//空间优化
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int f[30020];
int v[30],p[30];

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=0;i<m;i++) scanf("%d%d",&v[i],&p[i]);
  for(int i=m;i>=0;i--){
    for(int j=n;j>=0;j--){
      if(j>=v[i]) f[j]=max(f[j],f[j-v[i]]+v[i]*p[i]);
    }
  }
  printf("%d\n",f[n]);

  return 0;
}
*/

/*
//记忆化
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

const int MAX=30;
const int MAXN=30020;
int n,m;
int v[MAX],p[MAX],check[MAX][MAXN];

int f(int i, int j){
  if(i<0 || j<0) return 0;
  int & a=check[i][j];
  if(a!=-1) return a;
  if(j>=v[i]) a=f(i-1,j-v[i])+v[i]*p[i];
  return a=max(a,f(i-1,j));
}

int main(void){
  MST(check,-1);
  scanf("%d%d",&n,&m);
  FOR(i,0,m) scanf("%d%d",&v[i],&p[i]);
  printf("%d\n",f(m-1,n));

  return 0;
}
*/
