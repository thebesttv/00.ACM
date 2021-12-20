#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;

const int MAX=10;
int a[MAX+10];
class minHeap{
  private:
    int * h;  //范围：h[1:heapsize]
    int heapsize;
    int maxSize;
  public:
    minHeap(int maxSize_): maxSize(maxSize_) {
      h = new int[maxSize_]; heapsize=0;
    }
    ~minHeap() {delete [] h;}
    void siftUp(int i);
    void siftDown(int i);
    bool insert(int n);
    int top() {return h[1];}
    bool pop();
    void makeHeap(int * a, int n);
}hp(MAX);


int main(void){
  srand(time(NULL));
  for(int i=0;i<MAX;i++) a[i]=rand()%1000;
  for(int i=0;i<MAX;i++) printf("%d ",a[i]); printf("\n");
  hp.makeHeap(a,MAX);
  for(int i=0;i<MAX;i++){
    printf("%d ",hp.top()); hp.pop();
  }
  printf("\n");

  return 0;
}

void minHeap::siftUp(int i){  //全都是i被赋值，k来比较
  int j=i>>1, k=h[i];
  while(j && k<h[j]){
    h[i]=h[j]; i=j; j>>=1;
  }
  h[i]=k;
}
void minHeap::siftDown(int i){
  int j=i<<1,k=h[i];
  while(j<=heapsize){
    if(j+1<=heapsize && h[j+1]<h[j]) j++;
    if(h[j]>k) break;
    h[i]=h[j]; i=j; j<<=1;
  }
  h[i]=k;
}
bool minHeap::pop(){
  if(!heapsize) return false;
  h[1]=h[heapsize--];
  siftDown(1);
  return true;
}
bool minHeap::insert(int n){
  if(heapsize==maxSize) return false;
  h[++heapsize]=n;
  siftUp(heapsize);
}
void minHeap::makeHeap(int * a, int n){
  memset(h,0,sizeof(int)*maxSize);
  memcpy(h+1,a,sizeof(int)*n);
  heapsize=n;
  for(int i=(n>>1);i>=1;i--) siftDown(i);
}
