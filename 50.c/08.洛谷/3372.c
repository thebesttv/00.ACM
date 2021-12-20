/*
题目描述
如题，已知一个数列，你需要进行下面两种操作：
1.将某区间每一个数加上x
2.求出某区间每一个数的和

输入输出格式
输入格式：
第一行包含两个整数N、M，分别表示该数列数字的个数和操作的总个数。
第二行包含N个用空格分隔的整数，其中第i个数字表示数列第i项的初始值。

接下来M行每行包含3或4个整数，表示一个操作，具体如下：
操作1： 格式：1 x y k 含义：将区间[x,y]（从1开始）内每个数加上k
操作2： 格式：2 x y 含义：输出区间[x,y]（从1开始）内每个数的和

输出格式：
输出包含若干行整数，即为所有操作2的结果。

输入输出样例
输入样例#1：
5 5
1 5 4 2 3
2 2 4
1 2 3 2
2 3 4
1 1 5 1
2 1 4

输出样例#1：
11
8
20

说明
时空限制：1000ms,128M

数据规模：
对于30%的数据：N<=8，M<=10
对于70%的数据：N<=1000，M<=10000
对于100%的数据：N<=100000，M<=100000
（数据已经过加强^_^，保证在int64/long long数据范围内）
*/

#include<iostream>
#include<cstdio>
using namespace std;

struct SegTree{
  long long sum;
  long long addMark;
}segTree[100020*4]; //<b></b>
long long a[100020];
int maxRoot=0;

void build(int root, long long * array, int L, int R);
void pushDown(int root, int L, int R);
long long sum(int root, int cL, int cR, int qL, int qR);
void add(int root, int cL, int cR, int uL, int uR, long long addVal);
void debug_print(int n);

int main(void){
  int n,m; scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  build(1,a,1,n);
#ifdef DEBUG
  printf("  max root: %d\n",maxRoot);
#endif
  int type,l,r; long long k;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&type,&l,&r);
    if(type==1){
      scanf("%lld",&k);
      add(1,1,n,l,r,k);
    }else{
      printf("%lld\n",sum(1,1,n,l,r));
    }
  }
  return 0;
}

void build(int root, long long * array, int L, int R){
  segTree[root].addMark=0; maxRoot=(root>maxRoot ? root : maxRoot);
  if(L==R) segTree[root].sum=array[L];
  else{
    int M=L+(R-L)/2;
    build(root*2,a,L,M);
    build(root*2+1,a,M+1,R);
    segTree[root].sum = segTree[root*2].sum + segTree[root*2+1].sum;
  }
}
void pushDown(int root, int L, int R){
  if(segTree[root].addMark){
    int leftchild=root*2,rightchild=root*2+1;
    int M=L+(R-L)/2;
    if(leftchild<=maxRoot){
      segTree[leftchild].addMark+=segTree[root].addMark;
      segTree[leftchild].sum+=segTree[root].addMark*(M-L+1);
    }
    if(rightchild<=maxRoot){
      segTree[rightchild].addMark+=segTree[root].addMark;
      segTree[rightchild].sum+=segTree[root].addMark*(R-M);
    }
    segTree[root].addMark=0;
  }
}
long long sum(int root, int cL, int cR, int qL, int qR){
  if(qL>cR || qR<cL) return 0;
  if(qL<=cL && qR>=cR) return segTree[root].sum;
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  return sum(root*2,cL,M,qL,qR) + sum(root*2+1,M+1,cR,qL,qR);
}
void add(int root, int cL, int cR, int uL, int uR, long long addVal){
  if(uL>cR || uR<cL) return;
  if(uL<=cL && uR>=cR){
    segTree[root].addMark+=addVal;
    segTree[root].sum+=addVal*(cR-cL+1);
    return;
  }
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  add(root*2,cL,M,uL,uR,addVal);
  add(root*2+1,M+1,cR,uL,uR,addVal);
  segTree[root].sum=segTree[root*2].sum+segTree[root*2+1].sum;
}
void debug_print(int n){
  for(int i=1;i<=4*n;i++) if(segTree[i].sum) printf("  segTree[%d]:%lld\n",i,segTree[i].sum);
}
