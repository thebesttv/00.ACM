/*
描述
构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：
  Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)
  Wi:每个节点的权值。
  Li:根节点到第i个外部叶子节点的距离。
编程计算最小外部路径长度总和。

输入
第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。
2<=N<=100

输出
输出最小外部路径长度总和。
*/

//to be improved
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

class HTN{
public:
	int weight;
	HTN *left,*right;

	bool operator < (const HTN & b) const {
		return weight > b.weight;
	}
}node[110],temp;
priority_queue<HTN> pq;
int sum=0;

HTN * HuffmanTreeCreate();
void dfs(HTN * root, int step);

int main(void){
	int n,t; scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		temp.weight=t; pq.push(temp);
	}
	HTN * root;
	root = HuffmanTreeCreate();
	dfs(root,0);
	printf("%d\n",sum);
	return 0;
}

HTN * HuffmanTreeCreate(){
	while(1){
		HTN *L = new HTN, *R = new HTN;
		*L=pq.top(); pq.pop();
		*R=pq.top(); pq.pop();
		int tot=L->weight + R->weight;
		HTN * parent = new HTN;
		parent->weight=tot; parent->left=L; parent->right=R;
		if(pq.empty()) return parent;
		pq.push(*parent);
	}
}
void dfs(HTN * root, int step){
	#ifdef DEBUG
	printf("  dfs: in %d, weight = %d\n",step,root->weight);
	#endif
	if(root->left==NULL && root->right==NULL){
		#ifdef DEBUG
		printf("    sum += %d * %d\n",step,root->weight);
		#endif
		sum+=step*(root->weight); return;
	}
	if(root->left) dfs(root->left,step+1);
	if(root->right) dfs(root->right,step+1);
}
