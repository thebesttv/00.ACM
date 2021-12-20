/*
描述
设一个n个节点的二叉树tree的中序遍历为（l,2,3,…,n），其中数字1,2,3,…,n为节点编号。每个节点都有一个分数（均为正整数），记第i个节点的分数为di，tree及它的每个子树都有一个加分，任一棵子树subtree（也包含tree本身）的加分计算方法如下：
  subtree的左子树的加分 * subtree的右子树的加分 + subtree的根的分数
若某个子树为空，规定其加分为1。叶子的加分就是叶节点本身的分数，不考虑它的空子树。
试求一棵符合中序遍历为（1,2,3,…,n）且加分最高的二叉树tree。要求输出；
  1.tree的最高加分
  2.tree的前序遍历

格式
输入格式
第1行：一个整数n（n<30），为节点个数。
第2行：n个用空格隔开的整数，为每个节点的分数（分数<100）。

输出格式
第1行：一个整数，为最高加分（结果不会超过4,000,000,000）。
第2行：n个用空格隔开的整数，为该树的前序遍历。

样例1
样例输入1
5
5 7 1 2 10

样例输出1
145
3 1 2 4 5

限制
每个测试点1s

来源
NOIP2003第三题
*/

/*
  得分：100
  解题报告：
    一开始想到贪心，但发现错误。然后写了一个暴力。后来想到记忆化搜索，写出代码。然而写完发现答案中还要有前序遍历，非常焦虑，花了大约半个小时才写完前序遍历的函数。
    而如果想方设法减少维度，可能会有更好的效果。
  正解：
    令f(i,j)表示区间[i,j]中可行成的加分最大的树，并用root[i][j]记录使得加分最大的树根，则
      f(i,j) = max{ f(i,k-1)*f(k+1,j) +ori[k] | i<=k<=j }
    以后查找遍历时只要关注root[i][j]即可，效率得到很大提升。
*/

#include<iostream>
#include<cstdio>
using namespace std;

typedef unsigned int U;
const int MAX=34;
U ori[MAX];
U f[MAX][MAX];    //f[i][j]: [i,j]内加分最大的
                  //f[l][r] = max{ f[l][i-1]*f[i+1][r] + orl[i] | l<=i<=r }
U root[MAX][MAX]; //root[i][j]: [i,j]内加分最大的树的树根

U dfs(int l, int r){
  U & a=f[l][r];
  if(a) return a;
  if(l>r) a=1;  //<b>思考全面</b>
  else if(l==r) a=ori[l],root[l][r]=l;
  else{
    a=0;
    for(int i=l;i<=r;i++){
      U t=dfs(l,i-1)*dfs(i+1,r)+ori[i];
      if(t>a) a=t,root[l][r]=i;
    }
  }
  return a;
}
void pre(int l, int r){
  if(l>r) return; //<b></b>
  printf("%d ",root[l][r]);
  pre(l,root[l][r]-1);
  pre(root[l][r]+1,r);
}

int main(void){
  int n; scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%u",&ori[i]);
  U ans=dfs(1,n);
  printf("%u\n",ans);
  pre(1,n); printf("\n");

  return 0;
}

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef unsigned int U;
U ori[34];
U check[34][34][34];
int n;
bool first=0,vis[34];

U dfs(int root, int l, int r);
void pre(int root, int l, int r);

int main(void){
  scanf("%d",&n);
  for(int i=1;i<=n;i++) scanf("%u",&ori[i]);
  U ansMax=0,u;
  for(int i=1;i<=n;i++){
    U t=dfs(i,1,n);
    t>ansMax ? ansMax=t,u=i : 0;
  }
  printf("%u\n",ansMax);
#ifdef DEBUG
  for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=1;k<=n;k++){
    printf("  check[%d][%d][%d]: %u\n",i,j,k,check[i][j][k]);
  }
#endif
  vis[u]=1; pre(u,1,n);
  printf("\n");

  return 0;
}

U dfs(int root, int l, int r){
  U & a=check[root][l][r];
  if(a) return a;

  U ansMax=0;
  if(l==r) ansMax=ori[l];
  else{
    U lc,rc;
    if(l==root){  //左子树为空
      lc=1;
      for(int i=root+1;i<=r;i++){
        rc=dfs(i,root+1,r);
        U t=lc*rc+ori[root];
        t>ansMax ? ansMax=t : 0;
      }
    }else if(r==root){  //右子树为空
      rc=1;
      for(int i=l;i<root;i++){
        lc=dfs(i,l,root-1);
        U t=lc*rc+ori[root];
        t>ansMax ? ansMax=t : 0;
      }
    }else{
      for(int i=l;i<root;i++) for(int j=root+1;j<=r;j++){
        lc=dfs(i,l,root-1), rc=dfs(j,root+1,r);
        U t=lc*rc+ori[root];
        t>ansMax ? ansMax=t : 0;
      }
    }
  }
  return a=ansMax;
}
void pre(int root, int l, int r){ //但愿没有重复的
  U val=check[root][l][r];        //对每个f(root,l,r)，先输出root，再查找i,j，使得
  if(!first) first=1;             // f(i,l,root-1)*f(j,root+1,r) + ori[root] = f(root,l,r)，并依次进入递归
  else printf(" ");
  printf("%d",root);
  if(l==root){  //左子树为空
    for(int i=root+1;i<=r;i++) if(!vis[i])
      if(check[i][root+1][r]+ori[root]==val){
        vis[i]=1; pre(i,root+1,r);
        break;
      }
  }else if(r==root){  //右子树为空
    for(int i=l;i<root;i++) if(!vis[i])
      if(check[i][l][root-1]+ori[root]==val){
        vis[i]=1; pre(i,l,root-1);
        break;
      }
  }else{
    for(int i=l;i<root;i++) for(int j=root+1;j<=r;j++) if(!vis[i] && !vis[j])
      if(check[i][l][root-1]*check[j][root+1][r]+ori[root]==val){
        vis[i]=vis[j]=1;
        pre(i,l,root-1);
        pre(j,root+1,r);
        break;
      }
  }
}
*/
