/*
烽火传递
烽火台又称烽燧，是重要的防御设施，一般建在险要处或交通要道上。一旦有敌情发生，白天燃烧柴草，通过浓烟表达信息：夜晚燃烧干柴，以火光传递军情。在某两座城市之间有n个烽火台，每个烽火台发出信号都有一定的代价。为了使情报准确的传递，在m个烽火台中至少要有一个发出信号。现输入n、m和每个烽火台发出的信号的代价，请计算总共最少需要话费多少代价，才能使敌军来袭之时，情报能在这两座城市之间准确的传递。
例如：有5个烽火台，它们发出信号的代价依次为1、2、5、6、2，且m为3，则总共最少花费的代价为4，即由第2个和第5个烽火台发出信号。
*/

/*
  解题报告：
    动规，令 f(i) 为将信息从起点传到i，且i点发出信号的最小代价，则
      f(i) = min{ f(j) | i-m+1<=j<i } + value[i]
    而题目中使用堆将min{f(j)}替代为heap[1]，那么转换方程即为
      f(i) = heap[1] + value[i]，且转换后要删除heap中的一个元素
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int 
n,m,r,value[SIZE],heap[SIZE],
  pos[SIZE],home[SIZE],opt[SIZE];
//heap[i]表示用顺序存储的堆heap中第i个元素的值
//pos[i]表示opt[i]在堆heap中的位置。即heap[pos[i]]=opt[i]
//home[i]表示heap[i]在序列opt中的位置，即opt[home[i]] == heap[i] 

void swap(int i,int j){
  //交换堆的第i个元素和第j元素 
  int tmp;
  pos[home[i]] = j;
  pos[home[j]] = i;
  tmp = heap[i];
  heap[i] = heap[j];
  heap[j] = tmp;
  tmp = home[i];
  home[i] = home[j];
  home[j] = tmp;
}
void add(int k){ 
  //在堆中插入opt[k] 
  int i;
  r++;
  heap[r]=opt[k];
  pos[k]=r;
  home[r]=k;
  i=r;
  while(i>1 && heap[i]<heap[i/2]){
    swap(i,i/2); i /= 2;
  }
}
void remove(int k){
  int i,j;
  i=pos[k];
  swap(i,r);
  r--;
  if(i == r+1) return 
  while((i > 1) && (heap[i]<heap[i/2])){
    swap(i,i/2); i /= 2;
  }
  while(i + i <= r){
    if((i + i + 1 <=r) && (heap[i + i +1] < heap[i + i]))
      j=i+i+1;
    else
      j=i+i;
    if(heap[i] > heap[j]){
      swap(i,j);
      i=j; 
    }
    else break;
  }
}

int main(void){  
  int i;

  scanf("%d %d",&n,&m);
  for(i = 1;i <= n;i ++) scanf("%d",&value[i]);
  r = 0;
  for(i = 1;i <= m;i ++){
    opt[i] = value[i];
    add(i);
  }
  for(i = m+1;i <= n;i++){
    opt[i]=heap[1]+value[i];
    remove(i-m);  //<b>确保heap中只有[i-m+1,i)的元素</b>
    add(i);
  }
  printf("%d\n",heap[1]);
  system("pause");
  return 0;
}
