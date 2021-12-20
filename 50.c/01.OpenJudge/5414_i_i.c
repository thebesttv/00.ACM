/*
描述
我们知道如何按照三种深度优先次序来周游一棵二叉树，来得到中根序列、前根序列和后根序列。反过来，如果给定二叉树的中根序列和后根序列，或者给定中根序列和前根序列，可以重建一二叉树。本题输入一棵二叉树的中根序列和后根序列，要求在内存中重建二叉树，最后输出这棵二叉树的前根序列。

用不同的整数来唯一标识二叉树的每一个结点，下面的二叉树
   5
  / \
 9  67
   /
  32

中根序列是9 5 32 67

后根序列9 32 67 5

前根序列5 9 67 32

输入
两行。第一行是二叉树的中根序列，第二行是后根序列。每个数字表示的结点之间用空格隔开。结点数字范围0～65535。暂不必考虑不合理的输入数据。
输出
一行。由输入中的中根序列和后根序列重建的二叉树的前根序列。每个数字表示的结点之间用空格隔开。
*/

#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=65560;
int In[MAX],Post[MAX];
bool book[MAX],flag=0;
struct Node{
  int n;
  Node *left, *right;
};

Node * build_tree(int L1, int R1, int L2, int R2){
  if(L1>R1 || L2>R2) return NULL;
  Node * root = new Node;
  root->n = Post[R2];
  int pos=L1;
  while(In[pos]!=Post[R2]) pos++;
  int cnt=pos-L1;
  root->left = build_tree(L1,L1+cnt-1,L2,L2+cnt-1);
  root->right = build_tree(L1+cnt+1,R1,L2+cnt,R2-1);
  return root;
}

void pre_order(Node * root){
  if(root==NULL) return;
  if(flag) printf(" ");
  else flag=1;
  printf("%d",root->n);
  pre_order(root->left);
  pre_order(root->right);
}

int main(void){
  int t,tot=0;
  while(scanf("%d",&t)==1){
    if(!book[t]) book[t]=1;
    else {Post[0]=t; break;}
    In[tot++]=t;
  }
  for(int i=1;i<tot;i++) scanf("%d",&Post[i]);
  Node * root = build_tree(0,tot-1,0,tot-1);
  pre_order(root);
  printf("\n");

  return 0;
}
