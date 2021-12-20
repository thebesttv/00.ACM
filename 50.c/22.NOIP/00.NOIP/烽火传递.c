#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
int n,m,r,value[SIZE],heap[SIZE];
int pos[SIZE],home[SIZE],opt[SIZE];
//heap[i] 表示用顺序存储的堆 heap 中第 i 个元素的值
//pos[i] 表示 opt[i] 在堆 heap 中的位置。即 heap[pos[i]]=opt[i]
//home[i] 表示 heap[i] 在序列 opt 中的位置，即 opt[home[i]] == heap[i]
void swap(int i,int j) {//交换堆的第 i 个元素和第 j 元素
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
void add(int k) {
//在堆中插入opt[k]
  int i;
  r++;
  heap[r] = opt[k];
  pos[k] = r;
  home[r]=k;
  i=r;
  while((i > 1)&&(heap[i] <heap[i/2])) {
    swap(i,i/2);
    i /= 2;
  }
}
void remove(int k) {
  int i,j;
  i=pos[k];
  swap(i,r);
  r --;
  if(i == r+1)
    return ;
  while((i > 1) && (heap[i]<heap[i/2])) {
    swap(i,i/2);
    i /= 2;
  }
  while(i + i <= r) {
    if((i + i + 1 <=r) && (heap[i + i +1] < heap[i + i]))
      j = i + i + 1;
    else
      j=i+i;
    if(heap[i] > heap[j]) {
      swap(i,j);
      i = j;
    } else
      break;
  }
}
int main(void) {
  int i;
  scanf("%d %d",&n,&m);
  for(i = 1; i <= n; i ++)
    scanf("%d",&value[i]);
  r = 0;
  for(i = 1; i <= m; i ++) {
    opt[i] = value[i];
    add(i);
  }
  for(i = m+1; i <= n; i++) {
    opt[i]=heap[1]+value[i];
    remove(i-m);
    add(i);
  }
  printf("%d\n",heap[1]);
  return 0;
}
