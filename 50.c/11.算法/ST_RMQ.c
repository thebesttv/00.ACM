/*
  ST算法 O(nlogn + m)

  ST算法是一种使用动态规划的在线查询RMQ的算法。其核心思想为：使用f(i,j)表示区间[i,i+2^j-1]的最值。
  递推式：f(i,j) = a[i], j=0
                   min{ f(i,j-1), f(i+2^(j-1),j-1) }
  ST算法的预处理需要O(nlogn)的复杂度。
  对每个查询区间[L,R]，令k，使2^k<R-L+1，即k=floor(log_2(R-L+1))，因为C++中没有log2，所以使用换底公式，得 k=floor((double)log(R-L+1)/log(2))，再查询 RMQ{ f(l,k), f(r-2^k+1,k) } 即可，查询复杂度为O(1)。
*/

//查询最小值
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int MAX=1000;
int a[MAX];
int f[MAX][10];  //大小：MAX*ceil(log_2(MAX))
int n;

void rmq_init(){
  for(int i=1;i<=n;i++) f[i][0]=a[i];
  int k=floor(log(n)/log(2.0)); //<b></b>
  for(int j=1;j<=k;j++){
    for(int i=n;i>=1;i--) if(i+(1<<(j-1))<=n)
      f[i][j] = min( f[i][j-1], f[i+(1<<(j-1))][j-1] ); //<b></b>
  }
}

int query(int l, int r){
  int k=floor(log(r-l+1.0)/log(2));
  return min( f[l][k], f[r-(1<<k)+1][k] );  //<b></b>
}

int main(void){
  int m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%d",&a[i]);
  rmq_init();
  int l,r;
  for(int i=0;i<m;i++){
    scanf("%d%d",&l,&r); printf("%d\n",query(l,r));
  }

  return 0;
}
