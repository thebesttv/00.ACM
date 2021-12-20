/*
描述
一棵树的镜面映射指的是对于树中的每个结点，都将其子结点反序。例如，对左边的树，镜面映射后变成右边这棵树。

   a            a
 / | \        / | \
b  c  f  =>  f  c  b
  / \          / \
 d   e        e   d

我们在输入输出一棵树的时候，常常会把树转换成对应的二叉树，而且对该二叉树中只有单个子结点的分支结点补充一个虚子结点“$”，形成“伪满二叉树”。
例如，对下图左边的树，得到下图右边的伪满二叉树

    a             a
  / | \          / \
 b  c  f  =>    b   $
   / \         / \
  d   e       $   c                          
                 / \
                d   f
               / \
              $   e

然后对这棵二叉树进行前序遍历，如果是内部结点则标记为0，如果是叶结点则标记为1，而且虚结点也输出。
现在我们将一棵树以“伪满二叉树”的形式输入，要求输出这棵树的镜面映射的宽度优先遍历序列。

输入
输入包含一棵树所形成的“伪满二叉树”的前序遍历。
第一行包含一个整数，表示结点的数目。
第二行包含所有结点。每个结点用两个字符表示，第一个字符表示结点的编号，第二个字符表示该结点为内部结点还是外部结点，内部结点为0，外部结点为1。结点之间用一个空格隔开。
数据保证所有结点的编号都为一个小写字母。

输出
输出包含这棵树的镜面映射的宽度优先遍历序列，只需要输出每个结点的编号，编号之间用一个空格隔开。

样例输入
9
a0 b0 $1 c0 d0 $1 e1 f1 $1

样例输出
a f c b e d
*/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct Node{
  char c;
  int lev;
  Node *leftMostChild, *rightSibling;
} *q[100];

Node * read(int lev){
  Node *root = new Node;
  root->leftMostChild=NULL; root->rightSibling=NULL;
  char temp[4];
  scanf("%s",temp);
  if(temp[0]=='$') return NULL;
  root->c=temp[0]; root->lev=lev;
  if(temp[1]=='0'){
    root->leftMostChild = read(lev+1);
    root->rightSibling = read(lev);
  }
  return root;
}

int main(void){
  int n; scanf("%d",&n);
  Node *root = read(0);
#ifdef DEBUG
  printf("  read successful\n");
#endif
  int head=0, tail=0;
  while(root!=NULL){
    q[tail++]=root;
    root=root->rightSibling;
  }
  while(head<tail){
    Node *p=q[head++];
    p=p->leftMostChild;
    while(p!=NULL){
      q[tail++]=p;
      p=p->rightSibling;
    }
  }
#ifdef DEBUG
  printf("  bfs successful\n");
#endif
  bool flag=0;
  for(int i=0;i<tail;i++){
    int j=i;
    while(j+1<tail && q[j+1]->lev==q[i]->lev) j++;
    for(int k=j;k>=i;k--){
      if(flag) printf(" ");
      else flag=1;
      printf("%c",q[k]->c);
    }
    i=j;
  }
  printf("\n");

  return 0;
}
