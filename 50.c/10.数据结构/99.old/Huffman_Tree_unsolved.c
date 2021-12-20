#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

class HuffmanTreeNode;
class HuffmanTree;
typedef HuffmanTreeNode* HuffmanTreeNodePtr;

class HuffmanTreeNode{
private:
	char character;
	int frequency;
	HuffmanTreeNodePtr left,right;
public:
	HuffmanTreeNode();
	HuffmanTreeNode(char InCharacter, int InFrequency, HuffmanTreeNodePtr InLeft, HuffmanTreeNodePtr InRight);
	HuffmanTreeNode(HuffmanTreeNode & InHuffmanTreeNode);
	~HuffmanTreeNode();

	inline char GetCharacter();
	inline int GetFrequency();
	inline HuffmanTreeNodePtr GetLeft();
	inline HuffmanTreeNodePtr GetRight();
	inline void SetCharacter(char InNewCharacter);
	inline void SetFrequency(int InNewFrequency);
	inline void SetLeft(HuffmanTreeNodePtr InNewNode);
	inline void SetRight(HuffmanTreeNodePtr InNewNode);
	inline void IncreaseFrequency();
	inline bool IsLeaf();

	bool operator < (const HuffmanTreeNode & b) const {
//		return GetFrequency() > b.GetFrequency();
		return frequency > b.frequency;
	}
};

class HuffmanTree{
private:
	HuffmanTreeNodePtr root;
	void ClearTree(HuffmanTreeNodePtr InRoot);
	HuffmanTreeNodePtr CopyTree(HuffmanTreeNodePtr InRoot);
	HuffmanTreeNodePtr MergeTwoNodes(HuffmanTreeNodePtr InNode1, HuffmanTreeNodePtr InNode2);
public:
	HuffmanTree(priority_queue<HuffmanTreeNode> & InPqOfNodes);
	HuffmanTree(HuffmanTree & InHuffmanTreeToCopy);
	~HuffmanTree();

	void PrintCode();
	void EnCode(char * InInput, int InLenOfInput, char * InOutput, int & InLenOfOutput);
	void DeCode(char * InInput, int InLefOfInput, char * InOutput, int & InLenOfOutput);
	void EnCodeAndPrint(char * InInput, int InLenOfInput, char * InOutput, int & InLenOfOutput);
	void DeCodeAndPrint(char * InInput, int InLefOfInput, char * InOutput, int & InLenOfOutput);
};


//for class HuffmanTreeNode
HuffmanTreeNode::HuffmanTreeNode(char InCharacter, int InFrequency, HuffmanTreeNodePtr InLeft, HuffmanTreeNodePtr InRight){
	SetCharacter(InCharacter);
	SetFrequency(InFrequency);
	SetLeft(InLeft); SetRight(InRight);
}
HuffmanTreeNode::HuffmanTreeNode(HuffmanTreeNode & InHuffmanTreeNode){
	SetCharacter(InHuffmanTreeNode.GetCharacter());
	SetFrequency(InHuffmanTreeNode.GetFrequency());
	SetLeft(InHuffmanTreeNode.GetLeft()); SetRight(InHuffmanTreeNode.GetRight());
}
inline char HuffmanTreeNode::GetCharacter(){
	return character;
}
inline int HuffmanTreeNode::GetFrequency(){
	return frequency;
}
inline HuffmanTreeNodePtr HuffmanTreeNode::GetLeft(){
	return left;
}
inline HuffmanTreeNodePtr HuffmanTreeNode::GetRight(){
	return right;
}
inline void HuffmanTreeNode::SetCharacter(char InNewCharacter){
	character = InNewCharacter;
}
inline void HuffmanTreeNode::SetFrequency(int InNewFrequency){
	frequency = InNewFrequency;
}
inline void HuffmanTreeNode::SetLeft(HuffmanTreeNodePtr InNewNode){
	left = InNewNode;
}
inline void HuffmanTreeNode::SetRight(HuffmanTreeNodePtr InNewNode){
	right = InNewNode;
}
inline void HuffmanTreeNode::IncreaseFrequency(){
	frequency++;
}
inline bool HuffmanTreeNode::IsLeaf(){
	return (left == NULL && right == NULL);
}

//for class HuffmanTree
//private
void HuffmanTree::ClearTree(HuffmanTreeNodePtr InRoot){
	//recursively clear HuffmanTree
	//must use delete to release memory
	if(InRoot->IsLeaf()) {delete InRoot; return;}
	if(InRoot->GetLeft()) ClearTree(InRoot->GetLeft());
	if(InRoot->GetRight()) ClearTree(InRoot->GetRight());
	delete InRoot; return;
}
HuffmanTreeNodePtr HuffmanTree::CopyTree(HuffmanTreeNodePtr InRoot){
	HuffmanTreeNodePtr a = new HuffmanTreeNode;
	if(InRoot->IsLeaf()) {*a = *InRoot; return a;}
	a->SetCharacter(InRoot->GetCharacter());
	a->SetFrequency(InRoot->GetFrequency());
	if(InRoot->GetLeft()) a->SetLeft(CopyTree(InRoot->GetLeft()));
	if(InRoot->GetRight()) a->SetRight(CopyTree(InRoot->GetRight()));
	return a;
}
HuffmanTreeNodePtr HuffmanTree::MergeTwoNodes(HuffmanTreeNodePtr InNode1, HuffmanTreeNodePtr InNode2){
	HuffmanTreeNodePtr root = new HuffmanTreeNode;
	root->SetFrequency(InNode1->GetFrequency() + InNode2->GetFrequency());
	if(InNode1->GetFrequency() < InNode2->GetFrequency()){	//the comparing is not necessary, just for a good look XD
		root->SetLeft(InNode1); root->SetRight(InNode2);
	}else{
		root->SetLeft(InNode2); root->SetRight(InNode1);
	}
	return root;
}

//public
HuffmanTree::HuffmanTree(priority_queue<HuffmanTreeNode> & InPqOfNodes){
	HuffmanTreeNodePtr root;
	while(1){
		HuffmanTreeNode first = InPqOfNodes.top(); InPqOfNodes.pop();
		HuffmanTreeNode second = InPqOfNodes.top(); InPqOfNodes.pop();
		root = HuffmanTree::MergeTwoNodes(first, second);
		if(InPqOfNodes.empty()) break;
		InPqOfNodes.push(*root);
	}
	return root;
}
HuffmanTree::HuffmanTree(HuffmanTree & InHuffmanTreeToCopy){
	return HuffmanTree::CopyTree(InHuffmanTreeToCopy.root);
}

void PrintCode();
void EnCode(char * InInput, int InLenOfInput, char * InOutput, int & InLenOfOutput);
void DeCode(char * InInput, int InLefOfInput, char * InOutput, int & InLenOfOutput);
void EnCodeAndPrint(char * InInput, int InLenOfInput, char * InOutput, int & InLenOfOutput);
void DeCodeAndPrint(char * InInput, int InLefOfInput, char * InOutput, int & InLenOfOutput);











































/*
template <class T>
class HuffmanTreeNode<T>{
private:
	int weight;	//权值
	T element;
	HuffmanTreeNode<T> *leftchild, *rightchild;
};

template <class T>
class HuffmanTree{
private:
	HuffmanTreeNode<T> * root;	//树根
	void MergeTree(HuffmanTreeNode<T> & ht1, HuffmanTreeNode<T> & ht2, HuffmanTreeNode<T> * parent);
		//将ht1和ht2合并成一颗以parent为根的Huffman子树
		//1.修改parent的weight
public:
	HuffmanTree(T weight[], int n);				//构造函数，weight是储存权值的数组，n为数组长度
	virtual ~HuffmanTree(){DeleteTree(root);}	//析构函数
};

template <class T>
HuffmanTree<T>::HuffmanTree(T weight[], int n){	//构造函数
	MinHeap<HuffmanTreeNode<T> > heap;	//定义最小堆
	HuffmanTreeNode<T> *parent, &leftchild, &rightchild;
	HuffmanTreeNode<T> * NodeList = new HuffmanTreeNode<T>[n];	//暂时存储
	for(int i=0;i<n;i++){
		NodeList[i].weight=weight[i];
		NodeList[i].parent = NodeList[i].left = NodeList[i].right=NULL;
		heap.Insert(NodeList[i]);	//向堆中添加元素
	}
	
	for(int i=0;i<n-1;i++){	//通过<b>n-1</b>次合并建立Huffman树
		parent = new HuffmanTreeNode<T>;	//新建一个Huffman树的子节点，由此建立一个根为parent的Huffman子树
		firstchild = heap.RemoveMin();	//选择两个权值最小的节点
		secondchild = heap.RemoveMin();
		MergeTree(firstchild, secondchild, parent);	//合并权值最小的两颗树，由此生成根为parent的Huffman子树
		heap.Insert(*parent);	//将parent插入堆
		this->root = parent;	//建立根节点
								//<b>为parent新开辟的空间作为子树的树根，不能释放</b>
	}
	delete []NodeList;
}
*/
