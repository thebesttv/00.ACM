/*
描述
在Mars星球上，每个Mars人都随身佩带着一串能量项链。在项链上有N颗能量珠。能量珠是一颗有头标记与尾标记的珠子，这些标记对应着某个正整数。并且，对于相邻的两颗珠子，前一颗珠子的尾标记一定等于后一颗珠子的头标记。因为只有这样，通过吸盘（吸盘是Mars人吸收能量的一种器官）的作用，这两颗珠子才能聚合成一颗珠子，同时释放出可以被吸盘吸收的能量。如果前一颗能量珠的头标记为m，尾标记为r，后一颗能量珠的头标记为r，尾标记为n，则聚合后释放的能量为 m*r*n （Mars单位），新产生的珠子的头标记为m，尾标记为n。
需要时，Mars人就用吸盘夹住相邻的两颗珠子，通过聚合得到能量，直到项链上只剩下一颗珠子为止。显然，不同的聚合顺序得到的总能量是不同的，请你设计一个聚合顺序，使一串项链释放出的总能量最大。
例如：设N=4，4颗珠子的头标记与尾标记依次为(2，3) (3，5) (5，10) (10，2)。我们用记号⊕ 表示两颗珠子的聚合操作，(j⊕ k)表示第j，k两颗珠子聚合后所释放的能量。则第4、1两颗珠子聚合后释放的能量为：
(4⊕ 1)=10*2*3=60。
这一串项链可以得到最优值的一个聚合顺序所释放的总能量为
(((4⊕ 1)⊕ 2)⊕ 3) = 10*2*3+10*3*5+10*5*10 = 710。

格式
输入格式
输入文件的第一行是一个正整数N（4≤N≤100），表示项链上珠子的个数。第二行是N个用空格隔开的正整数，所有的数均不超过1000。第i个数为第i颗珠子的头标记（1≤i≤N），当1≤i＜N时，第i颗珠子的尾标记应该等于第i+1颗珠子的头标记。第N颗珠子的尾标记应该等于第1颗珠子的头标记。
至于珠子的顺序，你可以这样确定：将项链放到桌面上，不要出现交叉，随意指定第一颗珠子，然后按顺时针方向确定其他珠子的顺序。

输出格式
输出文件只有一行，是一个正整数E（E≤2.1*10^9），为一个最优聚合顺序所释放的总能量。

样例1
样例输入1
4
2 3 5 10

样例输出1
710

限制
1s

来源
NOIP2006第一题
*/

/*
  得分：10
  解题报告：（考后）
    区间dp。用 f[i][j] 表示头和尾分别为第i个和第j个珠子，在区间[i,j]内组合，所能求得的最大能量
      f[i][j] = max{ f[i][k] + f[k+1][j] + a[i]*a[k+1]*a[j+1] | i<=k<j} //相当于用两个小的珠子组合成一个大的珠子。
    得到了状态转移方程，最容易写的是递归。
    递推形式的写法：
      观察转移方程，发现 f[i][k] 中的k充当了“j”，且 k<j ，因此是使用小的j更新大的j，所以j要正序递推；而 f[k+1][j] 中的k+1充当了“i”，且 k+1>i ，因此是使用大的i更新小的i，所以i要倒序递推；k的顺序随意。
    又因为初始时十一个环，起点不定，则要以环的形式读入并解决。
    在读入时，读入ori[i]的同时令ori[i+n]=ori[i]，也就是说将ori复制到它的后面去，这样一来，只要遍历 f[i][i+n-1], 0<=i<n，其中最大值即为答案。
*/

//递推
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=120;
int ori[MAX*2];
int f[MAX*2][MAX*2];

int main(void){
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&ori[i]); ori[n+i]=ori[i];
  }

  for(int i=2*n-2-1;i>=0;i--){    //i倒序
    for(int j=i+1;j<=2*n-2;j++){  //j正序
      for(int k=i;k<j;k++){
        f[i][j] = max(f[i][j], f[i][k] + f[k+1][j] + ori[i]*ori[k+1]*ori[j+1]);
      }
    }
  }

  int ansMax=0;
  for(int i=0;i<n;i++) ansMax=max(ansMax,f[i][i+n-1]);
  printf("%d\n",ansMax);

  return 0;
}


/*
//记忆化搜索
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=120;
int ori[MAX*2];
int check[MAX*2][MAX*2];

int f(int l, int r){
  int & a=check[l][r];
  if(a!=-1) return a;
  if(l==r) a=0;
  else for(int k=l;k<r;k++){
    a=max(a, f(l,k) + f(k+1,r) + ori[l]*ori[k+1]*ori[r+1]);
  }
#ifdef DEBUG
  printf("  f(%d,%d)=%d, updated\n",l,r,a);
#endif
  return a;
}

int main(void){
  memset(check,-1,sizeof(check));
  int n; scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d",&ori[i]); ori[n+i]=ori[i];
  }
  int ansMax=0;
  for(int i=0;i<n;i++) ansMax=max(ansMax,f(i,i+n-1));
  printf("%d\n",ansMax);

  return 0;
}
*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=120;
bool vis[MAX];
int n,a[MAX];
int ansMax=0;

void dfs(int cur, int head, int tail, int pow){ //使用了cur颗珠子，头标记为head，尾标记为tail，当前能量为pow
  //问题：只能模拟“把一颗珠子连到当前大珠子的后面”，不能模拟“将两颗或多棵小珠子合成后，再放在当前珠子后面”
  if(cur==n){
    ansMax=max(ansMax,pow);
    return;
  }

  for(int i=0;i<n;i++) if(!vis[i] && a[i]==tail){
    vis[i]=1;
    int tpow=head*tail*a[i+1];
    dfs(cur+1,head,a[i+1],pow+tpow);
    vis[i]=0;
  }
}

int main(void){
  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&a[i]);
  a[n]=a[0];

  for(int i=0;i<n;i++){
    memset(vis,0,sizeof(vis));
    vis[i]=1;
    dfs(1,a[i],a[i+1],0);
  }
  printf("%d\n",ansMax);

  return 0;
}
*/
