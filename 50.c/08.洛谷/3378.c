/*
题目描述
如题，初始小根堆为空，我们需要支持以下3种操作：
操作1： 1 x 表示将x插入到堆中
操作2： 2 输出该小根堆内的最小数
操作3： 3 删除该小根堆内的最小数

输入输出格式
输入格式：
第一行包含一个整数N，表示操作的个数
接下来N行，每行包含1个或2个正整数，表示三种操作，格式如下：
操作1： 1 x
操作2： 2
操作3： 3

输出格式：
包含若干行正整数，每行依次对应一个操作2的结果。

输入输出样例
输入样例#1：
5
1 2
1 5
2
3
2

输出样例#1：
2
5

说明
时空限制：1000ms,128M

数据规模：
对于30%的数据：N<=15
对于70%的数据：N<=10000
对于100%的数据：N<=1000000（注意是6个0。。。不过不要害怕，经过编者实测，堆是可以AC的）
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORR(i,a,b) for(int i=(a);i<=(b);++i)
#define ROR(i,a,b) for(int i=(a);i>=(b);--i)
#define RORR(i,a,b) for(int i=(a);i>(b);--i)
#define PQ priority_queue
#define VR vector
#define MST(a,b) memset(a,b,sizeof(a))
#define SIZ(a) sizeof(a)
#define CE() clear()
#define FGETS(s) fgets(s,sizeof(s),stdin)

const int MAX=1000020;
int a[MAX],tail=1;

void pushUp(int i){ //全都是i被赋值，k来比较 
  int k=a[i],j=i>>1;
  while(j && k<a[j]){
    a[i]=a[j]; i=j; j>>=1;
  }
  a[i]=k;
}
void pushDown(int i){
  int k=a[i],j=i<<1;
  while(j<tail){
    if(j+1<tail && a[j+1]<a[j]) j++;
    if(a[j]>k) break;
    a[i]=a[j]; i=j; j<<=1;
  }
  a[i]=k;
}
void insert(int n){
  a[tail++]=n; pushUp(tail-1);
}

int main(void){
  int n; scanf("%d",&n);
  int t,x;
  FOR(i,0,n){
    scanf("%d",&t);
    if(t==1){
      scanf("%d",&x); insert(x);
    }else if(t==2){
      printf("%d\n",a[1]);
    }else{
      a[1]=a[--tail]; pushDown(1);
    }
  }

  return 0;
}

/*
#include<iostream>
#include<cstdio>
using namespace std;

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
}hp(1000020);


int main(void){
  int n; scanf("%d",&n);
  int type, x;
  for(int i=0;i<n;i++){
    scanf("%d",&type);
    if(type==1){
      scanf("%d",&x); hp.insert(x);
    }else if(type==2) printf("%d\n",hp.top());
    else hp.pop();
  }

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
*/
