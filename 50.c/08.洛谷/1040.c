/*
题目描述
设一个n个节点的二叉树tree的中序遍历为（1,2,3,…,n），其中数字1,2,3,…,n为节点编号。每个节点都有一个分数（均为正整数），记第i个节点的分数为di，tree及它的每个子树都有一个加分，任一棵子树subtree（也包含tree本身）的加分计算方法如下：
subtree的左子树的加分 * subtree的右子树的加分 + subtree的根的分数。
若某个子树为空，规定其加分为1，叶子的加分就是叶节点本身的分数。不考虑它的空子树。
试求一棵符合中序遍历为（1,2,3,…,n）且加分最高的二叉树tree。要求输出；
（1）tree的最高加分
（2）tree的前序遍历

输入输出格式
输入格式：
第1行：一个整数n（n<30），为节点个数。
第2行：n个用空格隔开的整数，为每个节点的分数（分数<100）。

输出格式：
第1行：一个整数，为最高加分（结果不会超过4,000,000,000）。
第2行：n个用空格隔开的整数，为该树的前序遍历。

输入输出样例
输入样例#1：
5
5 7 1 2 10

输出样例#1：
145
3 1 2 4 5
*/

/*
  解题报告：
    由于中序遍历为1:n，可以转换为区间DP，主要是root[l][r]函数，其他没什么，毕竟已经做过了。
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

typedef long long unsigned LLU;
const int MAX=40;
int w[MAX],n;
LLU check[MAX][MAX];
int root[MAX][MAX];

LLU f(int l, int r){
  LLU & a=check[l][r];
  if(a!=-1) return a;
  if(l>r) a=1;
  else if(l==r) {a=w[l]; root[l][r]=l;}
  else{
    a=0;
    FORR(i,l,r){
      LLU t=f(l,i-1)*f(i+1,r)+w[i];
      if(t>a) a=t,root[l][r]=i;
    }
  }
  return a;
}
void print(int l, int r){
  if(l>r) return;
  printf("%d ",root[l][r]);
  print(l,root[l][r]-1);
  print(root[l][r]+1,r);
}

int main(void){
  scanf("%d",&n);
  FORR(i,1,n) scanf("%d",&w[i]);

  MST(check,-1);
  printf("%llu\n",f(1,n));
  print(1,n); putchar('\n');

  return 0;
}
