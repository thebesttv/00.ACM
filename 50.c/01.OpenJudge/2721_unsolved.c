/*
描述

    A
  /   \
 B     D
  \   /
   C E
      \
       F

如上图，一棵每个节点都是一个字母，且字母互不相同的二叉树，可以用以下若干行文本表示:

A
-B
--*
--C
-D
--E
---*
---F

在这若干行文本中：
1) 每个字母代表一个节点。该字母在文本中是第几行，就称该节点的行号是几。根在第1行
2) 每个字母左边的'-'字符的个数代表该结点在树中的层次（树根位于第0层）
3) 若某第 i 层的非根节点在文本中位于第n行，则其父节点必然是第 i-1 层的节点中，行号小于n,且行号与n的差最小的那个
4) 若某文本中位于第n行的节点(层次是i) 有两个子节点，则第n+1行就是其左子节点，右子节点是n+1行以下第一个层次为i+1的节点
5) 若某第 i 层的节点在文本中位于第n行，且其没有左子节点而有右子节点，那么它的下一行就是 i+1个'-' 字符再加上一个 '*' 


给出一棵树的文本表示法，要求输出该数的前序、后序、中序遍历结果

输入
第一行是树的数目 n
接下来是n棵树，每棵树以'0'结尾。'0'不是树的一部分
每棵树不超过100个节点

输出
对每棵树，分三行先后输出其前序、后序、中序遍历结果
两棵树之间以空行分隔
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

struct Node{
	char c;
	Node *left, *right, *parent;
}*p,ind[120];
char temp[1000][200];
int level[1000], tail=0, tot=0;

int getLevel(char * str);
void Pre(Node * a);
void Mid(Node * a);
void Fin(Node * a);
void Insert(Node * p, int n);

int main(void){
	#ifdef LOCAL
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int T; scanf("%d",&T);
	for(int kase=0;kase<T;kase++){
		tail=0; tot=0; memset(temp,0,sizeof(temp)); memset(level,0,sizeof(level)); memset(ind,0,sizeof(ind));
		while(scanf("%s",temp[tail])==1){
			if(temp[tail][0]=='0') break;
			tail++;
		}
		for(int i=0;i<tail;i++) level[i]=getLevel(temp[i]);
		#ifdef DEBUG
		printf("total: %d\n",tail);
		for(int i=0;i<tail;i++) printf("  %d %s\n",level[i],temp[i]);
		#endif

		tot=tail; tail=0;
		p=&ind[tail++]; p->c=temp[0][level[0]];
		Insert(p,0);
		#ifdef DEBUG
		for(int i=0;i<tail;i++) printf("  ind[%d]: %c, left: %d, right: %d\n",
									i,ind[i].c,ind[i].left-ind, ind[i].right-ind);
		#endif

		if(kase) printf("\n");
		Pre(p); printf("\n");
		Fin(p); printf("\n");
		Mid(p); printf("\n");
	}

	return 0;
}

void Insert(Node * p, int n){
	bool Left=0,Right=0;
	if(level[n]>=level[n+1]) return;	//<b>n为叶节点时</b>
	for(int i=n+1;i<tot;i++){
		if(Left && Right) return;
//		if(level[n]+1<level[i]) return;
		if(temp[i][0]==0 || level[n]+1!=level[i]) continue;
		char c=temp[i][level[i]];
		if(c=='*') {Left=1; continue;}
		if(!Left){
			p->left=&ind[tail++];
			p->left->c=c; Left=1;
			Insert(p->left,i);
		}else{
			p->right=&ind[tail++];
			p->right->c=c; Right=1;
			Insert(p->right,i);
		}
		memset(temp[i],0,sizeof(temp[i]));
	}
}
int getLevel(char * str){
	int level=0;
	for(level=0;str[level]=='-';level++);
	return level;
}
void Pre(Node * a){
	if(!a) return;
	printf("%c",a->c);
	Pre(a->left);
	Pre(a->right);
}
void Mid(Node * a){
	if(!a) return;
	Mid(a->left);
	printf("%c",a->c);
	Mid(a->right);
}
void Fin(Node * a){
	if(!a) return;
	Fin(a->left);
	Fin(a->right);
	printf("%c",a->c);
}
