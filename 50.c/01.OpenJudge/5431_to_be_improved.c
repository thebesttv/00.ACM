/*
描述
二叉搜索树在动态查表中有特别的用处，一个无序序列可以通过构造一棵二叉搜索树变成一个有序序列，构造树的过程即为对无序序列进行排序的过程。每次插入的新的结点都是二叉搜索树上新的叶子结点，在进行插入操作时，不必移动其它结点，只需改动某个结点的指针，由空变为非空即可。
这里，我们想探究二叉树的建立和序列输出。

输入
只有一行，包含若干个数字，中间用空格隔开。（数字可能会有重复）

输出
输出一行，对输入数字建立二叉搜索树后进行前序周游的结果。
*/

#include<iostream>
#include<cstdio>
using namespace std;

class Node{
public:
	int n;
	Node *left,*right;

} *root = new Node;
bool flag=0;

void insert(int n);
Node * find(int n, Node * root);
void front(Node * p);
void Delete(Node * p);

int main(void){
	int t;
	scanf("%d",&(root->n));
	while(scanf("%d",&t)==1) insert(t);
	front(root); printf("\n");
	Delete(root);

	return 0;
}

void insert(int n){
	Node *p=find(n,root);
	if(!p) return;
	#ifdef DEBUG
	printf("  insert %d under %d\n",n,p->n);
	if(root->left && root->right)
		printf("  root: n=%d, left=%d, right=%d\n",root->n,root->left->n,root->right->n);
	else if(root->left)
		printf("  root: n=%d, left=%d\n",root->n,root->left->n);
	else if(root->right)
		printf("  root: n=%d, right=%d\n",root->n,root->right->n);
	else printf("  root: n=%d\n",n);
	#endif
	if(n < p->n){
		p->left = new Node;
		p->left->n = n;
	}else{
		p->right = new Node;
		p->right->n = n;
	}
}
Node * find(int n, Node * root){
	Node * p = root;
	#ifdef DEBUG
	printf("  find: %d\n",n);
	#endif
	while(p && (p->left || p->right)){
		if(n == p->n) return NULL;
		if(n < p->n){
			if(p->left) p=p->left;
			else break;
		}else{
			if(p->right) p=p->right;
			else break;
		}
	}
	return p;
}
void front(Node * p){
	if(!p) return;
	if(flag) printf(" ");
	else flag=1;
	printf("%d",p->n);
	front(p->left); front(p->right);
}
void Delete(Node * p){
	if(!p) return;
	Delete(p->left); Delete(p->right);
	delete p;
}
