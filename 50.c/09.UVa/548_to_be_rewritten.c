#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

class Node{
public:
	int n;
	Node *left, *right;

	~Node() {delete this;}
	bool isLeaf(){
		return (left==NULL && right==NULL);
	}
};
const int MAX=10020;
int In[MAX],Post[MAX];
int minSum,minU;
bool book[MAX];

void dfs(Node * root, int sum);
Node * build_tree(int L1, int R1, int L2, int R2);

int main(void){
	#ifdef LOCAL
	freopen("out","w",stdout);
	#endif
	int t;
	while(scanf("%d",&t)==1){
		memset(book,0,sizeof(book)); minSum=1<<30;
		int tot=1; In[0]=t; book[t]=1;
		while(1){
			scanf("%d",&t);
			if(!book[t]) book[t]=1;
			else {Post[0]=t; break;}
			In[tot++]=t;
		}
		for(int i=1;i<tot;i++) scanf("%d",&Post[i]);
		#ifdef DEBUG
		printf("  tot: %d\n",tot);
		printf(" "); for(int i=0;i<tot;i++) printf(" %d",In[i]); printf("\n");
		printf(" "); for(int i=0;i<tot;i++) printf(" %d",Post[i]); printf("\n");
		#endif

		Node * root = build_tree(0,tot-1,0,tot-1);
		dfs(root,root->n);
		printf("%d\n",minU);
	}

	return 0;
}

void dfs(Node * root, int sum){
	if(sum>minSum) return;
	if(root->isLeaf()){
		if(sum<minSum) {minSum=sum; minU=root->n;}
		else if(sum==minSum && root->n<minU) minU=root->n;
		return;
	}
	if(root->left) dfs(root->left,sum+root->left->n);
	if(root->right) dfs(root->right,sum+root->right->n);
}
Node * build_tree(int L1, int R1, int L2, int R2){
	if(L1>R1 || L2>R2) return NULL;
	Node * root = new Node;
	root->n = Post[R2];
	int pos; for(pos=L1; In[pos]!=root->n && pos<=R1; pos++);
	int cou=pos-L1;
	//if(pos==L1) return NULL;
	#ifdef DEBUG
	printf("  in build_tree(%d,%d,%d,%d)\n",L1,R1,L2,R2);
	printf("    go into left: (%d,%d,%d,%d)\n",L1,L1+cou-1,L2,L2+cou-1);
	printf("    go into right: (%d,%d,%d,%d)\n",L1+cou+1,R1,L2+cou,R2-1);
	#endif
	root->left = build_tree(L1,L1+cou-1,L2,L2+cou-1);
	root->right = build_tree(L1+cou+1,R1,L2+cou,R2-1);
	return root;
}
