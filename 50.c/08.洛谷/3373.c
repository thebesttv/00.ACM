/*
题目描述
如题，已知一个数列，你需要进行下面两种操作：
1.将某区间每一个数加上x
2.将某区间每一个数乘上x
3.求出某区间每一个数的和

输入输出格式
输入格式：
第一行包含三个整数N、M、P，分别表示该数列数字的个数、操作的总个数和模数。
第二行包含N个用空格分隔的整数，其中第i个数字表示数列第i项的初始值。
接下来M行每行包含3或4个整数，表示一个操作，具体如下：
操作1： 格式：1 x y k 含义：将区间[x,y]内每个数乘上k
操作2： 格式：2 x y k 含义：将区间[x,y]内每个数加上k
操作3： 格式：3 x y 含义：输出区间[x,y]内每个数的和对P取模所得的结果

输出格式：
输出包含若干行整数，即为所有操作3的结果。

输入输出样例
输入样例#1：
5 5 38
1 5 4 2 3
2 1 4 1
3 2 5
1 2 4 2
2 3 5 5
3 1 4

输出样例#1：
17
2

说明
时空限制：1000ms,128M
数据规模：
对于30%的数据：N<=8，M<=10
对于70%的数据：N<=1000，M<=10000
对于100%的数据：N<=100000，M<=100000
（数据已经过加强^_^）
*/

#include<iostream>
#include<cstdio>
using namespace std;

struct SegTree{
  long long n;
  long long addMark,mulMark;
}segTree[100020*4];
int n,m,p;
long long a[100020];

void build(int root, long long * array, int L, int R);
void pushDown(int root, int L, int R);
void add(int root, int cL, int cR, int uL, int uR, long long addVal);
void mul(int root, int cL, int cR, int uL, int uR, long long mulVal);
long long sum(int root, int cL, int cR, int qL, int qR);

int main(void){
  scanf("%d%d%d",&n,&m,&p);
  for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
  build(1,a,1,n);
  int type,l,r; long long k;
  for(int i=0;i<m;i++){
    scanf("%d%d%d",&type,&l,&r);
    if(type==1){
      scanf("%lld",&k); mul(1,1,n,l,r,k);
    }else if(type==2){
      scanf("%lld",&k); add(1,1,n,l,r,k);
    }else{
      printf("%lld\n",sum(1,1,n,l,r));
    }
  }

  return 0;
}

void build(int root, long long * array, int L, int R){
  segTree[root].addMark=0; segTree[root].mulMark=1;
  if(L==R) segTree[root].n=array[L];
  else{
    int M=L+(R-L)/2;
    build(root*2,array,L,M);
    build(root*2+1,array,M+1,R);
    segTree[root].n=segTree[root*2].n+segTree[root*2+1].n;
  }
}
void pushDown(int root, int L, int R){
  int leftchild=root*2,rightchild=root*2+1;
  int M=L+(R-L)/2;
  if(segTree[root].mulMark!=1){ //先乘后加
    //segTree[leftchild].mulMark = segTree[leftchild].mulMark*segTree[root].mulMark%p;
    //segTree[rightchild].mulMark = segTree[rightchild].mulMark*segTree[root].mulMark%p;
    segTree[leftchild].mulMark*=segTree[root].mulMark;
    segTree[rightchild].mulMark*=segTree[root].mulMark;
    segTree[leftchild].addMark*=segTree[root].mulMark;
    segTree[rightchild].addMark*=segTree[root].mulMark;
    segTree[leftchild].n = (segTree[leftchild].n*segTree[root].mulMark)%p;
    segTree[rightchild].n = (segTree[rightchild].n*segTree[root].mulMark)%p;
    segTree[root].mulMark=1;
  }
  if(segTree[root].addMark){
    //segTree[leftchild].addMark=(segTree[leftchild].addMark+segTree[root].addMark)%p;
    //segTree[rightchild].addMark=(segTree[rightchild].addMark+segTree[root].addMark)%p;
    segTree[leftchild].addMark+=segTree[root].addMark;
    segTree[rightchild].addMark+=segTree[root].addMark;
    segTree[leftchild].n+=segTree[root].addMark*(M-L+1);
    segTree[rightchild].n+=segTree[root].addMark*(R-M);
    segTree[leftchild].n%=p; segTree[rightchild].n%=p;
    segTree[root].addMark=0;
  }
}
void add(int root, int cL, int cR, int uL, int uR, long long addVal){
  if(uL>cR || uR<cL) return;
  if(uL<=cL && uR>=cR){
    segTree[root].addMark = segTree[root].addMark+addVal;
    segTree[root].n = (segTree[root].n+addVal*(cR-cL+1))%p;
    return;
  }
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  add(root*2,cL,M,uL,uR,addVal);
  add(root*2+1,M+1,cR,uL,uR,addVal);
  segTree[root].n = (segTree[root*2].n+segTree[root*2+1].n)%p;
}
void mul(int root, int cL, int cR, int uL, int uR, long long mulVal){
  if(uL>cR || uR<cL) return;
  if(uL<=cL && uR>=cR){
    segTree[root].mulMark = segTree[root].mulMark*mulVal%p;
    segTree[root].n = segTree[root].n*mulVal%p;
    return;
  }
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  mul(root*2,cL,M,uL,uR,mulVal);
  mul(root*2+1,M+1,cR,uL,uR,mulVal);
  segTree[root].n = (segTree[root*2].n+segTree[root*2+1].n)%p;
}
long long sum(int root, int cL, int cR, int qL, int qR){
  if(qL>cR || qR<cL) return 0;
  if(qL<=cL && qR>=cR) return segTree[root].n%p;
  pushDown(root,cL,cR);
  int M=cL+(cR-cL)/2;
  return (sum(root*2,cL,M,qL,qR)+sum(root*2+1,M+1,cR,qL,qR))%p;
}
