#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;

class MinHeap{
//private:
public:
	int * heapArray;	//存放堆数据的数组
	int CurrentSize;	//当前堆中元素数目
	int MaxSize;		//堆所能容纳的最大元素数目
	void BuildHeap();	//建立堆，即将无序数组变为堆
public:
	MinHeap(const int n){					//构造函数，n为最大元素数目
		this->heapArray=new int[n];
		this->CurrentSize=0; this->MaxSize=n;
	}
	MinHeap();
	~MinHeap(){delete []heapArray;}			//析构函数
	bool isLeaf(int pos) const;				//判断是否为叶节点
	int leftchild(int pos) const;			//返回左孩子位置，如果没有，返回-1
	int rightchild(int pos) const;			//返回右孩子位置，如果没有，返回-1
	int parent(int pos) const;				//返回父节点位置，如果是根节点，返回-1
	bool Remove(int pos, int & node);		//删除给定下表的元素，并将node赋为被删除的值
	bool Insert(const int & newNode);		//插入新元素newNode
	int & RemoveMin();						//
	void SiftUp(int pos);					//向上调整
	void SiftDown(int left);				//向下调整
};

MinHeap mh(1<<20);

int main(void){
	int n; scanf("%d",&n);
//	mh.CurrentSize=n;
//	for(int i=0;i<n;i++) scanf("%d",&mh.heapArray[i]);
//	mh.BuildHeap();
	int a;
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(!mh.Insert(a)) printf("  %d not inserted\n",a);
	}
	for(int i=0;i<n;i++){
		mh.Remove(0,a);
		printf("%d\n",a);
	}

	return 0;
}

void MinHeap::BuildHeap(){
	for(int i=CurrentSize/2-1;i>=0;i--) SiftDown(i);
}
bool MinHeap::isLeaf(int pos) const{
	return pos>=CurrentSize/2;
}
int MinHeap::leftchild(int pos) const{
	return pos*2+1 < CurrentSize ? pos*2+1 : -1;
}
int MinHeap::rightchild(int pos) const{
	return pos*2+2 < CurrentSize ? pos*2+2 : -1;
}
int MinHeap::parent(int pos) const{
	return (pos-1)/2>=0 ? (pos-1)/2 : -1;
}
bool MinHeap::Remove(int pos, int & node){
	if(pos<0 || pos>=CurrentSize) return false;
	node=heapArray[pos];
	heapArray[pos]=heapArray[--CurrentSize];
	int parent=(pos-1)/2;
	if(parent>=0 && heapArray[parent]>heapArray[pos]) SiftUp(pos);
	else SiftDown(pos);
	return true;
}
bool MinHeap::Insert(const int & newNode){
	if(CurrentSize==MaxSize) return false;
	heapArray[CurrentSize++]=newNode;
	SiftUp(CurrentSize-1);
	return true;
}
void MinHeap::SiftUp(int pos){
/*	int temp=heapArray[pos];
	int i=pos,j=(i-1)/2;
	while(j>=0){
		if(heapArray[j]<=temp) break;
		heapArray[i]=heapArray[j];	//<b>父节点被子节点覆盖</b>
		i=j; j=(i-1)/2;
	}
	heapArray[i]=temp;
*/
	int i=pos;
	int temp=heapArray[pos];
	while(i>0 && heapArray[parent(i)]>temp){
		heapArray[i]=heapArray[parent(i)];
		i=parent(i);
	}

}
void MinHeap::SiftDown(int pos){
	int temp=heapArray[pos];
	int i=pos, j=i*2+1;
	while(j<CurrentSize){
		if(j+1<CurrentSize && heapArray[j+1]<heapArray[j]) j++;
		if(temp<=heapArray[j]) break;
		heapArray[i]=heapArray[j];	//<b></b>
		i=j; j=i*2+1;
	}
	heapArray[i]=temp;
}
