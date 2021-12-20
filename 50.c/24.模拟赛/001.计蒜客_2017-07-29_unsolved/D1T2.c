/*
描述
蒜头君有一棵有根树，树的每一边都有边权，蒜头君想知道任意两点间最短距离之和为多少。另外，由于各种原因，蒜头君的树的边的边权会发生若干次改变，蒜头君想让你告诉他，每一次改变后，任意两点间最短距离之和为多少？

输入格式
第一行一个正整数 n，表示蒜头君的树上的结点个数。
接下来 n−1 行，每行两个正整数 xi,yi。xi 表示 i+1 号结点的父亲结点的编号，保证其父结点编号小于自己编号。yi 表示 i+1 号结点的父亲结点与自己间边的距离。
接下来一行一个整数 m，表示树的边权发生改变的次数。
接下来 m 行，每行两个正整数 a,b，表示将 a 结点与其父亲结点之间的距离改为 b，保证 a≥2。

输出格式
先输出一个整数，表示对于原始的树任意两点间最短距离之和。
接下来 m 行，每行输出一个整数，表示每一次改变后，任意两点间最短距离之和。

样例输入

4
1 1
1 1
1 1
1
2 2

样例输出

9
12
*/

/*
  得分：0
*/

//暴力，估分：30
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=100000+20;
int p[MAX],w[MAX];
bool vis[MAX];
int n,m;

unsigned long long getSum(int x, int y){
  memset(vis,0,sizeof(vis));
  int pos=x;
  while(p[pos]>0){
    vis[pos]=1; pos=p[pos];
  }
  pos=y;
  while(p[pos]>0){
    if(vis[pos]) break;
    else pos=p[pos];
  }
  long long sum=0;
  while(x>0){ sum+=w[x]; x=p[x]; }
  while(y>0){ sum+=w[y]; y=p[y]; }
  return sum;
}

int main(void){
#ifdef LOCAL
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  register int x,y;
  for(register int i=2;i<=n;++i){
    scanf("%d%d",&x,&y);
    p[i]=x; w[i]=y;
  }
  memset(p,-1,sizeof(int)*(n+4));
  register unsigned long long sum=0;
  for(register int i=1;i<=n;++i) for(register int j=i+1;j<=n;++j) sum+=getSum(i,j);
  printf("%llu\n",sum);
  scanf("%d",&m);
#ifdef DEBUG
  printf("  m: %d\n",m);
#endif
  for(register int i=0;i<m;++i){  //改进
    scanf("%d%d",&x,&y); w[x]=y;
    sum=0;
    for(register int j=1;j<=n;++j) for(register int k=j+1;k<=n;++k) sum+=getSum(j,k);
    printf("%llu\n",sum);
  }

  return 0;
}
